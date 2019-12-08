#pragma once
#include <set>
#include <string>
#include <iostream>
using namespace std;
class Conjunto
{
public:
	Conjunto(){}
	Conjunto(string a);
	set<string> Conjunt;
	static bool AgregarConjunto(string a);
};

