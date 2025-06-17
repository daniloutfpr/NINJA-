#include "Obstaculo.h"
namespace Entidades {
	namespace Obstaculos {
		Obstaculo::Obstaculo( sf::Vector2f pos, sf::Vector2f tam,ID id):Entidade(pos,tam,id)
			
		{
			corpo->setPosition(pos);
			//inicializa();
		}
		Obstaculo::~Obstaculo(){}

		
	}
}