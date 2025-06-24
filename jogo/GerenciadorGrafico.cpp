#include "GerenciadorGrafico.h"

namespace Gerenciadores {
	GerenciadorGrafico* GerenciadorGrafico::pGrafico=nullptr;
	float GerenciadorGrafico::dt(0);

	GerenciadorGrafico::GerenciadorGrafico() :
		camera(sf::Vector2f(LARGURA_JANELA / 2, ALTURA_JANELA / 2), sf::Vector2f(LARGURA_JANELA, ALTURA_JANELA)) {
		pJanela = new sf::RenderWindow(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Ninja++");
		pJanela->setView(camera);
		relogio.restart();
		dt = relogio.getElapsedTime().asSeconds();
	}

	GerenciadorGrafico::~GerenciadorGrafico() {
		//if (pJanela) {
			//delete pJanela;
		//}
	}

	GerenciadorGrafico* GerenciadorGrafico::getInstancia() {
		if (pGrafico == nullptr) {
			pGrafico = new GerenciadorGrafico();
		}
		return pGrafico;
	}

	void GerenciadorGrafico::renderizar( sf::RectangleShape* corpo) {
		pJanela->draw(*corpo);
	}

	void GerenciadorGrafico::display() {
		if (janelaAberta()) {
			pJanela->display();
		}
	}

	bool GerenciadorGrafico::janelaAberta() const {
		return (pJanela->isOpen());
	}

	void GerenciadorGrafico::limpar() {
		if (janelaAberta()) {
			pJanela->clear();
		}
	}

	void GerenciadorGrafico::fecharJanela() {
		pJanela->close();
	}

	void GerenciadorGrafico::centralizarCam(Math::CoordF pos) {
		camera.setCenter(sf::Vector2f(pos.x, pos.y));
		pJanela->setView(camera);
	}

	void GerenciadorGrafico::atualizaDeltaTempo() {
		dt = relogio.getElapsedTime().asSeconds();
		relogio.restart();

	}

	const float GerenciadorGrafico::getDeltaTempo()const {
		return dt;
	}

	bool GerenciadorGrafico::evGraficos(sf::Event &e) {
		return pJanela->pollEvent(e);
	}

	Math::CoordUI GerenciadorGrafico::getTamJanela() const {
		sf::Vector2u size = pJanela->getSize();
		return Math::CoordUI(size.x, size.y);
	}

	sf::Vector2f GerenciadorGrafico::getCentroCam() const {
		return camera.getCenter();
	}

	sf::Vector2f GerenciadorGrafico::getCameraPos() const {
		return pJanela->getView().getCenter();
	}

	sf::RenderWindow* GerenciadorGrafico::getJanela() {
		return pJanela;
	}

	sf::Texture* GerenciadorGrafico::carregarTextura(const char* caminho) {
		if (texturas.count(caminho)) {
			return texturas[caminho];
		}

		sf::Texture* textura = new sf::Texture();
		if (!textura->loadFromFile(caminho)) {
			return nullptr;
		}

		texturas.emplace(caminho, textura);
		return textura;
	}


}
