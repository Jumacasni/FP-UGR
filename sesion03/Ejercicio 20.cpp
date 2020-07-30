/*
		Diseñar un programa que lea un carácter (supondremos que el usuario introduce una mayúscula), lo pase a minúscula y lo imprima en pantalla. Hacedlo sin usar las funciones
	toupper ni tolower de la biblioteca cctype. Para ello, debe considerarse la equivalencia en C++ entre los tipos enteros y caracteres.
*/

#include <iostream>	// Inclusión de recursos E/S
#include <string>		// Inclusión de caracteres

using namespace std;

int main(){
	
	char mayuscula;	// Variable para guardar la letra mayúsula
	char minuscula; 
	
	cout << "Introduzca la letra mayúscula: ";
	cin >> mayuscula;

	minuscula = 'a' + (mayuscula - 'A');

	cout << "\nEn minúscula: " << minuscula;
}
	
	
