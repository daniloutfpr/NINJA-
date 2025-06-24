#pragma once
#include "Obstaculo.h"
#define EMPUXO 10.0f
namespace Gerenciadores {
	class GerenciadorDeColisoes;
}
namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		private:
			sf::Vector2f empuxo;
			void inicializa();
		public:
			Plataforma(sf::Vector2f pos, sf::Vector2f tam, ID id = ID::plataforma);
			~Plataforma();
			void obstaculizar(Entidades::Personagens::Personagem* pPersonagem);
			void executar();
			void colidir(Entidade* pEnt );
			void atualizarSprite(float dt);
			void carregaTexturas();
		};
	}
}