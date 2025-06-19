#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Fase.h"
using namespace std;
namespace Ninja {
	class Principal
	{
	private:
		//sf::RenderWindow window;
		//Entidades::Obstaculos::Obstaculo obstacul;
		//Entidades::Obstaculos::Plataforma plat;
		//Lista::ListaDeEntidades* entidadesM;
		//Lista::ListaDeEntidades* entidadesE;
		Gerenciadores::GerenciadorDeEventos* pEvento;
		Gerenciadores::GerenciadorDeColisoes* pColisoes;
		Gerenciadores::GerenciadorGrafico* pGrafico;
		Fases::Fase* fase;
	public:
		Principal();
		~Principal();
		void executar();

	};
}

