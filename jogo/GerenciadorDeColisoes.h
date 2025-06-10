#pragma once
#include "Obstaculo.h"
namespace Gerenciadores {
	//gerenciador singleton
	class GerenciadorDeColisoes
	{
	private:
		Lista::ListaDeEntidades* entidadesEstaticas;
		Lista::ListaDeEntidades* entidadesMoveis;
		static GerenciadorDeColisoes* pColisao;
		GerenciadorDeColisoes(Lista::ListaDeEntidades* eEstaticas, Lista::ListaDeEntidades* eMoveis);
		GerenciadorDeColisoes();
	public:
		~GerenciadorDeColisoes();
		static GerenciadorDeColisoes* getInstancia();
		void setListas(Lista::ListaDeEntidades* eE, Lista::ListaDeEntidades* eM);
		void notificaColisao(Entidades::Personagens::Personagem* sender,float dt);//no futuro isso tambem tera a parte do projetil
		void trataColisao(Entidades::Personagens::Personagem* sender, Entidades::Entidade* outraEntidade, Math::CoordF interseccao,float dt);
		void moverColisao(Entidades::Personagens::Personagem* sender, Entidades::Entidade* outraEntidade, Math::CoordF interseccao, float dt);
	};
}

