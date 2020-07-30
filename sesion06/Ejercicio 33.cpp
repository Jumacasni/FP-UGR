/*
Calcular mediante un programa en C++ la función potencia x^n, y la función factorial
n! con n un valor entero y x un valor real. No pueden usarse las funciones de la
biblioteca cmath.
*/

#include <iostream>

using namespace std;

int main(){
	
	double numero_real, copia_numero_real, factorial;
	int numero_n, copia_numero_n, contador;
	
	cout << "Introduzca un número real (base): ";
	cin >> numero_real;
	cout << "Introduzca un número entero positivo (exponente): ";
	cin >> numero_n;
	
	while(numero_n < 0){
		cout << "Introduzca un número entero positivo (exponente): ";
		cin >> numero_n;
	}
	
	copia_numero_n = numero_n;
	
	// FUNCIÓN POTENCIA //
	
	copia_numero_real = numero_real;
	if (numero_n == 0)
		cout << "\nLa función potencia es igual a 1";
	
	else{
		for(contador = numero_n ; contador > 1 ; contador--){

			copia_numero_real = numero_real * copia_numero_real;
	}
	
	cout << "\nLa función potencia es igual a " << copia_numero_real;
}

	// FUNCIÓN FACTORIAL //
	
	if(copia_numero_n == 0)
		cout << "\nLa función factorial es 1";
		
	else{
	
		factorial = copia_numero_n - 1;
		for(contador = factorial ; contador > 1 ; contador--){
			
			copia_numero_n = copia_numero_n * factorial;
			factorial--;
		}

		cout << "\nLa función factorial es igual a " << copia_numero_n;
	}		 
		
}
	
	
	
	
