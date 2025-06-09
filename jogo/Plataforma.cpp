#include "Plataforma.h"

namespace Entidades {
	namespace Obstaculos {

		Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, ID id)
			: Obstaculo(pos, tam, id), empuxo() {
			
		}

		Plataforma::~Plataforma() {
			
		}

		void Plataforma::obstaculizar() {
			
		}

		void Plataforma::executar() {
			obstaculizar();
		}
	}
}


