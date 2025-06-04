#pragma once
#include "GerenciadorGrafico.h"
namespace Entidades {
	namespace Obstaculos {
		class Obstaculo:public Entidade
		{
		private:
			sf::RectangleShape obstaculo1;
			void inicializa();
		public:
			Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam);
			~Obstaculo();
			const sf::RectangleShape& getObs();

			virtual void obstaculizar() = 0;
		};
	}
}
