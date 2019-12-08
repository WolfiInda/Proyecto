#pragma once
#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;

class Arbol
{
public:
	void CrearArbol(string Operacion, bool & Sigue);
	Nodo * Raiz;
};

