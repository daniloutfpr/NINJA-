#pragma once
#include "GerenciadorDeColisoes.h"


namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			Math::CoordF vel;
			bool pular;
			 Gerenciadores::GerenciadorDeColisoes* pColisao;
			 int num_vidas;
			 bool movendo;
			 bool podeMover;
			 bool olhaEsquerda;

		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id=ID::vazio);
			~Personagem();
			//const sf::RectangleShape& getCorpo() const;
			//Math::CoordF getVel() const;
			void pulo();
			bool getPulo() const;
			void setPulo(const bool p);
			bool getPodeMover();
			void pararDeMover();
			void setVelX(float vx);
			void setVelY(float vy);
			virtual void mover(bool esquerda) = 0;
			virtual void executar() = 0 ;
			virtual void atualizar(float dt) = 0;
			//virtual void executar() = 0;

		};
	}
}

