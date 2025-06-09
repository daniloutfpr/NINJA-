#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id) 
			:Entidade(pos,tam,id)
		{
			//corpo.setPosition(pos);
		}
		Personagem::~Personagem(){}
		
		//const sf::RectangleShape& Personagem::getCorpo() const {
			//return corpo;
		//}
	}
}