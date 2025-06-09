#pragma once
#include "GerenciadorGrafico.h"
enum ID {
	vazio = 0,
	jogador,
	inimigo,
	plataforma
};

class Ente{
protected:
	sf::RectangleShape* corpo;
	static Gerenciadores::GerenciadorGrafico* pGrafico;
	ID id;
public:
	Ente(ID id = ID::vazio);
	virtual ~Ente();
	void setID(ID id);
	ID getID() const;
	virtual void renderiza() = 0;


};

