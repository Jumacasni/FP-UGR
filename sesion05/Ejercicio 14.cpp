/*
	Modificad las soluciones de los ejercicios 3 y 5 para que no se mezclen E/S y C
(entradas/salidas y cómputos) dentro de la misma estructura condicional.
*/

#include <iostream>	// Inclusión de recursos de E/S

using namespace std;

enum class NumerosOrdenados
	{numeros_ordenados_ascendente, numeros_ordenados_descendente, numeros_no_ordenados};

int main() {
	
	int entero1, entero2, entero3;
	bool ascendente, descendente;
	NumerosOrdenados numeros_ordenados;
	
	cout << "Introduzca el entero 1: ";
	cin >> entero1;
	cout << "Introduzca el entero 2: ";
	cin >> entero2;
	cout << "Introduzca el entero 3: ";
	cin >> entero3;
	
	descendente = entero1 > entero2 && entero2 > entero3;
	ascendente = entero1 < entero2 && entero2 < entero3;
	
	if (descendente)
		
			numeros_ordenados = NumerosOrdenados::numeros_ordenados_descendente;
			
	else

		if (ascendente)
		
			numeros_ordenados = NumerosOrdenados::numeros_ordenados_ascendente;
			
		else
		
			numeros_ordenados = NumerosOrdenados::numeros_no_ordenados;
	
	if (numeros_ordenados == NumerosOrdenados::numeros_ordenados_descendente)
	
		cout << "\nLos números están ordenados de forma descendente.";
	
	if (numeros_ordenados == NumerosOrdenados::numeros_ordenados_ascendente)
		
		cout << "\nLos números están ordenados de forma ascendente.";
	
	if (numeros_ordenados == NumerosOrdenados::numeros_no_ordenados)
		
		cout << "\nLos números no están ordenados.";	
}
