#pragma once
#include "Personagem.h"

#define PLAYER_VELOCIDADE 500.0f
#define PLAYER_VIDA 100.0f
#define DANO_PLAYER 20.0f
namespace Gerenciadores {
	class ControleJogador;
}
namespace Gerenciadores {
	class GerenciadorDeColisoes;
}

namespace Entidades {
	namespace Obstaculos {
		class Fogueira;
	}
}
namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem
		{
		private:
			Gerenciadores::ControleJogador* pControle;
			bool Jogador1;
			float velocidade;
			Entidades::Obstaculos::Fogueira* pFog;
		public:
			Jogador(sf::Vector2f pos = sf::Vector2f(0.0f,0.0f), sf::Vector2f tam= sf::Vector2f(0.1f,0.1f),bool ehJogador1=true , ID id = ID::jogador);
			~Jogador();
			const bool getJogador1()const;
			void sofrerLentidao(float lent);
			//void sofrerDano(float dano);
			void mover(bool esquerda);
			void executar();
			void atualizar(float dt);
			void atualizarSprite(float dt);
			void carregaTexturas();
			void colidir(Entidade* pEnt );
			void verificaInimigosAlcance();
		};
	}
}
