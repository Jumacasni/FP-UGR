/* 
	Ampliad el ejercicio 10 de la relación de problemas I, para que, una vez calculada la
media y la desviación, el programa imprima por cada uno de los valores introducidos
previamente, si está por encima o por debajo de la media.
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
	
	desviacion_tipica = sqrt((pow(altura1 - media_aritmetica, 2) + pow(altura2 - media_aritmetica, 2) + pow(altura3 - media_aritmetica, 2)) / 3);
	
	cout << "\nLa media aritmética muestral vale " << media_aritmetica;
	
	cout << "\nLa desviación típica muestral vale " << desviacion_tipica;
	
	if (altura1 > media_aritmetica)
		
		cout << "\n\nLa altura 1 está por encima de la media";
		
	else 
	
		cout << "\n\nLa altura 1 no está por encima de la media";
		
	if (altura2 > media_aritmetica)
	
		cout << "\nLa altura 2 está por encima de la media";
		
	else
		
		cout << "\nLa altura 2 no está por encima de la media";
			
	if (altura3 > media_aritmetica)
	
		cout << "\nLa altura 3 está por encima de la media";
		
	else 
	
		cout << "\nLa altura 3 no está por encima de la media";
}

