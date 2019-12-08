#include "Instrucciones.h"



Instrucciones::Instrucciones()
{

}

void Instrucciones::Instrucc()
{
	cout << "NO USAR ESPACIOS AL DECLARAR CONJUNTOS O HACER OPERACIONES" << endl;
	cout << "====INSTRUCCIONES====" << endl;
	cout << "1.- Definir los conjuntos deseados." << endl;
	cout << "2.- Hacer las operaciones con los operadores deseados." << endl;
	cout << endl;
	cout << "=======EJEMPLO=======" << endl;
	cout << "Defines el primer conjunto" << endl;
	cout << "-U={1,2,3,4}" << endl;
	cout << "Defines el segundo conjuno con otra letra" << endl;
	cout << "-A={3,4,5,6}" << endl;
	cout << "Ahora escoges el operador" << endl;
	cout << "-U+A" << endl;
	cout << "Resultado:" << endl;
	cout << "-R={1,2,3,4,5,6}" << endl;
	cout << endl;
	cout << "====DECLARACIONES====" << endl;
	cout << "N = Declarar con letras mayusculas" << endl;
	cout << "N={Conjunto de numeros o letras minusculas} " << endl;
	cout << endl;
	cout << " =====OPERADORES=====" << endl;
	cout << "-Union = + " << endl;
	cout << "-Interseccion = * " << endl;
	cout << "-Diferencia = - " << endl;
	cout << "-Complemento = ^ " << endl;
	cout << endl;
	cout << "==CAJA DE OPERACIONES==" << endl;
}


Instrucciones::~Instrucciones()
{
}
