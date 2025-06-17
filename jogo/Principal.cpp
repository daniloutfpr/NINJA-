#include "Principal.h"

Ninja::Principal::Principal()
	//plat(sf::Vector2f(0.0f, 600.0f), sf::Vector2f(1000.0f, 200.0f), plataforma)
	
	//window(sf::VideoMode(800.0f, 600.0f), "Brasil++")
{
	entidadesM = new Lista::ListaDeEntidades();
	entidadesE = new Lista::ListaDeEntidades();
	pEvento = Gerenciadores::GerenciadorDeEventos::getInstancia();
	pGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();
	pColisoes = Gerenciadores::GerenciadorDeColisoes::getInstancia();
	Entidades::Personagens::Jogador* j1 = new Entidades::Personagens::Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f,50.0f),jogador);
	//Entidades::Personagens::Inimigo* i1 = new Entidades::Personagens::Inimigo(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(50.0f, 50.0f),j1,inimigo);
	Entidades::Personagens::Personagem* p1 = static_cast<Entidades::Personagens::Personagem*>(j1);
	//Entidades::Personagens::Personagem* p2 = static_cast<Entidades::Personagens::Personagem*>(i1);
	Entidades::Obstaculos::Plataforma* plat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(0.0f, 600.0f), sf::Vector2f(1000.0f, 200.0f), plataforma);
	//Entidades::Obstaculos::Plataforma* plat1 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(200.0f, 300.0f), sf::Vector2f(300.0f, 200.0f), plataforma);
	pColisoes->setListas(entidadesE, entidadesM);
	entidadesM->adicionarEntidade(p1);
	//entidadesM->adicionarEntidade(p2);
	entidadesE->adicionarEntidade(plat);
	//entidadesE->adicionarEntidade(plat1);
	executar();
}

Ninja::Principal::~Principal(){
	//isso vai ser mudado para uma lista de entidades moveis e estaticas
}

void Ninja::Principal::executar() {
	while (pGrafico->janelaAberta()) {
		pGrafico->atualizaDeltaTempo();
		pEvento->verificaEvento();
		pGrafico->limpar();

		entidadesE->executar(pGrafico->getDeltaTempo());
		entidadesM->executar(pGrafico->getDeltaTempo());

		pGrafico->display();
	}
}

