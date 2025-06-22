#pragma once
#include <SFML/System/Vector2.hpp>
#include <list>
#include <vector>
#include "Mediator.h"
#include "Jogador.h"
#include"Inimigo.h"
#include "Obstaculo.h"


namespace Gerenciadores {
	//gerenciador singleton
		class GerenciadorColisoes : public Mediator {
		private:
			static GerenciadorColisoes* instancia;

			std::set<Entidades::Personagens::Jogador*> jogadores;
			std::set<Entidades::Personagens::Inimigo*> inimigos;
			std::set<Entidades::Obstaculos::Obstaculo*> obstaculos;
			//std::set<Entidades::Projetil*> projeteis;

		private:
			GerenciadorColisoes();
			~GerenciadorColisoes();
			GerenciadorColisoes(const GerenciadorColisoes&) = delete;
			GerenciadorColisoes& operator=(const GerenciadorColisoes&) = delete;

			// Funcoes para verificar colisoes de cada caso de entidade
			void verificarProj(Entidades::Entidade* pEnt);
			void verificarInim(Entidades::Entidade* pEnt);
			void verificarJog(Entidades::Entidade* pEnt);

			// Funcoes auxiliares
			float calcOverlapVert(const Entidades::Entidade* e1, const Entidades::Entidade* e2) const;
			float calcOverlapHor(const Entidades::Entidade* e1, const Entidades::Entidade* e2) const;
			bool colidiu(const Entidades::Entidade* e1, const Entidades::Entidade* e2) const;
			bool colidiuVertical(const Entidades::Entidade* e1, const Entidades::Entidade* e2) const;
			bool colidiuHorizontal(const Entidades::Entidade* e1, const Entidades::Entidade* e2) const;

			// ============================================================================
			// Interface publica
			// ============================================================================

		public:
			static GerenciadorColisoes* getInstancia();

			void notificar(Entidades::Entidade* sender);

			sf::Vector2f calcOverlap(const Entidades::Entidade* e1, const Entidades::Entidade* e2) const;
			void limparEntidades();

			void incluirJog(Entidades::Personagens::Jogador* pJog);
			void incluirInim(Entidades::Personagens::Inimigo* pInim);
			void incluirObst(Entidades::Obstaculos::Obstaculo* pObst);
			//void incluirProj(Entidades::Projetil* pProj);
			void removerEnt(Entidades::Entidade* pEnt);
	};
}

