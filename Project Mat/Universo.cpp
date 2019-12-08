#include "Universo.h"

Universo * Universo::Instance = nullptr;
Universo * Universo::getInstance()
{
	if (Instance == nullptr)
		Instance = new Universo();
	return Instance;
}
//void Universo::SetearUniverso(map<char, set<string>> Todo)
void Universo::SetearUniverso(map<char, Conjunto> Todo)
{
	ConjuntoU.Conjunt.clear();
	for (It = Todo.begin(); It != Todo.end(); It++) {
		//for (string N : It->second)
		for (string N : It->second.Conjunt)
			ConjuntoU.Conjunt.insert(N);
	}
}
Universo::Universo()
{
}