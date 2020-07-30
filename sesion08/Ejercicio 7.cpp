/*
Cree las siguientes funciones relacionadas con la progresión geométrica que se vio en el ejercicio 36 de la relación de problemas II. 
Analizad cuáles deben ser los parámetros a estas funciones.

a) Una función SumaHasta que calcule la suma de los primeros k valores de una
progresión geométrica.
	Para implementarla, use el mismo algoritmo (con un bucle for) que se vio como solución del ejercicio 36 de la relación de problemas II.

b) Una función ProductoHasta para que multiplique los k primeros elementos de la progresión.
Observe que no se pide calcular los productos acumulados en un bucle sino que simplemente evalúe la expresión sqrt((a1ak)^k) 
que le da directamente el producto de los k primeros términos.

c) Una función SumaHastaInfinito para calcular la suma hasta infinito.

Cree un programa principal que llame a estas funciones.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Sumar los k valores de la progresión geométrica //

double SumaHasta (double a_1, double constante_r, double tope){
	
	/* 
	Sumar el valor inicial multiplicado por la constante de r mas la suma que se va acumulando.
	Elevar la razón cada vez un grado más.	
	*/
	
	int copia_constante_r, suma, i;
	
	copia_constante_r = constante_r;
	suma = a_1;
	
	for(i = 1 ; i < tope ; i++){
		suma = suma + a_1 * constante_r;
		constante_r = copia_constante_r * constante_r;
	}

	return suma;
}

// Multiplicar los k primeros valores de la progresión geométrica //

double ProductoHasta (double a_1, double tope, double constante_r){

	double producto, a_k;
	
	a_k = a_1 * pow(constante_r, tope);
	
	producto = sqrt(pow(a_1 * a_k, tope));
	
	return producto;
}

// Suma hasta el infinito //

double SumaHastaInfinito (double a_1, double constante_r){

	double suma_infinito;
	
	suma_infinito = a_1 / (1 - constante_r);
		
	return suma_infinito;
}

int main(){

	double constante_r, primer_valor, tope, primera_funcion, segunda_funcion, tercera_funcion;
	
	cout << "Introduzca el primer elemento (a1): ";
	cin >> primer_valor;
	cout << "Introduzca el valor de la constante r: ";
	cin >> constante_r;
	cout << "Introduzca el tope (k): ";
	cin >> tope;
	
	primera_funcion = SumaHasta(primer_valor, constante_r, tope);
	
	cout << "\nLa suma de todos los elementos es " << primera_funcion;
	
	segunda_funcion = ProductoHasta(primer_valor, tope, constante_r);
	
	cout << "\nEl producto de todos los elementos es " << segunda_funcion;
	
	/* 
	Tres posibilidades en la función 3: valor absoluto de la razón menor que 1, igual que 1 o mayor que 1.
	*/
	
	if (abs(constante_r) < 1){

	tercera_funcion = SumaHastaInfinito(primer_valor, constante_r);
	cout << "\nLa suma hasta infinito es " << tercera_funcion;
}
	else
		if (constante_r == 1)
		
		cout <<"\nLa suma hasta infinito no tiene solución real";

		else
		
		cout << "\nLa suma hasta infinito es infinito";
		
	cout << "\n\n";
	
	system("pause");
}
