/*
Supongamos una serie numérica cuyo término general es:
ai = a1r^(i-1)
Se pide crear un programa que lea desde teclado r, el primer elemento a1 y el tope k y calcule la suma de los primeros k valores de la serie. Se proponen dos alternativas:
a) Realizad la suma de la serie usando la función pow para el cómputo de cada término ai. Los argumentos de pow no pueden ser ambos enteros, por lo que
forzaremos a que la base (por ejemplo) sea double, multiplicando por 1.0.
b) Si analizamos la expresión algebraica de la serie numérica, nos damos cuenta que es una progresión geométrica ya que cada término de la serie queda definido
por la siguiente expresión: ai+1 = ai * r
Es decir, una progresión geométrica es una secuencia de elementos en la que cada uno de ellos se obtiene multiplicando el anterior por una constante denominada
razón o factor de la progresión. Cread el programa pedido usando esta fórmula. NO puede utilizarse la función pow.
¿Qué solución es preferible en términos de eficiencia?
*/

#include <iostream>

using namespace std;

int main(){
	
	int constante_r, copia_constante_r, primer_valor, tope, suma, i;
	
	cout << "Introduzca el primer elemento (a1): ";
	cin >> primer_valor;
	cout << "Introduzca el valor de la constante r: ";
	cin >> constante_r;
	cout << "Introduzca el tope (k): ";
	cin >> tope;
	
	copia_constante_r = constante_r;
	suma = primer_valor;
	
	for(i = 1 ; i < tope ; i++){
		suma = suma + primer_valor * constante_r;
		constante_r = copia_constante_r * constante_r;
	}
	
	cout << "\nLa suma de todos los elementos es " << suma;
}
		
		
		
		
	
