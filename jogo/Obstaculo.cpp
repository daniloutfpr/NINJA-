#include "Obstaculo.h"
namespace Entidades {
	namespace Obstaculos {
		Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam):Entidade(pos,tam),
			obstaculo1(sf::RectangleShape(tam))
		{
			obstaculo1.setPosition(pos);
			inicializa();
		}
		Obstaculo::~Obstaculo(){}
		const sf::RectangleShape& Obstaculo:: getObs()  {
			return obstaculo1;
		}

		void Obstaculo:: inicializa() {
			obstaculo1.setFillColor(sf::Color::Blue);
		}
	}
}