/*
En el ejercicio 14 de la Relación de Problemas I se pedía escribir un programa que leyese
un valor entero de tres dígitos e imprimiese los dígitos separados por un espacio
en blanco. Haced lo mismo pero para un número entero arbitrario.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int numero, contador_digitos, divisor, digito, copia_numero;
	
	cout << "Introduzca un número entero: ";
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
	
	
		
