/*
Construya la función con cabecera:
	string Digitos (int n)
para que extraiga en un string los dígitos del número n tal y como se indica en el ejercicio 27 de la relación de problemas II.
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
		
string Digitos (int numero){
	
	string un_digito, numero_separado;
	
	int contador_digitos, divisor, digito, copia_numero;
	
	copia_numero = numero;
	contador_digitos = 0;
	
	// Contar las cifras que tiene nuestro número
	
	while(numero >= 10){
		
		numero = numero/10;
		contador_digitos++;
	}

	divisor = pow(10, contador_digitos);
	
	// Separar un dígito, convertirlo a un string y sumarlo en cadena
	// Reducir en módulo 10 nuestro número y el divisor para volver a sacar otro dígito
	
	while(divisor > 0){
		
		digito = copia_numero / divisor;
		un_digito = to_string(digito);
		numero_separado = numero_separado + un_digito + " ";
		copia_numero = copia_numero % divisor;
		divisor = divisor / 10;		
	}
	
	return numero_separado;
	
}

int main(){
	
	int numero;
	
	cout << "Introduzca un número entero: ";
	cin >> numero;
	
	cout << Digitos(numero);
	
}

