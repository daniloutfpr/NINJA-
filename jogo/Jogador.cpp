	#include "Jogador.h"	
	#include "ControleJogador.h"
	#include"GerenciadorDeColisoes.h"
	#include "Fogueira.h"
	#include "Fase.h"
namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(sf::Vector2f pos,  sf::Vector2f tam,bool ehJogador1,ID id) :Personagem(pos, tam,id),velocidade(PLAYER_VELOCIDADE)
		{
			vel = Math::CoordF(0.0f, 0.0f);
			Jogador1 = true;
			//corpo = new sf::RectangleShape(tam);
			//corpo->setFillColor(sf::Color::Red);
		
			//corpo->setPosition(pos);
			pControle = new Gerenciadores::ControleJogador(this);
			pFog = new Entidades::Obstaculos::Fogueira((sf::Vector2f(0, 0), (sf::Vector2f(0, 0))));
			estaLento = false;
			carregaTexturas();
			setnum_vidas(PLAYER_VIDA);
		}

		Jogador::~Jogador() {
			if (pControle) {
				pControle = nullptr;
				delete pControle;
			}
		}

		const bool Jogador::getJogador1() const {
			return Jogador1;
		}
		
		void Jogador::mover(bool esquerda) {
			if (podeMover) {
				movendo = true;
				//std::cout << "Jogador::mover chamado! Esquerda: " << esquerda << std::endl;
				if (esquerda) {
					olhaEsquerda = true;
				}
				else
					olhaEsquerda = false;
			}
			static_cast<Entidade*>(this)->mover();
		}
	

		void Jogador::atualizar(float dt) {

			//vel = Math::CoordF(0.1f, 0.1f);
			incrementarTimers(dt);
			if (!atacando) {
				if (movendo) {
					if (olhaEsquerda) {
						setVelX(-velocidade);
					}
					else {
						setVelX(velocidade);
					}
				}
				else
				{
					setVelX(0.0);
				}
			}
			else
				setVelX(0.0);//para de andar ao atacar

			if (atacando) {
				
				if (timerAtaque > 0.1f) { 
					verificaInimigosAlcance();
				}
			}
			if (estaLento) {
				setVelX(velocidade * 0.1);
			}
			
			vel.y += GRAVIDADE * dt;
			posicao.x += vel.x * dt;
			posicao.y += vel.y * dt;	
			atualizarSprite(dt);
			setPosicao(posicao);
			if (pColisao) {
				//std::cout << "Jogador na pos Y: " << posicao.y << " -- Enviando notificacao..." << std::endl;
				pColisao->notificar(this);
			}
			
			//std::cout << "Jogador hp:" << getnum_vidas() << std::endl;
		

		}

		void Jogador::executar() {
			
			atualizar(pGrafico->getDeltaTempo());
			
		}

		void Jogador::carregaTexturas() {
			sprite = new ElementosGraficos::Animacao(corpo, Math::CoordF(0.1, 0.06));


			if (Jogador1) {
				sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::idle, "ninja_idle.png", 12);

				sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::atacando, "ninja_attack.png", 12);
			}
			else {
				sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::idle, "player2_idle.png", 12);
				sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::atacando, "player2_attack.png", 12);
			}
			
			

		}

		void Jogador::atualizarSprite(float dt) {
			sprite->atualizar(ElementosGraficos::ID_Animacao::idle, !olhaEsquerda, Math::CoordF(posicao.x,posicao.y), dt);

			if (atacando) {
				sprite->atualizar(ElementosGraficos::ID_Animacao::atacando, olhaEsquerda, Math::CoordF(posicao.x, posicao.y), dt);
			}
		}

		void Jogador::colidir(Entidade* pEnt) {
			if (pEnt->getID() == ID::goblin || pEnt->getID() == ID::mago) {
				receberDano(dynamic_cast<Entidades::Personagens::Inimigos::Inimigo*>(pEnt)->getDano());
			}
			else if (pEnt->getID() == ID::arbusto) {
				sofrerLentidao();
			}
			else if (pEnt->getID() == ID::fogueira) {
				receberDano(pFog->getDanoPs());
			}

		}

		void Jogador::sofrerLentidao() {
			estaLento = true;
		}

		void Jogador::verificaInimigosAlcance() {
				// Supondo que você tenha um pFase no seu Jogador
				if (!pFase) return;
				Lista::ListaDeEntidades* lista = pFase->getListaEntidades();

				for (auto it = lista->begin(); it != lista->end(); ++it) {
					if (auto* inimigo = dynamic_cast<Inimigos::Inimigo*>(*it)) {
						if (inimigo->getVivo()) {
							float jogadorX = getPos().x;
							float jogadorY = getPos().y;
							float inimigoX = inimigo->getPos().x;
							float inimigoY = inimigo->getPos().y;

							// Define a área de ataque
							float alcanceX = 60.f;
							float alcanceY = 50.f;

							bool naAltura = fabs(jogadorY - inimigoY) <= alcanceY;

							if (!olhaEsquerda) { // Olhando para a direita
								bool naDistancia = (inimigoX > jogadorX) && (inimigoX - jogadorX < alcanceX);
								if (naAltura && naDistancia) {
									inimigo->receberDano(getDano());
								}
							}
							else { // Olhando para a esquerda
								bool naDistancia = (inimigoX < jogadorX) && (jogadorX - inimigoX < alcanceX);
								if (naAltura && naDistancia) {
									inimigo->receberDano(getDano());
								}
							}
						}
					}
				}
			}
		

		void Jogador::atacar() {
			if (getPodeAtacar()) {
				atacando = true;
			}
		}
		
	}
}