#pragma once
#include "Personagem.h"


#define PLAYER_VELOCIDADE 500.0f
namespace Gerenciadores {
	class ControleJogador;
}
namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem
		{
		private:
			Gerenciadores::ControleJogador* pControle;
			bool Jogador1;
			float velocidade;
		public:
			Jogador(sf::Vector2f, sf::Vector2f tam, ID id = ID::jogador);
			~Jogador();
			const bool getJogador1()const;
			void mover(bool esquerda);
			void executar();
			void atualizar(float dt);
		};
	}
}
