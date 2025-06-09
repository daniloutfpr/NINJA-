#pragma once
#include "Jogador.h"
namespace Entidades {
	namespace Personagens {
		class Inimigo :public Personagem
		{
		private:
			
			Entidades::Personagens::Jogador* jogador;
			void inicializa();
		public:
			Inimigo(sf::Vector2f pos, sf::Vector2f tam,Entidades::Personagens::Jogador* j,ID id=ID::inimigo);
			~Inimigo();
			void mover();
			void executar();
		};
	}
}

