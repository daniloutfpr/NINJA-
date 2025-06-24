#pragma once
#include "Arbusto.h"
namespace Entidades {
	namespace Personagens {
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

