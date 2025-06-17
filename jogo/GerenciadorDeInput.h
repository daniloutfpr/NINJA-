#pragma once
#include "Subject.h"
namespace Gerenciadores {
	class GerenciadorDeInput : public Subject
	{
	private:
		static GerenciadorDeInput* pInput;
		GerenciadorDeInput();
	public:
		~GerenciadorDeInput();
		static GerenciadorDeInput* getInstancia();
		void adicionarObserver(Observer* obs) ;
		void removerObserver(Observer* obs) ;

		void notificaTeclaPressionada(sf::Keyboard::Key tecla) ;
		void notificaTeclaSolta(sf::Keyboard::Key tecla) ;
	};
}

