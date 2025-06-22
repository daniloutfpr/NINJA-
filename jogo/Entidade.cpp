#include "Entidade.h"
#include "GerenciadorDeColisoes.h"

namespace Entidades {

	//Gerenciadores::GerenciadorDeColisoes* Entidade::pColisao = Gerenciadores::GerenciadorDeColisoes::getInstancia();
	Gerenciadores::GerenciadorDeColisoes* Entidade::pColisao = Gerenciadores::GerenciadorDeColisoes::getInstancia();
	Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam,ID id):Ente(id),posicao(pos),tamanho(tam),sprite(nullptr)
	{
		
		corpo->setOrigin(tam.x / 2.0f, tam.y / 2.0f);
		corpo->setPosition(posicao);
	}
	Entidade::~Entidade(){
		if (sprite) {
			delete sprite;
		}
	}

	void Entidade::renderiza() {
		pGrafico->renderizar(corpo);
	}

	sf::Vector2f Entidade::getPos()const{
		return posicao;
	}
	sf::Vector2f Entidade::getTamanho()const {
		return tamanho;
	}

	void Entidade::setPosicao(sf::Vector2f p) {
		this->posicao = p;

		if (corpo) {
			corpo->setPosition(this->posicao);
		}
	}

	void Entidade::setPos(Math::CoordF p) {
		posicao = sf::Vector2f(p.x, p.y);
	}

	void Entidade::setTamanho(sf::Vector2f t) {
		tamanho = t;
	}

	Math::CoordF Entidade::getPosition() const {
		if (corpo)
			return Math::CoordF(corpo->getPosition().x, corpo->getPosition().y);
		return Math::CoordF(0.f, 0.f); // fallback seguro

	}

}