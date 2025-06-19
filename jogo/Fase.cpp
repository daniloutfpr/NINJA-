#include "Fase.h"

namespace Fases {

    //Gerenciadores::GerenciadorGrafico* Fase::pGrafico = nullptr;
   
    Fase::Fase() :
        entidadesMoveis(nullptr),
        entidadesEstaticas(nullptr),
        pGrafico(nullptr),
        imagemMapa(nullptr),
        spriteMapa(nullptr)
    {
        entidadesMoveis = new Lista::ListaDeEntidades();
        entidadesEstaticas = new Lista::ListaDeEntidades();
        pGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();
        imagemMapa = new sf::RectangleShape(sf::Vector2f(1024.0f, 768.0f));
        spriteMapa = new ElementosGraficos::Animacao(imagemMapa, Math::CoordF(1, 1));
        criarFase("mapa_floresta.json");
        spriteMapa->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::mapa, "mapa_floresta.png", 1);
        //Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador();
        //ntidadesMoveis->adicionarEntidade(jogador);
    }

   

    Fase::~Fase() {
    
        if (entidadesMoveis) {
            delete entidadesMoveis;
            entidadesMoveis = nullptr;
        }
        if (entidadesEstaticas) {
            delete entidadesEstaticas;
            entidadesEstaticas = nullptr;
        }
        if (imagemMapa) {
            delete imagemMapa;
            imagemMapa = nullptr;
        }
        if (spriteMapa) {
            delete spriteMapa;
            spriteMapa = nullptr;
        }
    }

    void Fase::criarFase(const char* caminho_arquivo) {
        std::ifstream file(caminho_arquivo);
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo: " << caminho_arquivo << std::endl;
            return;
        }

        json tmjData;

        try {
            file >> tmjData;
        }
        catch (const std::exception& e) {
            std::cerr << "Erro ao processar JSON: " << e.what() << std::endl;
            return;
        }

        int width = tmjData["width"];
        int height = tmjData["height"];
        int indice = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int value = tmjData["layers"][1]["data"][indice++];
                float posx = 32 * x;
                float posy = 32 * y;
                switch (value) {
                case 0: {
                    break;
                }
                case 1: {
                    Entidades::Obstaculos::Plataforma* tmp = nullptr;
                    tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(posx, posy), sf::Vector2f(32.0f, 32.0f), ID::plataforma);
                    if (tmp) {
                        std::cout << "tmp plataforma existe" << std::endl;
                        entidadesEstaticas->adicionarEntidade(tmp);
                    }
                    break;
                }
                case 2: {
                    Entidades::Personagens::Jogador* tmp = nullptr;
                    tmp = new Entidades::Personagens::Jogador(sf::Vector2f(posx, posy), sf::Vector2f(0.1f, 0.1f), ID::jogador);
                    if (tmp) {
                        std::cout << "tmp player existe" << std::endl;
                        entidadesMoveis->adicionarEntidade(tmp);
                    }
                }
                }
            }
        }
    }
    
    void Fase::executar() {
       //imagemMapa->setOrigin(0.0f, 0.0f);
        //entidadesMoveis->adicionarEntidade(jogador);
        spriteMapa->atualizar(ElementosGraficos::ID_Animacao::mapa, false, (0.0f, 0.0f), pGrafico->getDeltaTempo());
        pGrafico->renderizar(imagemMapa);
        pGrafico->centralizarCam(Math::CoordF(imagemMapa->getPosition().x/2.0f,imagemMapa->getPosition().y/2.0f));
        entidadesMoveis->executar(pGrafico->getDeltaTempo());
        entidadesEstaticas->executar(pGrafico->getDeltaTempo());
            
    }

   // Lista::ListaDeEntidades* Fase::getListaEntidades() {
     //   return 
  //  }
}

