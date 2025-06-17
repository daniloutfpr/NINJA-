	#include "Jogador.h"	
	#include "ControleJogador.h"
namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(sf::Vector2f pos,  sf::Vector2f tam,ID id) :Personagem(pos, tam,id),velocidade(PLAYER_VELOCIDADE)
		{
			vel = Math::CoordF(10.0f, 10.0f);
			Jogador1 = true;
			corpo = new sf::RectangleShape(tam);
			corpo->setFillColor(sf::Color::Red);
		
			corpo->setPosition(pos);
			pControle = new Gerenciadores::ControleJogador(this);
		}

		Jogador::~Jogador() {
			if (pControle) {
				pControle = nullptr;
				delete pControle;
			}
		}

		

		const bool Jogador::getJogador1() const {
			return Jogador1;
		}
		
		void Jogador::mover(bool esquerda) {
			if (podeMover) {
				movendo = true;
				std::cout << "Jogador::mover chamado! Esquerda: " << esquerda << std::endl;
				if (esquerda) {
					olhaEsquerda = true;
				}
				else
					olhaEsquerda = false;
			}
		}

		void Jogador::atualizar(float dt) {

			//vel = Math::CoordF(0.1f, 0.1f);
			if (movendo) {
				if (olhaEsquerda) {
					setVelX(-velocidade);
				}
				else {
					setVelX(velocidade);
				}

			}

			else
				setVelX(0.0);

			
			vel.y += GRAVIDADE * dt;
			posicao.x += vel.x * dt;
			posicao.y += vel.y * dt;
			
			pColisao->notificaColisao(this, dt);
			this->setPosicao(posicao);
			//std::cout << posicao.x << std::endl;

		}

		void Jogador::executar() {
			//mover();
			atualizar(pGrafico->getDeltaTempo());
			//pColisao->notificaColisao(this, pGrafico->getDeltaTempo());
		}
	}
}