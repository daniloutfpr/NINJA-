#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		//pColisao = Gerenciadores::GerenciadorDeColisoes::getInstancia();
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id) 
			:Entidade(pos,tam,id),movendo(false),podeMover(true),olhaEsquerda(false),num_vidas(100),dano(10),vivo(true)
		{
			//corpo->setPosition(pos);
			pular = true;
			//pColisao = Gerenciadores::GerenciadorDeColisoes::getInstancia();
		}
		Personagem::~Personagem(){}

		Math::CoordF Personagem::getVel() const {
			return vel;
		}

	
		bool Personagem::getPulo() const {
			return pular;
		}
		void Personagem::setnum_vidas(int vidas) {
			num_vidas = vidas;
		}

		void Personagem::receberDano(float dano) {
			setnum_vidas(getnum_vidas() - dano);
			if (num_vidas < 0) {
				setnum_vidas(0);
				setvivo(false);
				setPosicao(sf::Vector2f(2000.f, 2000.f));
			}

		}

		int Personagem::getDano() {
			return dano;
		}
		int Personagem::getnum_vidas() {
			return num_vidas;
		}

		void Personagem::setvivo(bool v) {
			vivo = v;
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