#pragma once
#include "Jogador.h"

//namespace Gerenciadores {
	//class GerenciadorDeColisoes;
//}
namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Inimigo :public Personagem
			{
			protected:
				int nivel_maldade;
				Entidades::Personagens::Jogador* pJogador1;
				Entidades::Personagens::Jogador* pJogador2;

			public:
				Inimigo(sf::Vector2f pos, sf::Vector2f tam, ID id = ID::vazio);
				virtual ~Inimigo();

				void setJogadores(Jogador* jog1, Jogador* jog2);
				Jogador* jogadorMaisProximo();
				void set_nivelMaldade(int nv);
				int get_nivelMaldade();
				virtual void atualizar(float dt) = 0;
				virtual void colidir(Entidade* pEnt) = 0;
				virtual void atualizarSprite(float dt) = 0;
				virtual void carregaTexturas() = 0;
				virtual void executar() = 0;
				//virtual void atacar(Jogador* pAlvo) = 0;
			};
		}
	}
}

