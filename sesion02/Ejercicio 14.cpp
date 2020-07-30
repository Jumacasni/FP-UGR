/*
	Programa para escribir dígitos separados por espacios
*/

#include <iostream>	// Inclusión de recursos de E/S
using namespace std;

int main (){
	
	int numero;		// Declaración de variable para guardar el número
	int digito1;	// Declaración de variables para guardar las cifras del número	
	int digito2;
	int digito3;
		
	cout << "Introduzca el dígito: ";
	cin >> numero;
	
	digito1 = numero / 100;
	
	digito2 = (numero % 100) / 10;
	
	digito3 = numero % 10;
	
	cout << "\nEl numero separado por tres espacios es " << digito1 << "   " << digito2 << "   " << digito3;
}
	
	
	
	
