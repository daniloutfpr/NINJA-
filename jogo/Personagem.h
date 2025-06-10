#pragma once
#include "ListaDeEntidades.h"
namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			Math::CoordF vel;
			bool pular;
		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id=ID::vazio);
			~Personagem();
			//const sf::RectangleShape& getCorpo() const;
			//Math::CoordF getVel() const;
			void pulo();
			bool getPulo() const;
			void setPulo(const bool p);
			void setVelX(Math::CoordF v);
			void setVelY(Math::CoordF v);
			virtual void mover() = 0;
			virtual void executar() = 0 ;

		};
	}
}

