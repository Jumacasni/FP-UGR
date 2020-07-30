/*
Calcular mediante un programa en C++ la funci�n potencia x^n, y la funci�n factorial
n! con n un valor entero y x un valor real. No pueden usarse las funciones de la
biblioteca cmath.
*/

#include <iostream>

using namespace std;

int main(){
	
	double numero_real, copia_numero_real, factorial;
	int numero_n, copia_numero_n, contador;
	
	cout << "Introduzca un n�mero real (base): ";
	cin >> numero_real;
	cout << "Introduzca un n�mero entero positivo (exponente): ";
	cin >> numero_n;
	
	while(numero_n < 0){
		cout << "Introduzca un n�mero entero positivo (exponente): ";
		cin >> numero_n;
	}
	
	copia_numero_n = numero_n;
	
	// FUNCI�N POTENCIA //
	
	copia_numero_real = numero_real;
	if (numero_n == 0)
		cout << "\nLa funci�n potencia es igual a 1";
	
	else{
		for(contador = numero_n ; contador > 1 ; contador--){

			copia_numero_real = numero_real * copia_numero_real;
	}
	
	cout << "\nLa funci�n potencia es igual a " << copia_numero_real;
}

	// FUNCI�N FACTORIAL //
	
	if(copia_numero_n == 0)
		cout << "\nLa funci�n factorial es 1";
		
	else{
	
		factorial = copia_numero_n - 1;
		for(contador = factorial ; contador > 1 ; contador--){
			
			copia_numero_n = copia_numero_n * factorial;
			factorial--;
		}

		cout << "\nLa funci�n factorial es igual a " << copia_numero_n;
	}		 
		
}
	
	
	
	
