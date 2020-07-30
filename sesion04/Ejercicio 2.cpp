/* 
	Ampliad el ejercicio 10 de la relaci�n de problemas I, para que, una vez calculada la
media y la desviaci�n, el programa imprima por cada uno de los valores introducidos
previamente, si est� por encima o por debajo de la media.
*/

#include <iostream>	// Inclusi�n de recursos E/S
#include <cmath>		// Inclusi�n de recursos matem�ticos
using namespace std;

int main (){
	
	double altura1;				// Declaraci�n de variables para guardar las 3 alturas
	double altura2;	
	double altura3;
	double media_aritmetica;	// Declaraci�n de variables para guardar la media aritm�tica y
	double desviacion_tipica;	// la desviaci�n t�pica
	
	cout << "Introduzca la altura 1: ";
	cin >> altura1;
	cout << "Introduzca la altura 2: ";
	cin >> altura2;
	cout << "Introduzca la altura 3: ";
	cin >> altura3;
	
	media_aritmetica = (altura1 + altura2 + altura3) / 3;
	
	desviacion_tipica = sqrt((pow(altura1 - media_aritmetica, 2) + pow(altura2 - media_aritmetica, 2) + pow(altura3 - media_aritmetica, 2)) / 3);
	
	cout << "\nLa media aritm�tica muestral vale " << media_aritmetica;
	
	cout << "\nLa desviaci�n t�pica muestral vale " << desviacion_tipica;
	
	if (altura1 > media_aritmetica)
		
		cout << "\n\nLa altura 1 est� por encima de la media";
		
	else 
	
		cout << "\n\nLa altura 1 no est� por encima de la media";
		
	if (altura2 > media_aritmetica)
	
		cout << "\nLa altura 2 est� por encima de la media";
		
	else
		
		cout << "\nLa altura 2 no est� por encima de la media";
			
	if (altura3 > media_aritmetica)
	
		cout << "\nLa altura 3 est� por encima de la media";
		
	else 
	
		cout << "\nLa altura 3 no est� por encima de la media";
}

