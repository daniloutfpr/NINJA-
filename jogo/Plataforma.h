#pragma once
#include "Obstaculo.h"
namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		private:
			sf::Vector2f empuxo;
			void inicializa();
		public:
			Plataforma(sf::Vector2f pos, sf::Vector2f tam, ID id = ID::plataforma);
			~Plataforma();
			void obstaculizar();
			void executar();
			void colidir(Entidade* pEnt );
		};
	}
}