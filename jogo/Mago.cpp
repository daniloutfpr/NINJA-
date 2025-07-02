#include "Mago.h"
#include "GerenciadorDeColisoes.h"
#define MAGO_VELOCIDADE 50.0f
#define MAGO_ALCANCE_CANALIZACAO 250.0f // Alcance para come�ar a atacar

namespace Entidades {
	namespace Personagens {
		namespace Inimigos
		{

			Mago::Mago(sf::Vector2f pos, sf::Vector2f tam, ID id) :
				Inimigo(pos, tam, id),
				poder(1.0f)       
				
				
			{
				setnum_vidas(40);
				setDano(5); 
				carregaTexturas();
			}

			Mago::~Mago() {}

			void Mago::executar() {
				atualizar(pGrafico->getDeltaTempo());
				renderiza();
			}

			void Mago::atualizar(float dt) {
				// Reseta os estados no in�cio de cada frame
				movendo = false;
				atacando = false;
				setVelX(0.f);

				Jogador* pJogador = jogadorMaisProximo();

				if (pJogador) {
					float dist = std::abs(pJogador->getPos().x - getPos().x);
					float distVertical = std::abs(pJogador->getPos().y - getPos().y);

					
					if (dist < MAGO_ALCANCE_CANALIZACAO && distVertical < 60.f) {
						
						atacando = true;

						// 1. AUMENTA O PODER COM O TEMPO
						poder += 0.25f * dt; 

						
						float intervaloDano = 0.25 ;
						float timerDano = 0.0;
						timerDano += dt;
						if (timerDano >= intervaloDano) {
							atacar(); // Chama o ataque para aplicar o dano
							timerDano = 0.f; // Reseta o timer do "tique" de dano
						}
					}
					
					else {
						if (dist > 0) { // Jogador � direita
							setVelX(-MAGO_VELOCIDADE);
							olhaEsquerda = false;
						}
						else { // Jogador � esquerda
							setVelX(MAGO_VELOCIDADE);
							olhaEsquerda = true;
						}
						movendo = true;
					}
					poder = 1.0f;
				}
				
				vel.y += GRAVIDADE * dt;
				posicao.x += vel.x * dt;
				posicao.y += vel.y * dt;
				setPosicao(posicao);

				if (pColisao) {
					pColisao->notificar(this);
				}
				
				
				atualizarSprite(dt);
			}

			void Mago::atacar() {
				// Este m�todo agora s� calcula e aplica o dano do "tique" atual.
				float danoFinal = getDano() * poder;

				Jogador* pAlvo = jogadorMaisProximo();
				
			}

			void Mago::colidir(Entidade* outraEntidade) {
				if (outraEntidade->getID() == ID::jogador) {
					static_cast<Jogador*>(outraEntidade)->receberDano(getDano());
				}
			}

			void Mago::carregaTexturas() {
				
				sprite = new ElementosGraficos::Animacao(corpo, Math::CoordF(0.15f, 0.15f));

				sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::idle, "wizard_idle.png", 4);

				sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::atacando, "wizard_attack.png", 4);

			}
			void Mago::atualizarSprite(float dt) {
				
				if (atacando) {
					sprite->atualizar(ElementosGraficos::ID_Animacao::atacando, !olhaEsquerda, Math::CoordF(posicao.x, posicao.y), dt);
				}
				else {
					sprite->atualizar(ElementosGraficos::ID_Animacao::idle, !olhaEsquerda, Math::CoordF(posicao.x, posicao.y), dt);
				}
			}
		}
	}
}