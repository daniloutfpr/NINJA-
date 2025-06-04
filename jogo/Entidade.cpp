#include "Entidade.h"

namespace Entidades {
	Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam):posicao(pos),tamanho(tam)
	{}
	Entidade::~Entidade(){}

	sf::Vector2f Entidade::getPos()const{
		return posicao;
	}
	sf::Vector2f Entidade::getTamanho()const {
		return tamanho;
	}

	void Entidade::setPosicao(sf::Vector2f p) {
		posicao = p;
	}
	void Entidade::setTamanho(sf::Vector2f t) {
		tamanho = t;
	}
}