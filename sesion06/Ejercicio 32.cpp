/*
Un n�mero entero de n d�gitos se dice que es narcisista si se puede obtener como
la suma de las potencias n-�simas de cada uno de sus d�gitos. Por ejemplo 153 y
8208 son n�meros narcisistas porque 153 = 1^3 + 5^3+ 3^3 (153 tiene 3 d�gitos) y
8208 = 8^4 +2^4 +0^4 +8^4 (8208 tiene 4 d�gitos). Construir un programa que, dado un
n�mero entero positivo, nos indique si el n�mero es o no narcisista.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int numero, contador_digitos, divisor, digito, exponente_divisor, copia_numero, suma_digitos, copia_numero_narcicista;
	
	cout << "Introduzca un n�mero entero positivo: ";
	cin >> numero;
	
	copia_numero = numero;
	copia_numero_narcicista = numero;
	
	while(numero < 0){
		cout << "Introduzca un n�mero entero positivo: ";
		cin >> numero;
	}
	
	contador_digitos = 0;
	
	while(numero > 0){
		
		numero = numero / 10;
		contador_digitos++;
	}
	
	exponente_divisor = contador_digitos - 1;
	divisor = pow(10, exponente_divisor);
	suma_digitos = 0;
	
	while(divisor > 0){
		
		digito = copia_numero / divisor;
		suma_digitos = suma_digitos + pow(digito, contador_digitos);
		copia_numero = copia_numero % divisor;
		divisor = divisor / 10;
	}

	if (copia_numero_narcicista == suma_digitos)
		cout << "\nEl n�mero introducido es narcicista.";
	else
		cout << "\nEl n�mero introducido no es narcicista.";
	
}
