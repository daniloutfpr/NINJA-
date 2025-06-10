#include "Principal.h"

Ninja::Principal::Principal():
	plat(sf::Vector2f(0.0f, 600.0f), sf::Vector2f(1000.0f, 200.0f), plataforma)
	
	//window(sf::VideoMode(800.0f, 600.0f), "Brasil++")
{
	entidadesM = new Lista::ListaDeEntidades();
	pGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();
	Entidades::Personagens::Jogador* j1 = new Entidades::Personagens::Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f,50.0f),jogador);
	Entidades::Personagens::Inimigo* i1 = new Entidades::Personagens::Inimigo(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(50.0f, 50.0f),j1,inimigo);
	Entidades::Personagens::Personagem* p1 = static_cast<Entidades::Personagens::Personagem*>(j1);
	Entidades::Personagens::Personagem* p2 = static_cast<Entidades::Personagens::Personagem*>(i1);

	entidadesM->adicionarEntidade(p1);
	entidadesM->adicionarEntidade(p2);

	executar();
}

Ninja::Principal::~Principal(){
	//isso vai ser mudado para uma lista de entidades moveis e estaticas
}

void Ninja:: Principal::executar(){
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
		//pGrafico->renderizar(obstacul.getObs());
		plat.renderiza();
		for (auto itM = entidadesM->begin();itM!=entidadesM->end() ; itM++) {
			(*itM)->renderiza();
			(*itM)->executar();

		}
		//window.draw(jogador.getCorpo());
		//jogador.mover();
		pGrafico->display();
	}

}