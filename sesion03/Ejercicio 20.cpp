/*
		Dise�ar un programa que lea un car�cter (supondremos que el usuario introduce una may�scula), lo pase a min�scula y lo imprima en pantalla. Hacedlo sin usar las funciones
	toupper ni tolower de la biblioteca cctype. Para ello, debe considerarse la equivalencia en C++ entre los tipos enteros y caracteres.
*/

#include <iostream>	// Inclusi�n de recursos E/S
#include <string>		// Inclusi�n de caracteres

using namespace std;

int main(){
	
	char mayuscula;	// Variable para guardar la letra may�sula
	char minuscula; 
	
	cout << "Introduzca la letra may�scula: ";
	cin >> mayuscula;

	minuscula = 'a' + (mayuscula - 'A');

	cout << "\nEn min�scula: " << minuscula;
}
	
	
