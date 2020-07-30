/*
	Modificad las soluciones de los ejercicios 3 y 5 para que no se mezclen E/S y C
(entradas/salidas y c�mputos) dentro de la misma estructura condicional.
*/

#include <iostream>	// Inclusi�n de recursos de E/S

using namespace std;

int main() {
	
	int entero1, entero2, entero3;
	bool numeros_ordenados;
	
	cout << "Introduzca el entero 1: ";
	cin >> entero1;
	cout << "Introduzca el entero 2: ";
	cin >> entero2;
	cout << "Introduzca el entero 3: ";
	cin >> entero3;
	
	numeros_ordenados = (entero1 > entero2 && entero2 > entero3) || (entero1 < entero2 && entero2 < entero3);
	
	if (numeros_ordenados)
		
		cout << "\nLos n�meros est�n ordenados.";
		
	else
	
		cout << "\nLos n�meros no est�n ordenados.";
}
