#include "GerenciadorDeColisoes.h"
namespace Gerenciadores {
    // ============================================================================
    // Construtora, Destrutora e Singleton
    // ============================================================================

    GerenciadorDeColisoes* GerenciadorDeColisoes::instancia = nullptr;

    GerenciadorDeColisoes::GerenciadorDeColisoes()
        : jogadores(), inimigos(), obstaculos()  {
        limparEntidades();
    }

    GerenciadorDeColisoes::~GerenciadorDeColisoes() {
        limparEntidades();
    }

    GerenciadorDeColisoes* GerenciadorDeColisoes::getInstancia() {
        if (!instancia) {
            instancia = new GerenciadorDeColisoes();
        }
        return instancia;
    }

    // ============================================================================
    // Funcoes auxiliares
    // ============================================================================

    float GerenciadorDeColisoes::calcOverlapVert(const Entidades::Entidade* e1, const Entidades::Entidade* e2) const {
        if (!e1 || !e2) return 0.f;

        // Como getPos() J� retorna o centro, a dist�ncia entre os centros � simples.
        float distCentrosY = std::abs(e1->getPos().y - e2->getPos().y);

        // A soma das "meias alturas"
        float somaMeiasAlturas = (e1->getTamanho().y / 2.f) + (e2->getTamanho().y / 2.f);

        // Se a dist�ncia entre os centros for MENOR que a soma das meias alturas, h� colis�o.
        float overlap = somaMeiasAlturas - distCentrosY;
        return (overlap > 0) ? overlap : 0.f; // Retorna o valor da sobreposi��o, ou 0 se n�o houver.
    }

    // Vers�o corrigida que assume que getPos() retorna o CENTRO
    float GerenciadorDeColisoes::calcOverlapHor(const Entidades::Entidade* e1, const Entidades::Entidade* e2) const {
        if (!e1 || !e2) return 0.f;

        // Dist�ncia entre os centros no eixo X
        float distCentrosX = std::abs(e1->getPos().x - e2->getPos().x);

        // A soma das "meias larguras"
        float somaMeiasLarguras = (e1->getTamanho().x / 2.f) + (e2->getTamanho().x / 2.f);

        float overlap = somaMeiasLarguras - distCentrosX;
        return (overlap > 0) ? overlap : 0.f;
    }

    sf::Vector2f GerenciadorDeColisoes::calcOverlap(
        const Entidades::Entidade* e1, const Entidades::Entidade* e2) const {
        return sf::Vector2f(calcOverlapHor(e1, e2), calcOverlapVert(e1, e2));
    }

    bool GerenciadorDeColisoes::colidiuVertical(const Entidades::Entidade* e1,
        const Entidades::Entidade* e2) const {
        return calcOverlapVert(e1, e2) != 0;
    }

    bool GerenciadorDeColisoes::colidiuHorizontal(
        const Entidades::Entidade* e1, const Entidades::Entidade* e2) const {
        return calcOverlapHor(e1, e2) != 0;
    }

    bool GerenciadorDeColisoes::colidiu(const Entidades::Entidade* e1,
        const Entidades::Entidade* e2) const {
        if (e1 && e2)
            return (colidiuHorizontal(e1, e2) && colidiuVertical(e1, e2));
        else {
            std::cerr << "erro: GerenciadorDeColisoes::colidiu(...)\n";
            exit(EXIT_FAILURE);
        }
    }

    // ============================================================================
    // Funcao do padrao de projeto Mediator
    // ============================================================================

    void GerenciadorDeColisoes::notificar(Entidades::Entidade* sender) {
        if (sender == nullptr) {
            std::cerr << "erro: GerenciadorDeColisoes::notificar(...)\n";
            exit(EXIT_FAILURE);
        }

   

      //  std::cout << "Colidindo!" << std::endl;
        ID id = sender->getID();

        //if (ehProjetil(id))
            //verificarProj(sender);

         if (id == inimigo||id==goblin||id==mago)
            verificarInim(sender);

        else if (id == jogador)
            verificarJog(sender);
    }


    // ============================================================================
    // Funcao para verificar se inimigo colidiu com jogador ou obstaculo
    // ============================================================================

    void GerenciadorDeColisoes::verificarInim(Entidades::Entidade* pEnt) {
        if (pEnt == nullptr) {
            std::cerr << "erro: GerenciadorDeColisoes::verificarInim(...) => inimigo == "
                "nullptr\n";
            exit(EXIT_FAILURE);
        }

        std::set<Entidades::Personagens::Jogador*>::iterator jogIt;
        std::set<Entidades::Obstaculos::Obstaculo*>::iterator obstIt;
       
        
        for (jogIt = jogadores.begin(); jogIt != jogadores.end(); jogIt++) {
            if (*jogIt) {
                if (colidiu(pEnt, *jogIt)) {
                    (pEnt)->colidir(*jogIt);
                }
            }
            else {
                std::cerr << "erro: GerenciadorDeColisoes::verificarInim(...) jogador == "
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
                std::cerr << "erro: GerenciadorDeColisoes::verificarInim(...) obstaculo == "
                    "nullptr\n";
                exit(EXIT_FAILURE);
            }
        }
    }

    // ============================================================================
    // Funcao para verificar se jogador colidiu com algum obstaculo
    // ============================================================================

    void GerenciadorDeColisoes::verificarJog(Entidades::Entidade* pEnt) {
        if (!pEnt) return;

        // Checa colis�o do Jogador com todos os Obst�culos
        for (auto const& pObst : obstaculos) {
            if (colidiu(pEnt, pObst)) {
                sf::Vector2f overlap = calcOverlap(pEnt, pObst);
                // Avisa o obst�culo (Plataforma, Fogueira, etc) sobre a colis�o
                pObst->colidir(pEnt);
            }
        }

        // Checa colis�o do Jogador com todos os Inimigos
        for (auto const& pInim : inimigos) {
            if (colidiu(pEnt, pInim)) {
                sf::Vector2f overlap = calcOverlap(pEnt, pInim);
                // Avisa AMBOS sobre a colis�o, para que possam reagir
                pEnt->colidir(pInim);
                pInim->colidir(pEnt);
            }
        }
    }

    // ============================================================================
    // Funcoes para gerenciar os conjuntos de entidades
    // ============================================================================

    void GerenciadorDeColisoes::incluirJog(Entidades::Personagens::Jogador* pJog) {
        if (pJog)
            jogadores.insert(pJog);
    }

    void GerenciadorDeColisoes::incluirInim(Entidades::Personagens::Inimigos::Inimigo* pInim) {
        if (pInim)
            inimigos.insert(pInim);
    }

    void GerenciadorDeColisoes::incluirObst(Entidades::Obstaculos::Obstaculo* pObst) {
        if (pObst)
        
            obstaculos.insert(pObst);
    }

  

    void GerenciadorDeColisoes::limparEntidades() {
        jogadores.clear();
        inimigos.clear();
        obstaculos.clear();
      
    }

    void GerenciadorDeColisoes::removerEnt(Entidades::Entidade* pEnt) {
        ID id = pEnt->getID();

        if (id==inimigo) {
           Entidades::Personagens::Inimigos::Inimigo* aux =dynamic_cast<Entidades::Personagens::Inimigos::Inimigo*>(pEnt);

            inimigos.erase(aux);

        }
        else if (id==jogador) {
            Entidades::Personagens::Jogador* aux = dynamic_cast<Entidades::Personagens::Jogador*>(pEnt);
            jogadores.erase(aux);
        }

       
    }

}