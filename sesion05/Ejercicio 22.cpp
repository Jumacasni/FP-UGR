/*
Realizar un programa que lea enteros desde teclado y calcule cu�ntos se han introducido y cual es el m�nimo de dichos valores (pueden ser positivos o negativos). Se
dejar� de leer datos cuando el usuario introduzca el valor 0. Realizad la lectura de los enteros dentro de un bucle sobre una �nica variable llamada dato. 
Es importante controlar los casos extremos, como por ejemplo, que el primer valor le�do fuese ya el terminador de entrada (en este caso, el cero).
*/

#include <iostream>

using namespace std;

int main(){
	
	int dato, minimo;
	int numeros = 0;
	
	cout << "Introduzca un n�mero: ";
	cin >> dato;
	
	minimo = dato;

	while(dato != 0){
			
		numeros++;
		
			if (dato < minimo)
			
				minimo = dato;
		
		cout << "Introduzca un n�mero: ";
		cin >> dato;
}			

	cout << "\nHay " << numeros << " n�mero/s";
	
	cout << "\nEl m�nimo de los n�meros es el " << minimo;
}

	
	
