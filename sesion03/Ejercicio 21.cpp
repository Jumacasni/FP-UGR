/*
		Supongamos el siguiente código:
		int entero;
		char caracter;
		caracter = '7';
		entero = caracter;
		La variable entero almacenará el valor 55 (el orden en la tabla ASCII del carácter '7'). Queremos construir una expresión que devuelva el entero 7, para asignarlo a la
	variable entero. Formalmente: Supongamos una variable car de tipo carácter que contiene un valor entre '0' y '9'. Construid un programa que obtenga el correspondiente valor entero, 
	se lo asigne a una variable de tipo int llamada entero y lo imprima en pantalla. Por ejemplo, si la variable car contiene '7' queremos asignarle a entero el valor numérico 7.
		Nota. La comilla simple para representar un literal de carácter es la que hay en el teclado del ordenador debajo de la interrogación ?.	
*/

#include <iostream>	// Inclusión de recursos E/S

using namespace std;

int main (){
	
	char caracter;		// Declara variables para guardar el carácter y el número entero
	int entero;		
	
	cout << "Introduzca un número entre el 0 y el 9: ";
	cin >> caracter;
	
	entero = caracter - '0';
	
	cout << "\nEl número entero es " << entero;
}
