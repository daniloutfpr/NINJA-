#pragma once
#include "Ente.h"
namespace Entidades {
	class Entidade :public Ente
	{
	private:
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
	public:
		Entidade(const sf::Vector2f pos, const sf::Vector2f tam,ID id=ID::vazio);
		virtual ~Entidade();
		void renderiza();
		void setPosicao(sf::Vector2f p);
		sf::Vector2f getPos()const;
		void setTamanho(sf::Vector2f t);
		sf::Vector2f getTamanho()const;
		virtual void executar() = 0;
	};
}
