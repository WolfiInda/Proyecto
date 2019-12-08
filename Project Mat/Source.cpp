#include <iostream>
#include <set>
#include <map>
#include <string>
#include "Calculadora.h"
#include "Instrucciones.h"
using namespace std;

string QuitarEspacios(string a) {
	string b = "";
	for (char c : a) {
		if (c != ' ')
			b += c;
	}
	return b;
}
int main()
{
	Instrucciones instruccion;
	Calculadora calculator;
	instruccion.Instrucc();
	while (true) {
		string a, c;
		std::getline(std::cin, a);
		c = QuitarEspacios(a);

		if (c[0] >= 65 && c[0] <= 90 && c[1] == '=' && c[2] == '{' && c[c.size() - 1] == '}') {
			if (Conjunto::AgregarConjunto(c))
			calculator.Conjuntos[c[0]] = Conjunto(c);
		}
		else {
			bool Sigue = true;
			int b = 0;
			Conjunto Resultado = calculator.Calcular(c, Sigue);
			if (Sigue) {
				cout << "R={";
				for (string N : Resultado.Conjunt) {
					b++;
					cout << N;
					if (b < Resultado.Conjunt.size())
						cout << ",";
				}
				cout << "}" << endl;
			}
			else
				cout << "Expresion no valida" << endl;
		}
	}
}