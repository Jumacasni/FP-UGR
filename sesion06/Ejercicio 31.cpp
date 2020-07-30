/*
Un número entero n se dice que es desgarrable (torn) si al dividirlo en dos partes
cualesquiera izda y dcha, el cuadrado de la suma de ambas partes es igual a n.
Por ejemplo, 88209 es desgarrable ya que (88 + 209)^2 = 88209; 81 también lo es
ya que 81 = (8 + 1)^2. Cread un programa que lea un entero n e indique si es o no
desgarrable.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int numero, izquierda, derecha, copia_numero, contador_digitos, divisor, numero_desgarrable;
	bool es_impar;
	
	cout << "Introduzca un número entero: ";
	cin >> numero;
	
	copia_numero = numero;
	contador_digitos = 1;
	
	while(numero >= 10){
		
		numero = numero / 10;
		contador_digitos++;
	}
	
	es_impar = (contador_digitos % 2 != 0);
	
	if (es_impar)
		
		contador_digitos = contador_digitos / 2 + 1;
	
	else
		
		contador_digitos = contador_digitos / 2;
	
	divisor = pow(10, contador_digitos);

	izquierda = copia_numero / divisor;
	derecha = copia_numero % divisor;

	numero_desgarrable = pow(izquierda + derecha, 2);

	if (numero_desgarrable == copia_numero)
		cout << "\nEl número introducido es desgarrable";
	else
		cout << "\nEl número introducido no es desgarrable";
}
	
	
	
