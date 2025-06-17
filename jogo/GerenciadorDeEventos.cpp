#include "GerenciadorDeEventos.h"
namespace Gerenciadores {
	GerenciadorDeEventos* GerenciadorDeEventos::pEventos = nullptr;
	GerenciadorGrafico* GerenciadorDeEventos::pGrafico = GerenciadorGrafico::getInstancia();
	GerenciadorDeInput* GerenciadorDeEventos::pInput = GerenciadorDeInput::getInstancia();

	GerenciadorDeEventos::GerenciadorDeEventos() {
		//pGrafico = GerenciadorGrafico::getInstancia();
		//pInput = GerenciadorDeInput::getInstancia();
	}

	GerenciadorDeEventos::~GerenciadorDeEventos(){}

	GerenciadorDeEventos* GerenciadorDeEventos::getInstancia() {
		if (pEventos == nullptr) {
			pEventos = new GerenciadorDeEventos();
		}
		return pEventos;
	}

	void GerenciadorDeEventos::verificaEvento(){
		sf::Event e;
		while (pGrafico->evGraficos(e)) {
			if (e.type == sf::Event::Closed) { pGrafico->fecharJanela(); }
			if (e.type == sf::Event::KeyPressed) { pInput->notificaTeclaPressionada(e.key.code); }
			if (e.type == sf::Event::KeyReleased) { pInput->notificaTeclaSolta(e.key.code); }

		}
	}
}
