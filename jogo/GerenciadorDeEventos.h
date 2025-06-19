#pragma once
#include "GerenciadorDeInput.h"
namespace Gerenciadores {
	class GerenciadorDeEventos
	{
	private:
		 GerenciadorGrafico* pGrafico;
		 GerenciadorDeInput* pInput;
		static GerenciadorDeEventos* pEventos;

		GerenciadorDeEventos();
	public:
		~GerenciadorDeEventos();
		static GerenciadorDeEventos* getInstancia();
		void verificaEvento();
	};
}
