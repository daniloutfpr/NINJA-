#pragma once
#include "GerenciadorDeColisoes.h"
namespace Gerenciadores {
	
	class GerenciadorDeInput;

	class Observer
	{
	protected:
		Gerenciadores::GerenciadorDeInput* pInput;
		bool ativo;
	public:
		Observer();
		~Observer();
		bool getAtivo() const;
		void setAtivo(const bool a);
		virtual void notificaTeclaPressionada(sf::Keyboard::Key tecla) = 0;
		virtual void notificaTeclaSolta(sf::Keyboard::Key tecla) = 0;
	};
}