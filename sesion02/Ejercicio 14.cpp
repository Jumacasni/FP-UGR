/*
	Programa para escribir d�gitos separados por espacios
*/

#include <iostream>	// Inclusi�n de recursos de E/S
using namespace std;

int main (){
	
	int numero;		// Declaraci�n de variable para guardar el n�mero
	int digito1;	// Declaraci�n de variables para guardar las cifras del n�mero	
	int digito2;
	int digito3;
		
	cout << "Introduzca el d�gito: ";
	cin >> numero;
	
	digito1 = numero / 100;
	
	digito2 = (numero % 100) / 10;
	
	digito3 = numero % 10;
	
	cout << "\nEl numero separado por tres espacios es " << digito1 << "   " << digito2 << "   " << digito3;
}
	
	
	
	
