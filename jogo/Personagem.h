#pragma once
#include "Entidade.h"
namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			Math::CoordF vel;
		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id=ID::vazio);
			~Personagem();
			//const sf::RectangleShape& getCorpo() const;
			virtual void mover() = 0;
			virtual void executar() = 0 ;

		};
	}
}

