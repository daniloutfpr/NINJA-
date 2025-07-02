#pragma once
#define DANO_FOGUEIRA 1.0f
#define FOGO_INTERVALO 0.5F
#include "Arbusto.h"

namespace Gerenciadores {
	class GerenciadorDeColisoes;
}
namespace Entidades {
	namespace Obstaculos {
		class Fogueira :public Obstaculo
		{
		private:
			float danoPs;
			int intervalo_fogo;
		public:
			Fogueira(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(1, 1), ID id = ID::fogueira);
			~Fogueira();
			void obstaculizar(Entidades::Personagens::Personagem* pPersonagem);
			void executar();
			void colidir(Entidade* pEnt);
			const int getDanoPs() ;
			void atualizarSprite(float dt);
			void carregaTexturas();
			//void setDanoPs(float dps);
		};
	}
}
