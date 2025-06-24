#include "Inimigo.h"
#include"GerenciadorDeColisoes.h"
namespace Entidades {
	namespace Personagens {
	
		Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam,ID id ):
			Personagem(pos,tam,id),pJogador1(nullptr),pJogador2(nullptr){
			corpo = new sf::RectangleShape(tam);
			vel = Math::CoordF(0.05f, 0.05f);
			corpo->setPosition(pos);
		}

		Inimigo::~Inimigo(){}

		void Inimigo::setJogadores(Jogador* j1, Jogador* j2) {
			pJogador1 = j1;
			if (j2) {
			pJogador2 = j2;
			}
		}

		void Inimigo::set_nivelMaldade(int nv) {
			nivel_maldade = nv;
		}

		int Inimigo::get_nivelMaldade() {
			return nivel_maldade;
		}
		
		Jogador* Inimigo::jogadorMaisProximo() {
			Math::CoordF d1 = fabs(posicao.x - pJogador1->getPosition().x);
			Math::CoordF d2 = fabs(posicao.x - pJogador2->getPosition().x);
			return (d1.x > d2.x ? pJogador2 : pJogador1);
		}
		
	}
}