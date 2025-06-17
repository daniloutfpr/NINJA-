#pragma once
#include "Observer.h"
namespace Gerenciadores {
	class Subject
	{
	protected:
		std::list<Observer*> observers;
	public:
		virtual ~Subject() = default;
		virtual void adicionarObserver(Observer* obs) = 0;
		virtual void removerObserver(Observer* obs) = 0;

		virtual void notificaTeclaPressionada(sf::Keyboard::Key tecla) = 0;
		virtual void notificaTeclaSolta(sf::Keyboard::Key tecla) = 0;
	};
}

