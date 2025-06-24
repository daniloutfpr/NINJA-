#pragma once
#include "Ente.h"

// C�digo baseado no reposit�rio "Desert" de Matheus Burda
// Reposit�rio: https://github.com/MatheusBurda/Desert
// Licen�a: MIT
// 
// Conforme a licen�a MIT, este c�digo pode ser usado, modificado e distribu�do,
// desde que a atribui��o ao autor original seja mantida.

namespace ElementosGraficos {

	enum ID_Animacao {
		idle = 0,
		mapa ,
		arbusto , 
		fogueira ,
		atacando ,
		morto ,
	};

	class Animacao {
	private:
		class AnimacaoUnica {
		private:
			const unsigned int contadorImagem;
			unsigned int imagemAtual;
			sf::Texture* textura;
			float tempoTotal;
			sf::IntRect tamRetangulo;
			static const float tempoTroca;
			static const float tempoTrocaAtaque;

		public:
			AnimacaoUnica(const char* caminho, const unsigned int contadorImagem) :
				contadorImagem(contadorImagem),
				imagemAtual(0),
				textura(pGrafico->carregarTextura(caminho)),
				tempoTotal(0.0f),
				tamRetangulo() {
				if (textura == NULL) {
					std::cout << "ERRO: Falha ao carregar textura em AnimacaoUnica::AnimacaoUnica()." << std::endl;
					exit(1);
				}
				if (textura) {
					tamRetangulo.width = textura->getSize().x / float(contadorImagem);
					tamRetangulo.height = textura->getSize().y;
				}
			}

			~AnimacaoUnica() {}

			void atualizar(float dt, bool viradoEsquerda, ID_Animacao id) {
				tempoTotal += dt;

				if (tempoTotal >= tempoTroca) {
					tempoTotal -= tempoTroca;
					imagemAtual++;

					if (imagemAtual >= contadorImagem)
						imagemAtual = 0;
				}

				if (viradoEsquerda) {
					tamRetangulo.left = (imagemAtual + 1) * abs(tamRetangulo.width);
					tamRetangulo.width = -abs(tamRetangulo.width);
				}
				else {
					tamRetangulo.left = imagemAtual * tamRetangulo.width;
					tamRetangulo.width = abs(tamRetangulo.width);
				}
			}

			void resetar() {
				imagemAtual = 0;
				tempoTotal = 0;
			}

			sf::IntRect getTamanho() const { return tamRetangulo; }
			sf::Texture* getTextura() const { return textura; }
		};

	private:
		sf::RectangleShape* corpo;
		std::map<ID_Animacao, AnimacaoUnica*> mapaAnimacoes;
		ID_Animacao idAtual;

		static Gerenciadores::GerenciadorGrafico* pGrafico;

	public:
		Animacao(sf::RectangleShape* corpo, Math::CoordF escala);
		~Animacao();

		void adicionarNovaAnimacao(ID_Animacao, const char* caminho, unsigned int contadorImagem);
		void atualizar(ID_Animacao id, bool viradoEsquerda, Math::CoordF posicao, float dt);
		Math::CoordF getTamanho() const;
	};

}

