#pragma once
#include "GerenciadorDeEventos.h"
namespace Gerenciadores {
	class ControleJogador:public Observer
	{
	private:
		Entidades::Personagens::Jogador* pJogador;
		sf::Keyboard::Key moverDireita;   
		sf::Keyboard::Key moverEsquerda;  
		//sf::Keyboard::Key atacar;        
		sf::Keyboard::Key pular;        
		//sf::Keyboard::Key defender;      
		//sf::Keyboard::Key pausar;
	public:
		ControleJogador(Entidades::Personagens::Jogador* pJog = nullptr);
		~ControleJogador();
		void notificaTeclaPressionada(sf::Keyboard::Key tecla);
		void notificaTeclaSolta(sf::Keyboard::Key tecla);
	};
}

