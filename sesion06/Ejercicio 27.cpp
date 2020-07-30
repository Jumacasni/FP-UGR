/*
En el ejercicio 14 de la Relaci�n de Problemas I se ped�a escribir un programa que leyese
un valor entero de tres d�gitos e imprimiese los d�gitos separados por un espacio
en blanco. Haced lo mismo pero para un n�mero entero arbitrario.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int numero, contador_digitos, divisor, digito, copia_numero;
	
	cout << "Introduzca un n�mero entero: ";
	cin >> numero;
	
	copia_numero = numero;
	contador_digitos = 0;
	
	while(numero >= 10){
		
		numero = numero/10;
		contador_digitos++;
}

	divisor = pow(10, contador_digitos);
	
	while(divisor > 0){
		
		digito = copia_numero / divisor;
		cout << digito << " ";
		copia_numero = copia_numero % divisor;
		divisor = divisor / 10;		
	}
}
	
	
		
