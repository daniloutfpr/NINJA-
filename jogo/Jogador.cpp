#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) :Personagem(pos, tam)
		{
			inicializa();
			corpo.setPosition(pos);

		}

		Jogador::~Jogador() {}

		void Jogador::inicializa() {
			vel = Math::CoordF(0.1f, 0.1f);
			corpo.setFillColor(sf::Color::Red);
		}

		void Jogador::executar() {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				corpo.move(-vel.x, 0.0f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				corpo.move(vel.x, 0.0f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				if (corpo.getPosition().y > 0.0f) {
					corpo.move(0.0f, -vel.y);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				if (corpo.getPosition().y + corpo.getSize().y < 600.0f) {
					corpo.move(0.0f, vel.y);
				}
			}
		}
	}
}