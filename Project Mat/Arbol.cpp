#include "Arbol.h"

void Arbol::CrearArbol(string Operacion, bool & Sigue)
{
	Raiz = new Nodo(Operacion, Sigue);
}
