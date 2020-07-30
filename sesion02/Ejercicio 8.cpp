/*
	Programa para calcular cu�nto dinero cobran los tres fabricantes y el dise�ador de un producto, sabiendo que 
	el dise�ador cobra el doble que cada uno de los fabricantes
*/

#include <iostream>	// Inclusi�n de recursos de E/S
using namespace std;

int main (){
	
	double ganancia_total;			// Declara variables para guardar la ganancia total a repartir,
	double ganancia_disenador;		// la ganancia del dise�ador y
	double ganancia_fabricantes;	// la ganancia de cada uno de los fabricantes
	
	cout << "Introduzca la ganancia total a repartir: ";
	cin >> ganancia_total;
	
	ganancia_fabricantes = ganancia_total / 5;
	
	cout << "\nCada fabricante gana " << ganancia_fabricantes << " euros.";
	
	ganancia_disenador = 2 * ganancia_fabricantes;
	
	cout << "\nEl dise�ador gana " << ganancia_disenador << " euros.";
}
