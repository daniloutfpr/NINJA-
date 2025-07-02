#include "Entidade.h"
#include "GerenciadorDeColisoes.h"

namespace Entidades {

	//Gerenciadores::GerenciadorDeColisoes* Entidade::pColisao = Gerenciadores::GerenciadorDeColisoes::getInstancia();
	Gerenciadores::GerenciadorDeColisoes* Entidade::pColisao = Gerenciadores::GerenciadorDeColisoes::getInstancia();
	Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam,ID id):Ente(id),posicao(pos),tamanho(tam),sprite(nullptr),noChao(true)
	{
		//if (pGrafico && corpo) {
			//pGrafico->renderizar(corpo);
		//}
		//corpo->setSize(tamanho);
		corpo->setOrigin(tamanho.x / 2.0f, tamanho.y / 2.0f);
		corpo->setPosition(posicao);
		
	}
		

	Entidade::~Entidade(){
		if (sprite) {
			delete sprite;
		}
	}
	void Entidade::setVelX(float vx) {
		vel.x = vx;
	}

	void Entidade::setVelY(float vy) {
		vel.y = vy;
	}

	Math::CoordF Entidade::getVel() const {
		return vel;
	}

	void Entidade::mover() {
		if (!getNoChao()) {
			cair();
		}
		Math::CoordF deslocamento = vel * pGrafico->getDeltaTempo();
		sf::Vector2f nPos = getPos() + sf::Vector2f(deslocamento.x, deslocamento.y);
		setPosicao(nPos);
	}

	void Entidade::cair() {
		setVelY(getVel().y + GRAVIDADE * pGrafico->getDeltaTempo());
		if (getID() == ID::plataforma) {
			setVelY(getVel().y + EMPUXO * pGrafico->getDeltaTempo());
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

	void Entidade::setNoChao(const bool c) {
		noChao = c;
	}

	bool Entidade::getNoChao() {
		return noChao;
	}

	Math::CoordF Entidade::getPosition() const {
		if (corpo)
			return Math::CoordF(corpo->getPosition().x, corpo->getPosition().y);
		return Math::CoordF(0.f, 0.f); // fallback seguro

	}

}