#include "GerenciadorDeColisoes.h"
#include "Personagem.h"
namespace Gerenciadores {

	GerenciadorDeColisoes* GerenciadorDeColisoes::pColisao = nullptr;

	GerenciadorDeColisoes::GerenciadorDeColisoes() {}

	GerenciadorDeColisoes::GerenciadorDeColisoes(Lista::ListaDeEntidades* eEstaticas, Lista::ListaDeEntidades* eMoveis) :entidadesEstaticas(eEstaticas)
		, entidadesMoveis(eMoveis) {
	}

	GerenciadorDeColisoes::~GerenciadorDeColisoes() {
		entidadesEstaticas = nullptr;
		entidadesMoveis = nullptr;
	}

	GerenciadorDeColisoes* GerenciadorDeColisoes::getInstancia() {
		if (pColisao == nullptr) {
			pColisao = new GerenciadorDeColisoes();
		}
		return pColisao;
	}

	void GerenciadorDeColisoes::setListas(Lista::ListaDeEntidades* eE, Lista::ListaDeEntidades* eM) {
		entidadesEstaticas = eE;
		entidadesMoveis = eM;
	}

	void GerenciadorDeColisoes::notificaColisao(Entidades::Personagens::Personagem* sender, float dt) {
		Math::CoordF interseccao;
		Math::CoordF dCentral;
		Entidades::Entidade* outraEntidade = nullptr;

		// Colisão com entidades estáticas
		for (auto itE = entidadesEstaticas->begin(); itE != entidadesEstaticas->end(); itE++) {
			outraEntidade = *itE;
			if (sender && outraEntidade) {
				dCentral.x = sender->getPosition().x - outraEntidade->getPosition().x;
				dCentral.y = sender->getPosition().y - outraEntidade->getPosition().y;

				// CÁLCULO CORRIGIDO AQUI
				interseccao.x = fabs(dCentral.x) - (sender->getTamanho().x / 2.0f + outraEntidade->getTamanho().x / 2.0f);
				interseccao.y = fabs(dCentral.y) - (sender->getTamanho().y / 2.0f + outraEntidade->getTamanho().y / 2.0f);

				if (interseccao.x < 0.0f && interseccao.y < 0.0f) {
					trataColisao(sender, outraEntidade, interseccao, dt);
				}
			}
		}

		// Colisão com entidades móveis
		for (auto itM = entidadesMoveis->begin(); itM != entidadesMoveis->end(); itM++) {
			if (*itM != sender) {
				outraEntidade = *itM;
				if (sender && outraEntidade) {
					dCentral.x = sender->getPosition().x - outraEntidade->getPosition().x;
					dCentral.y = sender->getPosition().y - outraEntidade->getPosition().y;

					// CÁLCULO CORRIGIDO AQUI TAMBÉM
					interseccao.x = fabs(dCentral.x) - (sender->getTamanho().x / 2.0f + outraEntidade->getTamanho().x / 2.0f);
					interseccao.y = fabs(dCentral.y) - (sender->getTamanho().y / 2.0f + outraEntidade->getTamanho().y / 2.0f);

					if (interseccao.x < 0.0f && interseccao.y < 0.0f) {
						trataColisao(sender, outraEntidade, interseccao, dt);
					}
				}
			}
		}
	}

	void GerenciadorDeColisoes::trataColisao(Entidades::Personagens::Personagem* sender, Entidades::Entidade* outraEntidade, Math::CoordF interseccao, float dt) {
		//colisao notificada pelo jogador


		//std::cout << "Entrando no trata colisao!" << std::endl;
		if (sender->getID() == ID::jogador) {
			if (outraEntidade->getID() == inimigo) {
				moverColisao(sender, outraEntidade, interseccao, dt);
			}
			else if (outraEntidade->getID() == ID::plataforma) {
				moverColisao(sender, outraEntidade, interseccao, dt);
			}
		}

		if (sender->getID() == ID::inimigo) {
			if (outraEntidade->getID() == ID::plataforma) {
				if (auto* plat = outraEntidade) {
					moverColisao(sender, outraEntidade, interseccao, dt);
				}
			}
			else
				moverColisao(sender, outraEntidade, interseccao, dt);
		}
	}



	void GerenciadorDeColisoes::moverColisao(Entidades::Personagens::Personagem* sender, Entidades::Entidade* outraEntidade, Math::CoordF interseccao, float dt) {
		Math::CoordF senderPos = sender->getPosition();
		Math::CoordF outroPos = outraEntidade->getPosition();

		//std::cout << "interseccao x " << interseccao.x << std::endl;
		//std::cout << "interseccao y " << interseccao.y << std::endl;

		
		if (interseccao.x > interseccao.y) {
			
			if (senderPos.x < outroPos.x) {
				
				senderPos.x += interseccao.x;
			}
			else {
				senderPos.x == interseccao.x; 
			}
			sender->setPos(senderPos);
			sender->setVelX(0.0f);
		}
		else {
			
			if (senderPos.y < outroPos.y) {
				senderPos.y += interseccao.y; 
				sender->setPulo(true);
			}
			else {
				senderPos.y -= interseccao.y; 
			}
			sender->setPos(senderPos);
			sender->setVelY(0.0f);
		}
	}
}