/*
Cree las siguientes funciones relacionadas con la progresi�n geom�trica que se vio en el ejercicio 36 de la relaci�n de problemas II. 
Analizad cu�les deben ser los par�metros a estas funciones.

a) Una funci�n SumaHasta que calcule la suma de los primeros k valores de una
progresi�n geom�trica.
	Para implementarla, use el mismo algoritmo (con un bucle for) que se vio como soluci�n del ejercicio 36 de la relaci�n de problemas II.

b) Una funci�n ProductoHasta para que multiplique los k primeros elementos de la progresi�n.
Observe que no se pide calcular los productos acumulados en un bucle sino que simplemente eval�e la expresi�n sqrt((a1ak)^k) 
que le da directamente el producto de los k primeros t�rminos.

c) Una funci�n SumaHastaInfinito para calcular la suma hasta infinito.

Cree un programa principal que llame a estas funciones.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Sumar los k valores de la progresi�n geom�trica //

double SumaHasta (double a_1, double constante_r, double tope){
	
	/* 
	Sumar el valor inicial multiplicado por la constante de r mas la suma que se va acumulando.
	Elevar la raz�n cada vez un grado m�s.	
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

// Multiplicar los k primeros valores de la progresi�n geom�trica //

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
	Tres posibilidades en la funci�n 3: valor absoluto de la raz�n menor que 1, igual que 1 o mayor que 1.
	*/
	
	if (abs(constante_r) < 1){

	tercera_funcion = SumaHastaInfinito(primer_valor, constante_r);
	cout << "\nLa suma hasta infinito es " << tercera_funcion;
}
	else
		if (constante_r == 1)
		
		cout <<"\nLa suma hasta infinito no tiene soluci�n real";

		else
		
		cout << "\nLa suma hasta infinito es infinito";
		
	cout << "\n\n";
	
	system("pause");
}
