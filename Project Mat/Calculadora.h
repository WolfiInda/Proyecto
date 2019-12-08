#pragma once
#include <iostream>
#include <set>
#include <map>
#include "Universo.h"
#include "Arbol.h"
#include "Conjunto.h"
using namespace std;

class Calculadora
{
public:
	Calculadora();
	/*set<string> Calcular(string Operacion, bool & Sigue);
	set<string> Operaciones(Nodo * SubArbol, bool & Sigue);
	set<string> Union(set<string> a, set<string> b);
	set<string> Interseccion(set<string> a, set<string> b);
	set<string> Diferencia(set<string> a, set<string> b);
	set<string> Complemento(set<string> a);*/
	Conjunto Calcular(string Operacion, bool & Sigue);
	Conjunto Operaciones(Nodo * SubArbol, bool & Sigue);
	Conjunto Union(Conjunto a, Conjunto b);
	Conjunto Interseccion(Conjunto a, Conjunto b);
	Conjunto Diferencia(Conjunto a, Conjunto b);
	Conjunto Complemento(Conjunto a);
	Universo * universo;
	//map<char, set<string>> Conjuntos;
	map<char, Conjunto> Conjuntos;
	Arbol ArbolDeOperaciones;
};

