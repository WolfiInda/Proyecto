#pragma once
#include <set>
#include <map>
#include <iostream>
#include "Conjunto.h"
using namespace std;

class Universo
{
public:
	static Universo * getInstance();
	//set<string> ConjuntoU;
	Conjunto ConjuntoU;
	//map<char, set<string>>::iterator It;
	map<char, Conjunto>::iterator It;
	//void SetearUniverso(map<char, set<string>> Todo);
	void SetearUniverso(map<char, Conjunto> Todo);
private:
	Universo();
	static Universo * Instance;
};

