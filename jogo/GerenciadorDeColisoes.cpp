#include "GerenciadorDeColisoes.h"
#include "Personagem.h"
namespace Gerenciadores {
    // ============================================================================
    // Construtora, Destrutora e Singleton
    // ============================================================================

    GerenciadorColisoes* GerenciadorColisoes::instancia = nullptr;

    GerenciadorColisoes::GerenciadorColisoes()
        : jogadores(), inimigos(), obstaculos()  {
        limparEntidades();
    }

    GerenciadorColisoes::~GerenciadorColisoes() {
        limparEntidades();
    }

    GerenciadorColisoes* GerenciadorColisoes::getInstancia() {
        if (!instancia) {
            instancia = new GerenciadorColisoes();
        }
        return instancia;
    }

    // ============================================================================
    // Funcoes auxiliares
    // ============================================================================

    float GerenciadorColisoes::calcOverlapVert(
        const Entidades::Entidade* e1, const Entidades::Entidade* e2) const {
        if (e1 && e2) {
            float distY = std::abs((e1->getPos().y + e1->getTamanho().y / 2.f) -
                (e2->getPos().y + e2->getTamanho().y / 2.f));
            float distColisaoY =
                (e1->getTamanho().y / 2.f) + (e2->getTamanho().y / 2.f);

            if (distColisaoY - distY > 0)
                return distColisaoY - distY;
            return 0;

        }
        else {
            std::cerr << "erro: GerenciadorColisoes::calcOverlapVert(...)\n";
            exit(EXIT_FAILURE);
        }
    }

    float GerenciadorColisoes::calcOverlapHor(const Entidades::Entidade* e1,
        const Entidades::Entidade* e2) const {
        if (e1 && e2) {
            float distX = std::abs((e1->getPos().x + e1->getTamanho().x / 2.f) -
                (e2->getPos().x + e2->getTamanho().x / 2.f));
            float distColisaoX =
                (e1->getTamanho().x / 2.f) + (e2->getTamanho().x / 2.f);

            if (distColisaoX - distX > 0)
                return distColisaoX - distX;
            return 0;

        }
        else {
            std::cerr << "erro: GerenciadorColisoes::calcOverlapHor(...)\n";
            exit(EXIT_FAILURE);
        }
    }

    sf::Vector2f GerenciadorColisoes::calcOverlap(
        const Entidades::Entidade* e1, const Entidades::Entidade* e2) const {
        return sf::Vector2f(calcOverlapHor(e1, e2), calcOverlapVert(e1, e2));
    }

    bool GerenciadorColisoes::colidiuVertical(const Entidades::Entidade* e1,
        const Entidades::Entidade* e2) const {
        return calcOverlapVert(e1, e2) != 0;
    }

    bool GerenciadorColisoes::colidiuHorizontal(
        const Entidades::Entidade* e1, const Entidades::Entidade* e2) const {
        return calcOverlapHor(e1, e2) != 0;
    }

    bool GerenciadorColisoes::colidiu(const Entidades::Entidade* e1,
        const Entidades::Entidade* e2) const {
        if (e1 && e2)
            return (colidiuHorizontal(e1, e2) && colidiuVertical(e1, e2));
        else {
            std::cerr << "erro: GerenciadorColisoes::colidiu(...)\n";
            exit(EXIT_FAILURE);
        }
    }

    // ============================================================================
    // Funcao do padrao de projeto Mediator
    // ============================================================================

    void GerenciadorColisoes::notificar(Entidades::Entidade* sender) {
        if (sender == nullptr) {
            std::cerr << "erro: GerenciadorColisoes::notificar(...)\n";
            exit(EXIT_FAILURE);
        }

        ID id = sender->getID();

        //if (ehProjetil(id))
            //verificarProj(sender);

         if (id == inimigo)
            verificarInim(sender);

        else if (id == jogador)
            verificarJog(sender);
    }

    // ============================================================================
    // Funcao para verificar se projetil colidiu com jogador, inimigo ou obstaculo
    // ============================================================================

