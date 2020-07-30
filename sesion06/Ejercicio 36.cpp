/*
Supongamos una serie num�rica cuyo t�rmino general es:
ai = a1r^(i-1)
Se pide crear un programa que lea desde teclado r, el primer elemento a1 y el tope k y calcule la suma de los primeros k valores de la serie. Se proponen dos alternativas:
a) Realizad la suma de la serie usando la funci�n pow para el c�mputo de cada t�rmino ai. Los argumentos de pow no pueden ser ambos enteros, por lo que
forzaremos a que la base (por ejemplo) sea double, multiplicando por 1.0.
b) Si analizamos la expresi�n algebraica de la serie num�rica, nos damos cuenta que es una progresi�n geom�trica ya que cada t�rmino de la serie queda definido
por la siguiente expresi�n: ai+1 = ai * r
Es decir, una progresi�n geom�trica es una secuencia de elementos en la que cada uno de ellos se obtiene multiplicando el anterior por una constante denominada
raz�n o factor de la progresi�n. Cread el programa pedido usando esta f�rmula. NO puede utilizarse la funci�n pow.
�Qu� soluci�n es preferible en t�rminos de eficiencia?
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
		
		
		
		
	
