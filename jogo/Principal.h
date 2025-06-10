#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Plataforma.h"
using namespace std;
namespace Ninja {
	class Principal
	{
	private:
		//sf::RenderWindow window;
		//Entidades::Obstaculos::Obstaculo obstacul;
		Entidades::Obstaculos::Plataforma plat;
		Lista::ListaDeEntidades* entidadesM;
		Lista::ListaDeEntidades* entidadesE;
		Gerenciadores::GerenciadorGrafico* pGrafico;
	public:
		Principal();
		~Principal();
		void executar();

	};
}