   /* void GerenciadorColisoes::verificarProj(Entidades::Entidade* pEnt) {
        if (pEnt == nullptr) {
            std::cerr << "erro: GerenciadorColisoes::verificarProj(...)\n";
            exit(EXIT_FAILURE);
        }

        std::set<Entidades::Personagens::Jogador*>::iterator jogIt;
        std::set<Entidades::Personagens::Inimigos::Inimigo*>::iterator inimIt;
        std::set<Entidades::Obstaculos::Obstaculo*>::iterator obstIt;

        // Detectar colisao projetil-jogador
        for (jogIt = jogadores.begin(); jogIt != jogadores.end(); jogIt++) {
            if (*jogIt) {
                if (colidiu(pEnt, *jogIt)) {
                    (*jogIt)->colidir(pEnt);
                    pEnt->colidir();
                }
            }
            else {
                std::cerr << "erro: GerenciadorColisoes::verificarProj(...)\n";
                exit(EXIT_FAILURE);
            }
        }

        // Detectar colisao projetil-inimigo
        for (inimIt = inimigos.begin(); inimIt != inimigos.end(); inimIt++) {
            if (*inimIt) {
                if (colidiu(pEnt, *inimIt)) {
                    (*inimIt)->colidir(pEnt);
                    pEnt->colidir();
                }
            }
            else {
                std::cerr << "erro: GerenciadorColisoes::verificarProj(...)\n";
                exit(EXIT_FAILURE);
            }
        }

        // Detectar colisao projetil-obstaculo
        for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
            if (*obstIt) {
                if (colidiu(pEnt, *obstIt)) {
                    pEnt->colidir();
                }
            }
            else {
                std::cerr << "erro: GerenciadorColisoes::verificarProj(...)\n";
                exit(EXIT_FAILURE);
            }
        }
    }

    */
    // ============================================================================
    // Funcao para verificar se inimigo colidiu com jogador ou obstaculo
    // ============================================================================

    void GerenciadorColisoes::verificarInim(Entidades::Entidade* pEnt) {
        if (pEnt == nullptr) {
            std::cerr << "erro: GerenciadorColisoes::verificarInim(...) => inimigo == "
                "nullptr\n";
            exit(EXIT_FAILURE);
        }

        std::set<Entidades::Personagens::Jogador*>::iterator jogIt;
        std::set<Entidades::Obstaculos::Obstaculo*>::iterator obstIt;

        // Detectar colisao inimigo-jogador
        for (jogIt = jogadores.begin(); jogIt != jogadores.end(); jogIt++) {
            if (*jogIt) {
                if (colidiu(pEnt, *jogIt)) {
                    (pEnt)->colidir(*jogIt);
                }
            }
            else {
                std::cerr << "erro: GerenciadorColisoes::verificarInim(...) jogador == "
                    "nullptr\n";
                exit(EXIT_FAILURE);
            }
        }

        // Detectar colisao inimigo-obstaculo
        for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
            if (*obstIt) {
                if (colidiu(pEnt, *obstIt)) {
                    (*obstIt)->colidir(pEnt);
                }
            }
            else {
                std::cerr << "erro: GerenciadorColisoes::verificarInim(...) obstaculo == "
                    "nullptr\n";
                exit(EXIT_FAILURE);
            }
        }
    }

    // ============================================================================
    // Funcao para verificar se jogador colidiu com algum obstaculo
    // ============================================================================

    void GerenciadorColisoes::verificarJog(Entidades::Entidade* pEnt) {
        if (pEnt == nullptr) {
            std::cerr << "erro: GerenciadorColisoes::verificarJog(...)\n";
            exit(EXIT_FAILURE);
        }

        std::set<Entidades::Obstaculos::Obstaculo*>::iterator obstIt;

        for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
            if (*obstIt) {
                if (colidiu(pEnt, *obstIt)) {
                    // Jogador colide com obstaculo
                    (*obstIt)->colidir(pEnt);
                }
            }
            else {
                std::cerr << "erro: GerenciadorColisoes::verificarJog(...)\n";
                exit(EXIT_FAILURE);
            }
        }
    }

    // ============================================================================
    // Funcoes para gerenciar os conjuntos de entidades
    // ============================================================================

    void GerenciadorColisoes::incluirJog(Entidades::Personagens::Jogador* pJog) {
        if (pJog)
            jogadores.insert(pJog);
    }

    void GerenciadorColisoes::incluirInim(Entidades::Personagens::Inimigo* pInim) {
        if (pInim)
            inimigos.insert(pInim);
    }

    void GerenciadorColisoes::incluirObst(Entidades::Obstaculos::Obstaculo* pObst) {
        if (pObst)
            obstaculos.insert(pObst);
    }

    //void GerenciadorColisoes::incluirProj(Projetil* pProj) {
       // if (pProj)
          //  projeteis.insert(pProj);
   // }

    void GerenciadorColisoes::limparEntidades() {
        jogadores.clear();
        inimigos.clear();
        obstaculos.clear();
       // projeteis.clear();
    }

    void GerenciadorColisoes::removerEnt(Entidades::Entidade* pEnt) {
        ID id = pEnt->getID();

        if (id==inimigo) {
           Entidades::Personagens::Inimigo* aux =
                dynamic_cast<Entidades::Personagens::Inimigo*>(pEnt);

            inimigos.erase(aux);

        }
        else if (id==jogador) {
            Entidades::Personagens::Jogador* aux = dynamic_cast<Entidades::Personagens::Jogador*>(pEnt);
            jogadores.erase(aux);
        }

       // else if (ehProjetil(id)) {
         //   Projetil* aux = dynamic_cast<Projetil*>(pEnt);
           // projeteis.erase(aux);
        //}
    }

}