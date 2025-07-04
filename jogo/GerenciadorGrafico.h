#pragma once
#include "Coord.h"
//gerenciador grafico deve ser singleton por eu querer apenas uma instancia dele no meu jogo 
//(Isaaque) estudar esse padrao de projeto depois

namespace Gerenciadores {
#define ALTURA_JANELA 768.0f
#define LARGURA_JANELA 1024.0f
	class GerenciadorGrafico
	{	
	private:

		sf::RenderWindow* pJanela;
		sf::View camera;
		//ainda vai ser necessario um mapa de texturas
		unordered_map<std::string, sf::Texture*> texturas;
		//e uma fonte
		sf::Clock relogio;
		static float dt;

		//singleton
		static Gerenciadores::GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();
	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getInstancia();
		void renderizar(sf::RectangleShape* corpo);
		void display();
		bool janelaAberta()const ;
		void limpar();	
		void fecharJanela();
		void centralizarCam(Math::CoordF pos);
		void atualizaDeltaTempo();
		const float getDeltaTempo() const;
		bool evGraficos(sf::Event &e);
		sf::Texture* carregarTextura(const char* caminho);
		sf::RenderWindow* getJanela();
		Math::CoordUI getTamJanela() const;
		sf::Vector2f getCentroCam() const;
		sf::Vector2f getCameraPos() const;


	};
}

