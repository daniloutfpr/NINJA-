#include "Plataforma.h"
#include "GerenciadorDeColisoes.h"
namespace Entidades {
	namespace Obstaculos {

		Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, ID id)
			: Obstaculo(pos, tam, id), empuxo(0.0f,0.0f) {
			//std::cout << "construto da plataforma!" << endl;
			//corpo = new sf::RectangleShape(tam);
		
			//corpo->setPosition(pos);
			
		}

		Plataforma::~Plataforma() {

		}

		void Plataforma::obstaculizar(Entidades::Personagens::Personagem* pPersonagem) {
			if (pPersonagem == nullptr) {
				std::cout << "Ponteiro(Entidade) nulo obstaculizar plataforma!" << std::endl  ;
			}
			if (pColisao == nullptr) {
				std::cout << "Ponteiro(Colisao) nulo obstaculizaar plataforma!" << std::endl;
			}

			sf::Vector2f novaPos = pPersonagem->getPos();
			sf::Vector2f ds = pColisao->calcOverlap(dynamic_cast<Entidades::Entidade*>(pPersonagem), this);

			if (ds.x < ds.y) {                          // Eixo da colisão
				if (pPersonagem->getPos().x < this->getPos().x)  // Direção da colisao
					novaPos.x -= ds.x;                      // Colisão Esquerda => Direita
				else
					novaPos.x += ds.x;  // Colisao Direita => Esquerda
				pPersonagem->setVelX(0.f);
			}
			else {                            // Eixo da colisão
				if (pPersonagem->getPos().y < this->getPos().y) {  // Direção da colisão
					novaPos.y -= ds.y;                        // Caindo
					pPersonagem->setNoChao(true);
					pPersonagem->setPulo(true);
				}
				else
					novaPos.y += ds.y;
				
				pPersonagem->setVelY(0.f);
				
			}
			
			pPersonagem->setPosicao(novaPos);
		}

		void Plataforma::executar() {
			pColisao->notificar(this);
			//mover();
			renderiza();
		}

		void Plataforma::colidir(Entidade* pEnt) {
			if (pEnt == nullptr) {
				std::cout << "Ponteiro nulo na colidir da plataforma!" << std::endl;
			}
			else
				obstaculizar(dynamic_cast<Entidades::Personagens::Personagem*>(pEnt));
			
		}

		void Plataforma::carregaTexturas() {

		}

		void Plataforma::atualizarSprite(float dt) {

		}
	}
}


