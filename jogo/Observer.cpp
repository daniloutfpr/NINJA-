#include "Observer.h"
#include "GerenciadorDeInput.h"
namespace Gerenciadores {
	Observer::Observer():ativo(true){
		
		pInput = GerenciadorDeInput::getInstancia();
		pInput->adicionarObserver(this);
	}

	Observer::~Observer(){}

	bool Observer::getAtivo() const{
		return ativo;
	}

	void Observer::setAtivo(const bool a) {
		ativo = a;
	}

}