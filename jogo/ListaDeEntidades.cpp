#include "ListaDeEntidades.h"
#include "Jogador.h"
namespace Lista{
	
	ListaDeEntidades::ListaDeEntidades():listaEntidades() {}
	ListaDeEntidades::~ListaDeEntidades(){}

	void ListaDeEntidades::adicionarEntidade(Entidades::Entidade* pEntidade) {
		if (pEntidade) {
			listaEntidades.incluir(pEntidade);
		}
		else
			std::cout << "Erro na Entidade Nula Passada na Lista!" << endl;
	}

	void ListaDeEntidades::removerEntidade(Entidades::Entidade* pEntidade) {
		if (!pEntidade) {
			std::cout << "Erro na Entidade Nula Passada na Lista!" << std::endl;
			return;
		}
		else
			listaEntidades.remover(pEntidade);
	}

	int ListaDeEntidades::getTam()const {
		return listaEntidades.getTamanho();
	}

	void ListaDeEntidades::executar(float dt) {
		for (auto it = listaEntidades.begin(); it != listaEntidades.end(); ++it) {
			Entidades::Entidade* e = *it;



			if (e) {
				if (Entidades::Personagens::Jogador* player = dynamic_cast<Entidades::Personagens::Jogador*> (e)) {
					//std::cout <<"player executando" << std::endl;
				}
				e->renderiza();
				e->executar();
			}
		}
	}

	Lista<Entidades::Entidade*>::Iterator ListaDeEntidades::begin() {
		return listaEntidades.begin();
	}

	Lista<Entidades::Entidade*>::Iterator ListaDeEntidades::end() {
		return listaEntidades.end();
	}
}