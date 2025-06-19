#pragma once
#include "Lista.h"

namespace Entidades {
	namespace Personagens {
		class Jogador;
	}
}
namespace Lista {
	class ListaDeEntidades
	{
	private:
		Lista<Entidades::Entidade*> listaEntidades;
	public:
		ListaDeEntidades();
		~ListaDeEntidades();
		void adicionarEntidade(Entidades::Entidade* pEntidade);
		void removerEntidade(Entidades::Entidade* pEntidade);
		int getTam() const;
		void executar(float dt);
		Lista<Entidades::Entidade*>::Iterator begin();
		Lista<Entidades::Entidade*>::Iterator end();
	};
}
