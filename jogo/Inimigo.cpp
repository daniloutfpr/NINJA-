#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
	
		Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, Entidades::Personagens::Jogador* j,ID id ):
			Personagem(pos,tam,id),jogador(j){
			corpo = new sf::RectangleShape(tam);
			inicializa();
			corpo->setPosition(pos);
		}

		Inimigo::~Inimigo(){}

		void Inimigo::inicializa() {
			vel = Math::CoordF(0.05f, 0.05f);
			corpo->setFillColor(sf::Color::Green);
		}

		void Inimigo::mover() {
			sf::Vector2f posJogador = jogador->getPos();
			sf::Vector2f posInimigo = corpo->getPosition();

			if (fabs(posJogador.x - posInimigo.x) <= 200.0f && fabs(posJogador.y - posInimigo.y) <= 200.0f) 
			{
				if (posJogador.x - posInimigo.x > 0.0f) {
					corpo->move(vel.x, 0.0f);
				}
				else {
					corpo->move(-vel.x, 0.0f);
				}
				if (posJogador.y - posInimigo.y > 0.0f) {
					corpo->move(0.0f, vel.y);  
				}
				else {
					corpo->move(0.0f, -vel.y); 
				}
			}

		}

		void Inimigo::executar() {
			mover();
		}
	}
}