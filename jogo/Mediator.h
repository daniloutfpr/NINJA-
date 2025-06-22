#include "Plataforma.h"
namespace Gerenciadores {
	class Mediator {
	private:
		bool ativo;

	public:
		Mediator();
		virtual ~Mediator();
		virtual void notificar(Entidades::Entidade* sender) = 0;
	};
}

