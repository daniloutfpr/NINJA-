#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam) 
			:Entidade(pos,tam),corpo(sf::RectangleShape(tam))
		{
			corpo.setPosition(pos);
		}
		Personagem::~Personagem(){}
		
		const sf::RectangleShape& Personagem::getCorpo() const {
			return corpo;
		}
	}
}