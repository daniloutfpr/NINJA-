#include "Principal.h"

Brasil::Principal::Principal() :
	obstacul(sf::Vector2f(0.0f,600.0f),sf::Vector2f(1000.0f,200.0f))
	//window(sf::VideoMode(800.0f, 600.0f), "Brasil++")
{
	pGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();
	personagens.clear();
	Entidades::Personagens::Jogador* j1 = new Entidades::Personagens::Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f,50.0f));
	Entidades::Personagens::Inimigo* i1 = new Entidades::Personagens::Inimigo(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(50.0f, 50.0f),j1);
	Entidades::Personagens::Personagem* p1 = static_cast<Entidades::Personagens::Personagem*>(j1);
	Entidades::Personagens::Personagem* p2 = static_cast<Entidades::Personagens::Personagem*>(i1);

	personagens.push_back(p1);
	personagens.push_back(p2);

	executar();
}

Brasil::Principal::~Principal(){
	personagens.clear();//isso vai ser mudado para uma lista de entidades moveis e estaticas
}

void Brasil:: Principal::executar(){
	//sf::RectangleShape j(sf::Vector2f(50.0,50.0));
	//j.setFillColor(sf::Color::Blue);
	//jogador.setPosition(50.0, 50.0);

	while (pGrafico->janelaAberta()) {
		sf::Event e;
		if (pGrafico->evGraficos(e)) {
			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Escape) {
					pGrafico->fecharJanela();
				}
			}
		}
		
		pGrafico->limpar();
		pGrafico->renderizar(obstacul.getObs());
		for (int i = 0; i < personagens.size(); i++) {

			pGrafico->renderizar(personagens[i]->getCorpo());
			personagens[i]->executar();

		}
		//window.draw(jogador.getCorpo());
		//jogador.mover();
		pGrafico->display();
	}

}