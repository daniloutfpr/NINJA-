#include "Principal.h"

Ninja::Principal::Principal()
	//plat(sf::Vector2f(0.0f, 600.0f), sf::Vector2f(1000.0f, 200.0f), plataforma)
	
	//window(sf::VideoMode(800.0f, 600.0f), "Brasil++")
{

	pEvento = Gerenciadores::GerenciadorDeEventos::getInstancia();
	pGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();
	//Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador();
	pColisoes = Gerenciadores::GerenciadorDeColisoes::getInstancia();
	//Fases::Fase fas;
	fase = new Fases::Fase();

}

Ninja::Principal::~Principal(){
	//isso vai ser mudado para uma lista de entidades moveis e estaticas
	if (fase) {
		delete fase;
		fase = nullptr;
	}
}

void Ninja::Principal::executar() {
	while (pGrafico->janelaAberta()) {
		pGrafico->atualizaDeltaTempo();
		pEvento->verificaEvento();
		pGrafico->limpar();

		//entidadesE->executar(pGrafico->getDeltaTempo());
		//entidadesM->executar(pGrafico->getDeltaTempo());

		if (fase) {
			fase->executar();
		}

		pGrafico->display();
	}
}

