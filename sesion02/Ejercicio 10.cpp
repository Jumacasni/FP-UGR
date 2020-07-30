/*
	Programa para calcular la media aritm�tica muestral y desviaci�n t�pica muestral de las alturas de 3 personas
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
	
	desviacion_tipica = sqrt(pow(altura1 - media_aritmetica, 2) / 3 + pow(altura2 - media_aritmetica, 2) / 3 + pow(altura3 - media_aritmetica, 2) / 3);
	
	cout << "\nLa media aritm�tica muestral vale " << media_aritmetica;
	
	cout << "\nLa desviaci�n t�pica muestral vale " << desviacion_tipica;
}
