/*
	Escribid un programa en C++ para que lea tres enteros desde teclado y nos diga si
están ordenados (da igual si es de forma ascendente o descendente) o no lo están.
*/

#include <iostream>	// Inclusión de recursos de E/S

using namespace std;

int main() {
	
	int entero1;
	int entero2;
	int entero3;
	
	cout << "Introduzca el entero 1: ";
	cin >> entero1;
	cout << "Introduzca el entero 2: ";
	cin >> entero2;
	cout << "Introduzca el entero 3: ";
	cin >> entero3;
	
	if (entero1 > entero2){
		
		if (entero2 > entero3)
		
			cout << "\nLos números están ordenados.";
			
		else
		
			cout << "\nLos números no estan ordenados.";
}
	if (entero1 < entero2){
		
		if (entero2 < entero3)
		
			cout << "\nLos números están ordenados.";
			
		else
		
			cout << "\nLos números no están ordenados.";
	}
}
