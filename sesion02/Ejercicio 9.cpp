/*
	Programa para intercambiar dos variables enteras, la edad de Juan y la edad de Pedro
*/

#include <iostream>	// Inclusión de recursos E/S
using namespace std;

int main(){
	
	int edad_Juan;		// Declara variables para guardar la edad de Juan,
	int edad_Pedro;	// la de Pedro y
	int edades;			// una auxiliar
	
	cout << "Introduzca la edad de Juan: ";
	cin >> edad_Juan;
	cout << "Introduzca la edad de Pedro: ";
	cin >> edad_Pedro;
	
	edades = edad_Juan;
	edad_Juan = edad_Pedro;
	edad_Pedro = edades;
	
	cout << "\nLa edad de Juan es: " << edad_Juan;
	cout << "\nLa edad de Pedro es: " << edad_Pedro;
}
	

