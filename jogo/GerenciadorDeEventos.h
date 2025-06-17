#pragma once
#include "GerenciadorDeInput.h"
namespace Gerenciadores {
	class GerenciadorDeEventos
	{
	private:
		static GerenciadorGrafico* pGrafico;
		static GerenciadorDeInput* pInput;
		static GerenciadorDeEventos* pEventos;

		GerenciadorDeEventos();
	public:
		~GerenciadorDeEventos();
		static GerenciadorDeEventos* getInstancia();
		void verificaEvento();
	};
}
