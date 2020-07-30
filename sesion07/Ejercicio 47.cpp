/*
Modificad los dos ejercicios anteriores para que se lea desde teclado el valor inicial y el número de filas a imprimir. 
En los ejemplos anteriores, el valor inicial era 1 y se imprimían un total de 6 filas
*/

#include <iostream>

using namespace std;

int main(){
	
	int contador, numero, tope_filas, tope_numeros, numeros_fila;
	int numero_45, numero_46, copia_numero_45, copia_numero_46;							// Variables para guardar los números de sus respectivos ejercicios.
	
	cout << "Introduzca un valor inicial: ";
	cin >> numero;
	cout << "Introduzca el número de filas a imprimir: ";
	cin >> tope_filas;

	// EJERCICIO 45 //
	
	numero_45 = numero;
	tope_numeros = tope_filas + numero_45;
	
	for (contador = 1; contador <= tope_filas; contador++){
		for (copia_numero_45 = numero_45; copia_numero_45 < tope_numeros; copia_numero_45++){
		cout << copia_numero_45 << " ";
		
}	
	numero_45++;
	cout << "\n";
}

	// EJERCICIO 46 //
	
	cout << "\n";
	numero_46 = numero;
	copia_numero_46 = numero_46;
	
	for (contador = 1; contador <= tope_filas; contador++){
		
		numero_46 = copia_numero_46;
		
		for (numeros_fila = 1; numeros_fila <= tope_filas; numeros_fila++){
			
			cout << numero_46 << " ";
			numero_46++;			
		}
		
		copia_numero_46++;
		cout << "\n";
	}
system("pause");
}
	
