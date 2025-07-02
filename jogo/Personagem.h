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
			 bool atacando;
			 bool movendo;
			 bool podeMover;
			 bool olhaEsquerda;
			 bool podeAtacar;
			 float tempoAtaque;
			 int dano;
			 bool vivo;
			 float cooldownAtaque;           
			 float timerAtaque;        
			 float timerCooldown;

		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id=ID::vazio);
			~Personagem();
			
			Math::CoordF getVel() const;
			void pulo();
			bool getPulo() const;
			void setPulo(const bool p);
			bool getPodeMover();
			void pararDeMover();
			void setnum_vidas(int vidas);
			int getnum_vidas();
			void setvivo(bool v);
			bool getVivo();
			int getDano();
			void setDano(int d);
			bool getAtacando();
			bool getPodeAtacar();
			virtual void atacar() = 0;
			void receberDano(float dano);
			void incrementarTimers(float dt);
			virtual void atualizarSprite(float dt) = 0;
			virtual void carregaTexturas() = 0;
			virtual void executar() = 0 ;
			virtual void atualizar(float dt) = 0;
			virtual void colidir(Entidade* pEnt ) = 0;
		};
	}
}

