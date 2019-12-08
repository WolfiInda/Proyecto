#include "Calculadora.h"

Calculadora::Calculadora()
{
	universo = Universo::getInstance();
}

//set<string> Calculadora::Calcular(string Operacion, bool & Sigue)
Conjunto Calculadora::Calcular(string Operacion, bool & Sigue)
{
	set<string> Resultado;
	ArbolDeOperaciones.CrearArbol(Operacion, Sigue);
	universo->SetearUniverso(Conjuntos);
	if (Sigue)
		return Operaciones(ArbolDeOperaciones.Raiz, Sigue);
	return Conjunto();
}

//set<string> Calculadora::Operaciones(Nodo * SubArbol, bool & Sigue)
Conjunto Calculadora::Operaciones(Nodo * SubArbol, bool & Sigue)
{
	if (SubArbol->Valor == '^')
		return Complemento(Operaciones(SubArbol->Izquierdo, Sigue));
	else if (SubArbol->Valor == '*')
		return Interseccion(Operaciones(SubArbol->Izquierdo, Sigue), Operaciones(SubArbol->Derecho, Sigue));
	else if (SubArbol->Valor == '+')
		return Union(Operaciones(SubArbol->Izquierdo, Sigue), Operaciones(SubArbol->Derecho, Sigue));
	else if (SubArbol->Valor == '-')
		return Diferencia(Operaciones(SubArbol->Izquierdo, Sigue), Operaciones(SubArbol->Derecho, Sigue));
	else if ((SubArbol->Valor >= 65 && SubArbol->Valor <= 90) && Conjuntos.find(SubArbol->Valor) != Conjuntos.end())
		return Conjuntos[SubArbol->Valor];
	else
		Sigue = false;
	return Conjunto();
}

//set<string> Calculadora::Union(set<string> a, set<string> b)
Conjunto Calculadora::Union(Conjunto a, Conjunto b)
{
	Conjunto R;
	for (string N : a.Conjunt)
		R.Conjunt.insert(N);
	for (string N : b.Conjunt)
		R.Conjunt.insert(N);
	return R;
}

//set<string> Calculadora::Interseccion(set<string> a, set<string> b)
Conjunto Calculadora::Interseccion(Conjunto a, Conjunto b)
{
	Conjunto R;
	for (string N : a.Conjunt) {
		if (b.Conjunt.find(N) != b.Conjunt.end())
			R.Conjunt.insert(N);
	}
	return R;
}

//set<string> Calculadora::Diferencia(set<string> a, set<string> b)
Conjunto Calculadora::Diferencia(Conjunto a, Conjunto b)
{
	Conjunto R;
	for (string N : a.Conjunt) {
		if (b.Conjunt.find(N) == b.Conjunt.end())
			R.Conjunt.insert(N);
	}
	return R;
}

//set<string> Calculadora::Complemento(set<string> a)
Conjunto Calculadora::Complemento(Conjunto a)
{
	Conjunto R;
	for (string N : universo->ConjuntoU.Conjunt) {
		if (a.Conjunt.find(N) == a.Conjunt.end())
			R.Conjunt.insert(N);
	}
	return R;
}
