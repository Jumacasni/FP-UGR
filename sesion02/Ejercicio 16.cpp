/* 
	Programa para calcular el número de segundos que hay entre dos instantes del mismo dia
*/

#include <iostream>	// Inclusión de recursos de E/S
#include <cmath>		// Inclusión de recursos matemáticos
using namespace std;

int main (){										// Programa principal
	
	double hora1, minutos1, segundos1;		// Declara variables para guardar la hora inicial
	double hora2, minutos2, segundos2;		// Declara variables para guardar la hora final
	double segundos_finales;					// Declara variable para guardar los segundos que hay entre los dos instantes
	const double horas_segundos = 3600;		// Una hora tiene 3600 segundos
	const double minutos_segundos = 60;		// Un minuto tiene 60 segundos
	
	cout << "Hora inicial: ";
	cin >> hora1;
	cout << "Minuto inicial: ";
	cin >> minutos1;
	cout << "Segundo inicial: ";
	cin >> segundos1;
	cout << "Hora final: ";
	cin >> hora2;
	cout << "Minuto final: ";
	cin >> minutos2;
	cout << "Segundo final: ";
	cin >> segundos2;
	
	segundos_finales = abs(horas_segundos*(hora1 - hora2) + minutos_segundos*(minutos1 - minutos2) + segundos1 - segundos2);
	
	cout << "\nEntre los dos instantes hay " << segundos_finales << " segundos";
}
	
	
