#pragma once
#include "Coord.h"
namespace Entidades {
	class Entidade
	{
	private:
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
		sf::RectangleShape corpo;
	public:
		Entidade(const sf::Vector2f pos, const sf::Vector2f tam);
		virtual ~Entidade();
		void setPosicao(sf::Vector2f p);
		sf::Vector2f getPos()const;
		void setTamanho(sf::Vector2f t);
		sf::Vector2f getTamanho()const;
	};
}
