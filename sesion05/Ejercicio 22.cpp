/*
Realizar un programa que lea enteros desde teclado y calcule cuántos se han introducido y cual es el mínimo de dichos valores (pueden ser positivos o negativos). Se
dejará de leer datos cuando el usuario introduzca el valor 0. Realizad la lectura de los enteros dentro de un bucle sobre una única variable llamada dato. 
Es importante controlar los casos extremos, como por ejemplo, que el primer valor leído fuese ya el terminador de entrada (en este caso, el cero).
*/

#include <iostream>

using namespace std;

int main(){
	
	int dato, minimo;
	int numeros = 0;
	
	cout << "Introduzca un número: ";
	cin >> dato;
	
	minimo = dato;

	while(dato != 0){
			
		numeros++;
		
			if (dato < minimo)
			
				minimo = dato;
		
		cout << "Introduzca un número: ";
		cin >> dato;
}			

	cout << "\nHay " << numeros << " número/s";
	
	cout << "\nEl mínimo de los números es el " << minimo;
}

	
	
