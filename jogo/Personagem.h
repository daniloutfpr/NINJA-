#pragma once
#include "Entidade.h"
namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			sf::RectangleShape corpo;
			Math::CoordF vel;
		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
			~Personagem();
			const sf::RectangleShape& getCorpo() const;
			virtual void executar() = 0;

		};
	}
}

