#include "Goblin.h"
namespace Entidades {
	namespace Personagens {
		
		Goblin::Goblin(sf::Vector2f pos, sf::Vector2f tam, ID id):Inimigo(pos,tam,id),ehForte(false) {
			this->setnum_vidas(1);
			carregaTexturas();
			set_nivelMaldade(rand()%10);

			if (this->get_nivelMaldade() > 5) {
				ehForte = true;
			}
		}
		Goblin::~Goblin() {

		}
		void Goblin::executar() {
			
		}

		void Goblin::atualizar(float dt) {
			atualizarSprite(dt);

			Jogador* jogadorProx = jogadorMaisProximo();
			if (jogadorProx) {

			}
		}

		void Goblin::atualizarSprite(float dt) {
			
		}

		void Goblin::carregaTexturas() {
			
		}
		
		void Goblin::atacar() {
			if (ehForte) {
				this->getDano() += get_nivelMaldade();
			}
		}

		void Goblin::colidir(Entidade* pEnt) {
			
		}
	}
}