#pragma once
#include <iostream>
#include <string>
using namespace std;

class Nodo
{
public:
	Nodo(string Operacion, bool & Sigue);
	Nodo * Derecho;
	Nodo * Izquierdo;
	char Valor;
};