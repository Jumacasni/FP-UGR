/*
Reescribid la solución del ejercicio 33 (factorial y potencia) de la Relación de Problemas II, modularizándola con funciones.
Para obligar a que el valor leído de n sea positivo, implemente y llame a la función int LeeEnteroPositivo()
*/

#include <iostream>

using namespace std;

		// FUNCIÓN PARA LEER EL NÚMERO ENTERO POSITIVO //
		
int LeeEnteroPositivo(int entero){
	while (entero < 0){
		cout << "Introduzca un número entero positivo (exponente): ";
		cin >> entero;
}
	return entero;
}
		
		// FUNCIÓN POTENCIA //
		
int Potencia(int base_real, int copia_base_real, int exponente){
	
		int contador;
		
		if (exponente == 0)
		
			return 1;
	
		else{
			for(contador = exponente ; contador > 1 ; contador--){

				copia_base_real = base_real * copia_base_real;
		}
		
		return copia_base_real;
}
}

		// FUNCIÓN FACTORIAL //

int Factorial(int numero){
	
	int factorial;
	int contador;
	
	if(numero == 0)
	
		return 1;
		
	else{
	
		factorial = numero - 1;
		for(contador = factorial ; contador > 1 ; contador--){
			
			numero = numero * factorial;
			factorial--;
		}
	
		return numero;
	}
}

int main(){
	
	int numero_real, copia_numero_real, resultado_potencia, resultado_factorial;
	int numero_n, copia_numero_n;
	
	cout << "Introduzca un número real (base): ";
	cin >> numero_real;
	cout << "Introduzca un número entero positivo (exponente): ";
	cin >> numero_n;
	
	numero_n = LeeEnteroPositivo(numero_n);
	copia_numero_n = numero_n;
	
	// FUNCIÓN POTENCIA //
	
	copia_numero_real = numero_real;
	resultado_potencia = Potencia(numero_real, copia_numero_real, numero_n);
	
	cout << "\nLa función potencia es igual a " << resultado_potencia;

	// FUNCIÓN FACTORIAL //
	
	resultado_factorial = Factorial(copia_numero_n);
	
	cout << "\nLa función factorial es igual a " << resultado_factorial << "\n";
	
system("pause");	
}
