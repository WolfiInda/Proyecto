#include "Nodo.h"
#include <tuple>
#include <vector>

Nodo::Nodo(string Operacion, bool & Sigue)
{
	int ParentesisDentro = 0, Parentesis = 0;
	bool Par = false;
	for (int j = 0; j < Operacion.size(); j++) {
		if (Operacion[j] == '(') {
			Parentesis++;
			Par = true;
		}
		if (Operacion[j] == ')')
			Parentesis--;
		if (Par && Parentesis == 0) {
			ParentesisDentro++;
			Par = false;
		}
	}
	if (ParentesisDentro == 1 && Operacion[0] == '(' && Operacion[Operacion.size() - 1] == ')')
		Operacion = Operacion.substr(1, Operacion.size() - 2);
	vector<tuple<int, int, char>> Operadores;
	if (Operacion.size() == 1) {
		if (Operacion[0] >= 65 && Operacion[0] <= 90)
			Valor = Operacion[0];
		else
			Sigue = false;
	}
	else if (Sigue) {
		int Parentesis = 0;
		for (int i = 0; i < Operacion.size(); i++) {
			if (Operacion[i] == '(')
				Parentesis++;
			else if (Operacion[i] == ')')
				Parentesis--;
			else if (Parentesis == 0) {
				if (Operacion[i] == '-') {
					if (i != 0 && i != Operacion.size() - 1 && (Operacion[i - 1] != '-' && Operacion[i - 1] != '+' && Operacion[i - 1] != '*' && Operacion[i + 1] != '-' && Operacion[i + 1] != '+' && Operacion[i + 1] != '*' && Operacion[i + 1] != '^'))
						Operadores.push_back(make_tuple(i, 0, '-'));
					else {
						Sigue = false;
						break;
					}
				}
				else if (Operacion[i] == '+') {
					if (i != 0 && i != Operacion.size() - 1 && (Operacion[i - 1] != '-' && Operacion[i - 1] != '+' && Operacion[i - 1] != '*' && Operacion[i + 1] != '-' && Operacion[i + 1] != '+' && Operacion[i + 1] != '*' && Operacion[i + 1] != '^'))
						Operadores.push_back(make_tuple(i, 0, '+'));
					else {
						Sigue = false;
						break;
					}
				}
				else if (Operacion[i] == '*') {
					if (i != 0 && i != Operacion.size() - 1 && (Operacion[i - 1] != '-' && Operacion[i - 1] != '+' && Operacion[i - 1] != '*' && Operacion[i + 1] != '-' && Operacion[i + 1] != '+' && Operacion[i + 1] != '*' && Operacion[i + 1] != '^'))
						Operadores.push_back(make_tuple(i, 1, '*'));
					else {
						Sigue = false;
						break;
					}
				}
				else if (Operacion[i] == '^') {
					if (i != 0 && (Operacion[i - 1] != '-' && Operacion[i - 1] != '+' && Operacion[i - 1] != '*' && !(Operacion[i + 1] >= 'A' && Operacion[i + 1] <= 'Z')) && Operacion[i + 1] != '(')
						Operadores.push_back(make_tuple(i, 2, '^'));
					else {
						Sigue = false;
						break;
					}
				}
			}
			else if (Parentesis < 0) {
				Sigue = false;
				break;
			}
		}
		if (Parentesis != 0 || Operadores.size() == 0)
			Sigue = false;
	}
	if (Sigue) {
		int Menor = 5;
		for (int i = 0; i < Operadores.size(); i++) {
			if (Menor > get<1>(Operadores[i]))
				Menor = get<1>(Operadores[i]);
		}
		for (int i = Operadores.size() - 1; i > -1; i--) {
			if (get<1>(Operadores[i]) == Menor) {
				string SubStringIzquierdo = "", SubStringDerecho = "";
				int ParentesisIzquierda = 0, ParentesisDerecha = 0, Parentesis = 0;
				bool Par = false;
				for (int j = 0; j < get<0>(Operadores[i]); j++) {
					SubStringIzquierdo += Operacion[j];
					if (Operacion[j] == '(') {
						Parentesis++;
						Par = true;
					}
					if (Operacion[j] == ')')
						Parentesis--;
					if (Par && Parentesis == 0) {
						ParentesisIzquierda++;
						Par = false;
					}
				}
				for (int j = get<0>(Operadores[i]) + 1; j < Operacion.size(); j++) {
					SubStringDerecho += Operacion[j];
					if (Operacion[j] == '(') {
						Parentesis++;
						Par = true;
					}
					if (Operacion[j] == ')')
						Parentesis--;
					if (Par && Parentesis == 0) {
						ParentesisDerecha++;
						Par = false;
					}
				}
				if (SubStringIzquierdo.size() > 0)
					Izquierdo = new Nodo(SubStringIzquierdo, Sigue);
				if (SubStringDerecho.size() > 0)
					Derecho = new Nodo(SubStringDerecho, Sigue);
				Valor = get<2>(Operadores[i]);
				break;
			}
		}
	}
}