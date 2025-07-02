#include "Goblin.h"
#include"GerenciadorDeColisoes.h"
#define GOBLIN_VELOCIDADE 80.0f
#define GOBLIN_ALCANCE_VISAO 400.0f
#define GOBLIN_ALCANCE_ATAQUE 40.0f
namespace Entidades {
	namespace Personagens {
		namespace Inimigos {

			Goblin::Goblin(sf::Vector2f pos, sf::Vector2f tam, ID id) : Inimigo(pos, tam, id), ehForte(false) {
				setnum_vidas(1);
				set_nivelMaldade(rand() % 10);
				if (nivel_maldade > 5) {
					ehForte = true;
				}
				if (ehForte) {
					setDano(5);
					setnum_vidas(11);
				}

				carregaTexturas();
			}

			Goblin::~Goblin() {}

			void Goblin::executar() {
				
				atualizar(pGrafico->getDeltaTempo());
				renderiza();
			}

			void Goblin::atualizar(float dt) {

				movendo = false;
				atacando = false;
				setVelX(0.f);

				Jogador* pJogador = jogadorMaisProximo();
				if (pJogador) {
					float distHorizontal = pJogador->getPos().x - getPos().x;
					float distVertical = std::abs(pJogador->getPos().y - getPos().y);

					// Só reage se o jogador estiver no alcance de visão e na mesma altura
					if (std::abs(distHorizontal) < GOBLIN_ALCANCE_VISAO && distVertical < 60.f) {

						// Se estiver MUITO perto, para e ataca (o dano é na colisão)
						if (std::abs(distHorizontal) < GOBLIN_ALCANCE_ATAQUE) {
							atacar();
						}
						// Se não, persegue
						else {
							if (distHorizontal > 0) { setVelX(GOBLIN_VELOCIDADE); olhaEsquerda = false; }
							else { setVelX(-GOBLIN_VELOCIDADE); olhaEsquerda = true; }
							movendo = true;
						}
					}
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

			void Goblin::atacar() {

				atacando = true;
			}

			void Goblin::colidir(Entidade* outraEntidade) {

				// Lógica específica do Goblin: causar dano por toque no jogador
				if (outraEntidade->getID() == ID::jogador) {
					static_cast<Jogador*>(outraEntidade)->receberDano(getDano());
				}
			}

			void Goblin::carregaTexturas() {
				//if (corpo) corpo->setSize(tamanho);
				
				sprite = new ElementosGraficos::Animacao(corpo, Math::CoordF(0.3f, 0.3f));

				sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::idle, "goblin_idle.png", 6);

				sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::atacando, "goblin_attack.png", 6);
			}

			void Goblin::atualizarSprite(float dt) {
				if (sprite) {
					if (atacando) {
						sprite->atualizar(ElementosGraficos::ID_Animacao::atacando, !olhaEsquerda, Math::CoordF(posicao.x, posicao.y), dt);
					}
					else
						sprite->atualizar(ElementosGraficos::ID_Animacao::idle, !olhaEsquerda, Math::CoordF(posicao.x, posicao.y), dt);

				}
			}
		}
	}
}