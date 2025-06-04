#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Obstaculo.h"
using namespace std;
namespace Brasil {
	class Principal
	{
	private:
		//sf::RenderWindow window;
		Entidades::Obstaculos::Obstaculo obstacul;
		std::vector<Entidades::Personagens::Personagem*> personagens;
		Gerenciadores::GerenciadorGrafico* pGrafico;
	public:
		Principal();
		~Principal();
		void executar();

	};
}

