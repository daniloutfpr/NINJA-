#include "Fogueira.h"
#include "GerenciadorDeColisoes.h"
namespace Entidades {
	namespace Obstaculos {
		Fogueira::Fogueira(sf::Vector2f pos, sf::Vector2f tam, ID id) :danoPs(DANO_FOGUEIRA),intervalo_fogo(FOGO_INTERVALO),
			Obstaculo(pos, tam, id) {
			carregaTexturas();
		}

		Fogueira::~Fogueira() {

		}

		void Fogueira::executar() {
			atualizarSprite(pGrafico->getDeltaTempo());
			corpo->setPosition(posicao.x, posicao.y);
			pColisao->notificar(this);
			//mover();
			renderiza();
		}

		const int Fogueira::getDanoPs() {
			intervalo_fogo += pGrafico->getDeltaTempo();
			if (intervalo_fogo >= FOGO_INTERVALO) {
				intervalo_fogo = 0;
				return danoPs;
			}


		}

		void Fogueira::obstaculizar(Entidades::Personagens::Personagem* pPersonagem) {
			if (pPersonagem->getID() == ID::jogador) {
				dynamic_cast<Entidades::Personagens::Jogador*>(pPersonagem)->receberDano(getDanoPs());
			}
		}
		
		void Fogueira::colidir(Entidade* pEnt) {
			obstaculizar(dynamic_cast<Entidades::Personagens::Personagem*>(pEnt));
		}

		void Fogueira::carregaTexturas() {
			sprite = new ElementosGraficos::Animacao(corpo, Math::CoordF(1.0,0.8));

			sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::fogueira, "fogueira.png", 12);
		}

		void Fogueira::atualizarSprite(float dt) {
			sprite->atualizar(ElementosGraficos::ID_Animacao::fogueira, false, Math::CoordF(posicao.x, posicao.y), dt);
		}
	}
}