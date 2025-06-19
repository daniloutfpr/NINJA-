#include "Animacao.h"

namespace ElementosGraficos {

    const float Animacao::AnimacaoUnica::tempoTroca = 0.15f;

    Gerenciadores::GerenciadorGrafico* Animacao::pGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();

    Animacao::Animacao(sf::RectangleShape* corpo, Math::CoordF escala) :
        corpo(corpo),
        mapaAnimacoes(),
        idAtual(ID_Animacao::idle) {
        corpo->setScale(sf::Vector2f(escala.x, escala.y));
    }

    Animacao::~Animacao() {
        std::map<ID_Animacao, AnimacaoUnica*>::iterator it;
        for (it = mapaAnimacoes.begin(); it != mapaAnimacoes.end(); ++it)
            delete(it->second);

        mapaAnimacoes.clear();
    }

    void Animacao::adicionarNovaAnimacao(ID_Animacao id, const char* caminho, unsigned int contadorImagem) {
        AnimacaoUnica* tmp = new AnimacaoUnica(caminho, contadorImagem);

        if (tmp == NULL) {
            std::cout << "ERRO: Não foi possível criar a animação em Animacao::adicionarNovaAnimacao" << std::endl;
            exit(1);
        }

        mapaAnimacoes.insert(std::pair<ID_Animacao, AnimacaoUnica*>(id, tmp));

        sf::IntRect tamRetangulo = tmp->getTamanho();
        corpo->setSize(sf::Vector2f((float)tamRetangulo.width, (float)tamRetangulo.height));
        corpo->setOrigin(sf::Vector2f((float)tamRetangulo.width, (float)tamRetangulo.height) / 2.0f);
    }

    void Animacao::atualizar(ID_Animacao id, bool olhandoParaEsquerda, Math::CoordF posicao, float dt) {
        if (idAtual != id) {
            idAtual = id;
            if (mapaAnimacoes[idAtual])
                mapaAnimacoes[idAtual]->resetar();
        }
        if (mapaAnimacoes[idAtual]) {
            mapaAnimacoes[idAtual]->atualizar(dt, olhandoParaEsquerda, id);
            corpo->setPosition(sf::Vector2f(posicao.x, posicao.y));
            corpo->setTextureRect(mapaAnimacoes[idAtual]->getTamanho());
            corpo->setTexture(mapaAnimacoes[idAtual]->getTextura());
        }
    }

    Math::CoordF Animacao::getTamanho() const {
        return Math::CoordF(corpo->getSize().x, corpo->getSize().y);
    }
}
