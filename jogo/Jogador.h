#pragma once
#include "Personagem.h"
namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem
		{
		private:
			void inicializa();
		public:
			Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
			~Jogador();
			//const sf::Vector2f getPosition() const;
			void executar();
		};
	}
}
