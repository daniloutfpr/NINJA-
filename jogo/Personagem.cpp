#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id) 
			:Entidade(pos,tam,id)
		{
			//corpo.setPosition(pos);
		}
		Personagem::~Personagem(){}

		void Personagem::setVelX(Math::CoordF v) {
			vel.x = v.x;
		}
		
		void Personagem::setVelY(Math::CoordF v) {
			vel.y = v.y;
		}

		bool Personagem::getPulo() const {
			return pular;
		}

		void Personagem::setPulo(const bool p) {
			pular = p;
		}

		void Personagem::pulo() {
			if (pular) {
				pular = false;
				vel.y -= 500.0f;
			}
		}
		//const sf::RectangleShape& Personagem::getCorpo() const {
			//return corpo;
		//}
	}
}