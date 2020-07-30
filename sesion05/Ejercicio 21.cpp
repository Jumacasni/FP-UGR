/*
Se pide leer un car�cter desde teclado, obligando al usuario a que sea una letra may�scula.
Para ello, habr� que usar una estructura repetitiva do while, de forma que
si el usuario introduce un car�cter que no sea una letra may�scula, se le volver� a
pedir otro car�cter. Calculad la min�scula correspondiente e imprimidla en pantalla.
No pueden usarse las funciones tolower ni toupperde la biblioteca cctype.
*/

#include <iostream>

using namespace std;

int main(){
	
	char caracter, minuscula;
	
	do{
		cout << "Introduzca un car�cter: ";
		cin >> caracter;
	}while (caracter < 'A' || caracter > 'Z');
	
	minuscula = 'a' + (caracter - 'A');
	
	cout << "\nLa letra en min�scula es " << minuscula;
}
