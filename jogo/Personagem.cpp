#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id) 
			:Entidade(pos,tam,id),movendo(false),podeMover(true),olhaEsquerda(false),num_vidas(0)
		{
			//corpo->setPosition(pos);
			pular = true;
			pColisao = Gerenciadores::GerenciadorDeColisoes::getInstancia();
		}
		Personagem::~Personagem(){}

		void Personagem::setVelX(float vx) {
			vel.x = vx;
		}
		
		void Personagem::setVelY(float vy) {
			vel.y = vy;
		}

		bool Personagem::getPulo() const {
			return pular;
		}

		void Personagem::setPulo(const bool p) {
			pular = p;
		}

		void Personagem::pulo() {
			if (pular) {
				pular = false;
				vel.y -= 500.0f;

			}
		}

		void Personagem::pararDeMover() {
			movendo = false;
		}

		bool Personagem::getPodeMover() {
			return podeMover;
		}

		//const sf::RectangleShape& Personagem::getCorpo() const {
			//return corpo;
		//}
	}
}