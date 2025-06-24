#include "Arbusto.h"
#include "GerenciadorDeColisoes.h"

namespace Entidades {
	namespace Obstaculos {
		Arbusto::Arbusto(sf::Vector2f pos, sf::Vector2f tam, ID id) :lentidao(LENTIDAO),Obstaculo(pos,tam,id) {
			carregaTexturas();
		}

		Arbusto::~Arbusto() {

		}

		const float Arbusto::getLentidao()const {
			return lentidao;
		}

		void Arbusto::setLentidao(float lento) {
			lentidao = lento;
		}

		void Arbusto::executar() {
			atualizarSprite(pGrafico->getDeltaTempo());
			corpo->setPosition(posicao.x, posicao.y);
			pColisao->notificar(this);
			renderiza();
			mover();
		}

		void Arbusto::colidir(Entidade* pE) {
			obstaculizar(dynamic_cast<Entidades::Personagens::Personagem*>(pE));
		}

		void Arbusto::obstaculizar(Entidades::Personagens::Personagem* pPersonagem) {
			if (pPersonagem->getID() == ID::jogador) {
				dynamic_cast<Entidades::Personagens::Jogador*>(pPersonagem)->sofrerLentidao(lentidao);
			}
		}

		void Arbusto::carregaTexturas() {
			sprite = new ElementosGraficos::Animacao(corpo,Math::CoordF(2.2, 2.2));

			sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::arbusto, "arbusto.png", 1);
		}

		void Arbusto::atualizarSprite(float dt) {
			sprite->atualizar(ElementosGraficos::ID_Animacao::arbusto,false, Math::CoordF(posicao.x, posicao.y), dt);
		}
	}
}
