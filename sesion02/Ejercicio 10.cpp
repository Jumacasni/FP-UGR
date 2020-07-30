/*
	Programa para calcular la media aritmética muestral y desviación típica muestral de las alturas de 3 personas
*/

#include <iostream>	// Inclusión de recursos E/S
#include <cmath>		// Inclusión de recursos matemáticos
using namespace std;

int main (){
	
	double altura1;				// Declaración de variables para guardar las 3 alturas
	double altura2;	
	double altura3;
	double media_aritmetica;	// Declaración de variables para guardar la media aritmética y
	double desviacion_tipica;	// la desviación típica
	
	cout << "Introduzca la altura 1: ";
	cin >> altura1;
	cout << "Introduzca la altura 2: ";
	cin >> altura2;
	cout << "Introduzca la altura 3: ";
	cin >> altura3;
	
	media_aritmetica = (altura1 + altura2 + altura3) / 3;
	
	desviacion_tipica = sqrt(pow(altura1 - media_aritmetica, 2) / 3 + pow(altura2 - media_aritmetica, 2) / 3 + pow(altura3 - media_aritmetica, 2) / 3);
	
	cout << "\nLa media aritmética muestral vale " << media_aritmetica;
	
	cout << "\nLa desviación típica muestral vale " << desviacion_tipica;
}
