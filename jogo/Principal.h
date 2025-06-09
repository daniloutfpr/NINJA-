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
		//Entidades::Obstaculos::Plataforma plat;
		std::vector<Entidades::Personagens::Personagem*> personagens;
		Gerenciadores::GerenciadorGrafico* pGrafico;
	public:
		Principal();
		~Principal();
		void executar();

	};
}

