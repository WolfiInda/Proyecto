#include "Conjunto.h"
Conjunto::Conjunto(string a)
{
	string Valor = "";
	set<string> Nuevo;
	for (int i = 3; i < a.size() - 1; i++) {
		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= '0' && a[i] <= '9'))
			Valor += a[i];
		else if (a[i] == ',' && Valor != "") {
			Nuevo.insert(Valor);
			Valor = "";
		}
	}
	if (Valor != "")
		Nuevo.insert(Valor);
	Conjunt = Nuevo;
}

bool Conjunto::AgregarConjunto(string a)
{
	string Valor = "";
	for (int i = 3; i < a.size() - 1; i++) {
		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= '0' && a[i] <= '9')) 
			Valor += a[i];
		else if (a[i] == ',' && Valor != "") {
			Valor = "";
		}
		else {
			cout << "Conjunto no valido" << endl;
			return false;
		}
	}
	if (Valor == ""){
		cout << "Conjunto no valido" << endl;
		return false;
	}
	return true;
}
