#include "Ente.h"

Gerenciadores::GerenciadorGrafico* Ente::pGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();

Ente::Ente(ID id) : id(id) {
	corpo = new sf::RectangleShape();
}

Ente::~Ente() {
	if (corpo) {
		delete corpo;
		corpo = nullptr;
	}
}
void Ente::setID(ID id) {
	this->id = id;
}

ID Ente::getID() const {
	return id;
}