#include "GerenciadorDeInput.h"

namespace Gerenciadores{

	GerenciadorDeInput* GerenciadorDeInput::pInput = nullptr;

	GerenciadorDeInput::GerenciadorDeInput() {

	}

	GerenciadorDeInput::~GerenciadorDeInput() {
		observers.clear();
	}

	GerenciadorDeInput* GerenciadorDeInput::getInstancia() {
		if (pInput == nullptr) {
			pInput = new GerenciadorDeInput();
		}
		return pInput;
	}
	

	void GerenciadorDeInput::adicionarObserver(Observer* obs) {
		if (obs) {
			observers.push_back(obs);
		}
	}

	void GerenciadorDeInput::removerObserver(Observer* obs) {
		if (obs) {
			observers.remove(obs);
		}
	}

	void GerenciadorDeInput::notificaTeclaPressionada(sf::Keyboard::Key tecla){
		for (auto& observer : observers) {
			if (observer) {
				//std::cout << "Ta chamando o ObserverAAAA!" << std::endl;
				if (observer->getAtivo())
					observer->notificaTeclaPressionada(tecla);
			}
		}
	}

	void GerenciadorDeInput::notificaTeclaSolta(sf::Keyboard::Key tecla) {
		for (auto& observer : observers) {
			if (observer) {
				if (observer->getAtivo())
					observer->notificaTeclaSolta(tecla);
			}
		}
	}

}