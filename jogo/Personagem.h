#pragma once
#include "ListaDeEntidades.h"


namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			bool pular;
			 //Gerenciadores::GerenciadorDeColisoes* pColisao;
			 int num_vidas;
			 bool movendo;
			 bool podeMover;
			 bool olhaEsquerda;
			 int dano;
			 bool vivo;

		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id=ID::vazio);
			~Personagem();
			//const sf::RectangleShape& getCorpo() const;
			Math::CoordF getVel() const;
			void pulo();
			bool getPulo() const;
			void setPulo(const bool p);
			bool getPodeMover();
			void pararDeMover();
			void setnum_vidas(int vidas);
			int getnum_vidas();
			void setvivo(bool v);
			int getDano();
			virtual void receberDano(float dano);
			virtual void atualizarSprite(float dt) = 0;
			virtual void carregaTexturas() = 0;
			virtual void mover(bool esquerda) = 0;
			virtual void executar() = 0 ;
			virtual void atualizar(float dt) = 0;
			virtual void colidir(Entidade* pEnt ) = 0;
			//virtual void executar() = 0;

		};
	}
}

