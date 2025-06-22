#pragma once
#include "Inimigo.h"
namespace Entidades {
	namespace Obstaculos {
		class Obstaculo:public Entidade
		{
		private:
			//sf::RectangleShape *obstaculo1;
			//void inicializa();
			bool danoso;
		public:
			Obstaculo(sf::Vector2f pos,sf::Vector2f tam,ID id = ID::vazio);
			virtual ~Obstaculo();
			//sf::RectangleShape* getObs();
			virtual void obstaculizar() = 0;
			virtual void executar() = 0;
			virtual void colidir(Entidade* pEnt ) = 0;
		};
	}
}
