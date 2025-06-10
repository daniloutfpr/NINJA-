#include "GerenciadorDeColisoes.h"
namespace Gerenciadores {

	GerenciadorDeColisoes* GerenciadorDeColisoes::pColisao = nullptr;

	GerenciadorDeColisoes::GerenciadorDeColisoes(){}

	GerenciadorDeColisoes::GerenciadorDeColisoes(Lista::ListaDeEntidades* eEstaticas, Lista::ListaDeEntidades* eMoveis) :entidadesEstaticas(eEstaticas)
		, entidadesMoveis(eMoveis) {}

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

		//colisao com entidades estaticas

		for (auto itE = entidadesEstaticas->begin(); itE != entidadesEstaticas->end(); itE++) {
			outraEntidade = *itE;
			if (sender && outraEntidade) {
				dCentral.x = sender->getPosition().x - outraEntidade->getPosition().x;
				dCentral.y = sender->getPosition().y - outraEntidade->getPosition().y;

				interseccao.x = fabs(dCentral.x) - (sender->getTamanho().x / 2.0f + outraEntidade->getTamanho().x);
				interseccao.y = fabs(dCentral.y) - (sender->getTamanho().y / 2.0f + outraEntidade->getTamanho().x);

				if (interseccao.x < 0.0f && interseccao.y < 0.0f) {
					trataColisao(sender, outraEntidade, interseccao, dt);
				}

			}

		}

		for (auto itM = entidadesMoveis->begin(); itM != entidadesMoveis->end(); itM++) {
			if (*itM != sender) {
				outraEntidade = *itM;//depois vou ter que verificar se a entidade esta viva ou morta
				auto* pIn = static_cast<Entidades::Personagens::Personagem*>(outraEntidade);
				if (sender && outraEntidade) {
					dCentral.x = sender->getPosition().x - outraEntidade->getPosition().x;
					dCentral.y = sender->getPosition().y - outraEntidade->getPosition().y;

					interseccao.x = fabs(dCentral.x) - (sender->getTamanho().x / 2.0f + outraEntidade->getTamanho().x);
					interseccao.y = fabs(dCentral.y) - (sender->getTamanho().y / 2.0f + outraEntidade->getTamanho().x);

					if (interseccao.x < 0.0f && interseccao.y < 0.0f) {
						trataColisao(sender, outraEntidade, interseccao, dt);
					}
				}
			}


		}
	}

	void GerenciadorDeColisoes::trataColisao(Entidades::Personagens::Personagem* sender, Entidades::Entidade* outraEntidade, Math::CoordF interseccao, float dt) {
		//colisao notificada pelo jogador
		if(sender->getID() == ID::jogador) {
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



	void GerenciadorDeColisoes::moverColisao(Entidades::Personagens::Personagem* sender, Entidades::Entidade* outraEntidade, Math::CoordF interseccao, float dt){
		Math::CoordF senderPos = sender->getPosition();
		Math::CoordF outroPos = outraEntidade->getPosition();

		//colisao em x
		if (interseccao.x > interseccao.y) {
			if (senderPos.x < outroPos.x) {
				senderPos.x += interseccao.x;
			}
			else
				senderPos.x -= interseccao.x;
			sender->setPos(senderPos);
			sender->setVelX(0.0f);
		}
		else
		{
			if (senderPos.y < outroPos.y) {
				senderPos.y += outroPos.y;
				if (auto* personagem = sender) {
					personagem->setPulo(true);
				}
			}
			else
				senderPos.y -= outroPos.y;

			sender->setPos(senderPos);
			sender->setVelY(0.0f);
		}
		
	}

}