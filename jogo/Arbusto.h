#pragma once
#include "Plataforma.h"

#define LENTIDAO 0.65f

namespace Gerenciadores {
	class GerenciadorDeColisoes;
}
namespace Entidades {
	namespace Obstaculos {
		class Arbusto : public Obstaculo
		{
		private:
			float lentidao;
		public:
			Arbusto(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f tam = sf::Vector2f(300, 120), ID id = ID::arbusto);
			~Arbusto();
			void obstaculizar(Entidades::Personagens::Personagem* pPersonagem);
			void executar();
			void colidir(Entidade* pEnt);
			const float getLentidao() const;
			void atualizarSprite(float dt);
			void carregaTexturas();
			void setLentidao(float lento);
		};
	}
}

