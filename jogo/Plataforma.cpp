#include "Plataforma.h"

namespace Entidades {
	namespace Obstaculos {

		Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, ID id)
			: Obstaculo(pos, tam, id), empuxo() {
			//std::cout << "construto da plataforma!" << endl;
			corpo = new sf::RectangleShape(tam);
			inicializa();
			corpo->setPosition(pos);
			
		}

		Plataforma::~Plataforma() {
			
		}
		void Plataforma::inicializa() {
			corpo->setFillColor(sf::Color::Blue);
		}

		void Plataforma::obstaculizar() {

		}

		void Plataforma::executar() {
			obstaculizar();
		}
	}
}


