#include "ControleJogador.h"
namespace Gerenciadores {
    ControleJogador::ControleJogador(Entidades::Personagens::Jogador* pJog)
        : Observer(), pJogador(pJog) {

        moverDireita = sf::Keyboard::Unknown;
        moverEsquerda = sf::Keyboard::Unknown;
       // atacar = sf::Keyboard::Unknown;
        pular = sf::Keyboard::Unknown;
       // defender = sf::Keyboard::Unknown;
       // usarPocao = sf::Keyboard::Unknown;
        //pausar = sf::Keyboard::Escape;

        if (pJogador) {
            if (pJogador->getJogador1()) {
                moverDireita = sf::Keyboard::D;
                moverEsquerda = sf::Keyboard::A;
                pular = sf::Keyboard::W;
                //atacar = sf::Keyboard::Q;
                //defender = sf::Keyboard::E;
                //usarPocao = sf::Keyboard::Z;
            }
            else {
                moverDireita = sf::Keyboard::L;
                moverEsquerda = sf::Keyboard::J;
                pular = sf::Keyboard::I;
                //atacar = sf::Keyboard::U;
                //defender = sf::Keyboard::O;
                //usarPocao = sf::Keyboard::N;
            }
        }
    }

    ControleJogador::~ControleJogador() {
        pJogador = nullptr;
    }

    void ControleJogador::notificaTeclaPressionada(sf::Keyboard::Key tecla) {
        std::cout << "Tecla pressionada detectada: " << tecla << std::endl;
        if (tecla == moverDireita) {
            if (pJogador->getPodeMover()) {
                pJogador->mover(false);
            }
        }
        if (tecla == moverEsquerda) {
            if (pJogador->getPodeMover()) {
                pJogador->mover(true);
            }
        }

        if (tecla == pular) {
            if (pJogador->getPulo()) {
                pJogador->pulo();
            }
        }
   }


    void ControleJogador::notificaTeclaSolta(sf::Keyboard::Key tecla) {
        if (tecla == moverDireita && !sf::Keyboard::isKeyPressed(moverEsquerda)) {
            if (pJogador->getPodeMover()) {
                pJogador->pararDeMover();
            }
        }

        if (tecla == moverEsquerda && !sf::Keyboard::isKeyPressed(moverDireita)) {
            if (pJogador->getPodeMover()) {
                pJogador->pararDeMover();
            }
        }
    }

}