#pragma once
#include "Personagem.h"
namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem
		{
		private:
			void inicializa();
		public:
			Jogador(sf::Vector2f pos, sf::Vector2f tam, ID id = ID::jogador);
			~Jogador();
			void mover();
			void executar();
		};
	}
}
