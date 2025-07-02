#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		//pColisao = Gerenciadores::GerenciadorDeColisoes::getInstancia();
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam,ID id) 
			:Entidade(pos,tam,id),movendo(false),podeMover(true),olhaEsquerda(false),num_vidas(100),dano(10),vivo(true),atacando(false),podeAtacar(true),pular(false), 
			cooldownAtaque(0.8f), tempoAtaque(0.3f), timerAtaque(0.f), timerCooldown(0.8f)
		{
			//corpo->setPosition(pos);
			//pular = true;
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

		bool Personagem::getAtacando() {
			return atacando;
		}

		bool Personagem::getPodeAtacar() {
			return (timerCooldown > cooldownAtaque);
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
				if(noChao)
				pular = false;
				vel.y -= 350.0f;
			}
		}

		bool Personagem::getVivo() {
			return vivo;
		}

		void Personagem::setDano(int d) {
			dano = d;
		}

		void Personagem::pararDeMover() {
			movendo = false;
		}

		bool Personagem::getPodeMover() {
			return podeMover;
		}

		void Personagem::incrementarTimers(float dt) {
			if (atacando) {
				// Se está atacando, reseta o cooldown e avança o timer de ataque
				timerCooldown = 0.f;
				timerAtaque += dt;
				if (timerAtaque > tempoAtaque) {
					atacando = false; // Termina o ataque
				}
			}
			else {
				// Se não está atacando, avança o timer de cooldown
				timerCooldown += dt;
				timerAtaque = 0.f;
			}
		}
	}
}