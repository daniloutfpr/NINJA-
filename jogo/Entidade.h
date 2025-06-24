#pragma once
#include "Animacao.h"
#define GRAVIDADE 500.0f
#define EMPUXO 500.0f

namespace Gerenciadores {
	class GerenciadorDeColisoes;
}
namespace Entidades {

	
	class Entidade :public Ente
	{
	protected:
		Math::CoordF vel;
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
		ElementosGraficos::Animacao* sprite;
		static Gerenciadores::GerenciadorDeColisoes* pColisao;
		bool noChao;
	public:
		Entidade(const sf::Vector2f pos, const sf::Vector2f tam,ID id=ID::vazio);
		virtual ~Entidade();
		void renderiza();
		void setPosicao(sf::Vector2f p);
		sf::Vector2f getPos()const;
		Math::CoordF getPosition() const;
		Math::CoordF getVel() const;
		void setPos(Math::CoordF p);
		bool getNoChao();
		void mover();
		void setVelX(float vx);
		void setVelY(float vy);
		void cair();
		virtual void atualizarSprite(float dt) = 0;
		virtual void carregaTexturas() = 0;
		void setTamanho(sf::Vector2f t);
		void setNoChao(const bool c);
		sf::Vector2f getTamanho()const;
		virtual void colidir(Entidade* pEnt  ) = 0;
		//virtual void atualizar(float dt) = 0;
		virtual void executar() = 0;
	};
}
