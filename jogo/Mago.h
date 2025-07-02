#pragma once
#include "Goblin.h"

namespace Gerenciadores {
	class GerenciadorDeColisoes;
}
namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Mago : public Inimigo {
			private:

				float poder;

			public:
				Mago(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(0.1f, 0.1f), ID id = ID::mago);
				~Mago();

				void atacar() ;
				void executar();
				void atualizar(float dt);
				void atualizarSprite(float dt);
				void carregaTexturas();
				void colidir(Entidade* pEnt);
			};
		}
	}
}

