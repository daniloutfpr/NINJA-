#include "Fase.h"

namespace Fases {

    //Gerenciadores::GerenciadorGrafico* Fase::pGrafico = nullptr;
   
    Fase::Fase() :
        lJogadores(nullptr),
        lObstaculos(nullptr),
        pGrafico(nullptr),
        imagemMapa(nullptr),
        spriteMapa(nullptr),
        pColisoes(nullptr),
        pJogador(nullptr)
    {
        lJogadores = new Lista::ListaDeEntidades();
        lObstaculos = new Lista::ListaDeEntidades();
        pGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();
        pColisoes = Gerenciadores::GerenciadorDeColisoes::getInstancia();


        
        imagemMapa = new sf::RectangleShape(sf::Vector2f(1024.0f, 768.0f));
        imagemMapa->setOrigin(sf::Vector2f(0.0f,0.0f));
        spriteMapa = new ElementosGraficos::Animacao(imagemMapa, Math::CoordF(1, 1));
        spriteMapa->adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::mapa, "mapa_floresta.png", 1);


       
        criarFase("mapa_floresta.json");
            
            //sf::Vector2f tamanhoMapa = imagemMapa->getSize();

            // Calcula o ponto central do mapa
            //sf::Vector2f centroDoMapa(tamanhoMapa.x / 2.0f, tamanhoMapa.y / 2.0f);
            //Math::CoordF centroParaCamera(centroDoMapa.x, centroDoMapa.y);

            // Manda o Gerenciador Gráfico centralizar a câmera neste ponto fixo
           // pGrafico->centralizarCam(centroParaCamera);
        
        //entidadesMoveis->adicionarEntidade(jogador);
    }

   

    Fase::~Fase() {
    
        if (lJogadores) {
            delete lJogadores;
            lJogadores = nullptr;
        }
        if (lObstaculos) {
            delete lObstaculos;
            lObstaculos = nullptr;
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

        int width = 32;
        int height = 24;
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
                       
                        lObstaculos->adicionarEntidade(tmp);
                        pColisoes->incluirObst(tmp);
                       // std::cout << "PLataforma criada e adicionada!" << std::endl;
                      
                    }
                    break;
                }
                case 2: {
                    Entidades::Personagens::Jogador* tmp = nullptr;
                    tmp = new Entidades::Personagens::Jogador(sf::Vector2f(posx, posy), sf::Vector2f(0.3f, 0.3f), ID::jogador);
                    if (tmp) {
                         
                        lJogadores->adicionarEntidade(tmp);
                        this->pJogador = tmp;
                    }
                }
                }

            }
        }
        std::cout << "--- RELATORIO DE CRIACAO DE FASE ---" << std::endl;
        std::cout << "Total de Plataformas criadas: " << lObstaculos->getTam() << std::endl;
        std::cout << "Total de Jogadores/Inimigos criados: " << lJogadores->getTam() << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
    
    void Fase::executar() {
        spriteMapa->atualizar(ElementosGraficos::ID_Animacao::mapa, false, (0.0f, 0.0f), pGrafico->getDeltaTempo());
        
       //if (pJogador) {
        //    pGrafico->centralizarCam(pJogador->getPosition());
     //  }
     
        
        pGrafico->renderizar(imagemMapa);
        lJogadores->executar(pGrafico->getDeltaTempo());
        lObstaculos->executar(pGrafico->getDeltaTempo());
        
    }

   // Lista::ListaDeEntidades* Fase::getListaEntidades() {
     //   return 
  //  }
}

