#pragma once
#include "GerenciadorDeEventos.h"
#include <nlohmann/json.hpp>
#include <fstream>   // Para usar std::ifstream (leitura de arquivos)
#include <iostream>  // Para usar std::cout e std::cerr (sa�da no console)
using json = nlohmann::json;

namespace Fases {
	class Fase
	{
	protected:
		sf::RectangleShape* imagemMapa;
		ElementosGraficos::Animacao* spriteMapa;
		Lista::ListaDeEntidades* lJogadores;
		Lista::ListaDeEntidades* lObstaculos;
		Lista::ListaDeEntidades* lInimigos;
		Entidades::Personagens::Jogador* pJogador1;
		Entidades::Personagens::Jogador* pJogador2;
		Gerenciadores::GerenciadorGrafico* pGrafico;
		Gerenciadores::GerenciadorDeColisoes* pColisoes;
		Entidades::Personagens::Jogador* pJogador;

	public:
		Fase();
		virtual ~Fase();
		void criarFase(const char* caminho_arquivo);
		Lista::ListaDeEntidades* getListaEntidades();
		void executar();

	};
}

