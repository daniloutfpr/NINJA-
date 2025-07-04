#pragma once
#include "Fogueira.h"

#define GOBLIN_VELOCIDADE 350.0f
#define GOBLIN_ALCANCE_VISAO 300.0f

namespace Gerenciadores {
	class GerenciadorDeColisoes;
}
namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Goblin :public Inimigo
			{
			private:
				bool ehForte;
			public:
				Goblin(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(0.1f, 0.1f), ID id = ID::goblin);
				~Goblin();
				void atacar();
				void executar();
				void atualizar(float dt);
				void atualizarSprite(float dt);
				void carregaTexturas();
				void colidir(Entidade* pEnt);

			};
		}
	}
}

