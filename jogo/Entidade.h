#pragma once
#include "Animacao.h"
#define GRAVIDADE 500.0f

namespace Gerenciadores {
	class GerenciadorDeColisoes;
}
namespace Entidades {
	class Entidade :public Ente
	{
	protected:
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
		ElementosGraficos::Animacao* sprite;
		//Gerenciadores::GerenciadorDeColisoes* pColisao;
	public:
		Entidade(const sf::Vector2f pos, const sf::Vector2f tam,ID id=ID::vazio);
		virtual ~Entidade();
		void renderiza();
		void setPosicao(sf::Vector2f p);
		sf::Vector2f getPos()const;
		Math::CoordF getPosition() const;
		void setPos(Math::CoordF p);
		void setTamanho(sf::Vector2f t);
		sf::Vector2f getTamanho()const;
		//virtual void atualizar(float dt) = 0;
		virtual void executar() = 0;
	};
}
