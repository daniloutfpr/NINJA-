	#include "Jogador.h"	
	#include "ControleJogador.h"
	#include"GerenciadorDeColisoes.h"
	#include "Fogueira.h"
namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(sf::Vector2f pos,  sf::Vector2f tam,bool ehJogador1,ID id) :Personagem(pos, tam,id),velocidade(PLAYER_VELOCIDADE)
		{
			vel = Math::CoordF(10.0f, 10.0f);
			Jogador1 = true;
			//corpo = new sf::RectangleShape(tam);
			//corpo->setFillColor(sf::Color::Red);
		
			//corpo->setPosition(pos);
			pControle = new Gerenciadores::ControleJogador(this);
			pFog = new Entidades::Obstaculos::Fogueira((sf::Vector2f(0, 0), (sf::Vector2f(0, 0))));

			carregaTexturas();
			setnum_vidas(PLAYER_VIDA);
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
				//std::cout << "Jogador::mover chamado! Esquerda: " << esquerda << std::endl;
				if (esquerda) {
					olhaEsquerda = true;
				}
				else
					olhaEsquerda = false;
			}
		}
		
		void Jogador::verificaInimigosAlcance() {
			

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
			atualizarSprite(dt);
			this->setPosicao(posicao);
			pColisao->notificar(this);
			atualizarSprite(dt);
			//this->setPosicao(posicao);
			//std::cout << posicao.x << std::endl;

		}

		void Jogador::executar() {
			//mover();
			atualizar(pGrafico->getDeltaTempo());
			//std::cout << "Player posy:" << this->getPos().y <<  std::endl;
			//pColisao->notificaColisao(this, pGrafico->getDeltaTempo());
		}

		void Jogador::carregaTexturas() {
			sprite = new ElementosGraficos::Animacao(corpo, Math::CoordF(0.1, 0.1));

			sprite->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::idle, "ninja_idle.png", 12);
				//sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "p1_idle.png", 10);

			//corpo->setOrigin(tamanho.x / 2 + 15, tamanho.y / 2 - 80);

		}

		void Jogador::atualizarSprite(float dt) {
			sprite->atualizar(ElementosGraficos::ID_Animacao::idle, !olhaEsquerda, Math::CoordF(posicao.x,posicao.y), dt);
		}

		void Jogador::colidir(Entidade* pEnt) {
			if (pEnt->getID() == ID::inimigo) {
				std::cout << "Jogador Ira atacar ou sofrer dano!" << std::endl;
			}
		}

		void Jogador::sofrerLentidao(float lent) {
			Math::CoordF vel = getVel();
			vel *= lent;
			setVelX(vel.x);
		}
	}
}