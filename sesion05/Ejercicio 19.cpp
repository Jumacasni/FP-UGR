/*
	Modifiquemos el ejercicio 6 del capital y los intereses de la primera relación. Supongamos ahora que se quiere reinvertir todo el dinero obtenido 
(el original C más los intereses producidos) en otro plazo fijo a un año y así, sucesivamente. Construid un programa para que lea el capital, el interés y 
un número de años N, y calcule e imprima todo el dinero obtenido durante cada uno de los N años, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente año.	
*/
#include <iostream>

using namespace std;

int main (){
	
	double capital, interes, total;
	int anios, anio_final;
	
	cout << "Introduzca el capital: ";
	cin >> capital;
	cout << "Introduzca el interés: ";
	cin >> interes;
	cout << "Introduzca el número de años: ";
	cin >> anio_final;
	
	anios = 1;
	
	do{
		total = capital + capital*(interes/100);
		
		cout << "\nTotal en el año número " << anios << ": " << total << " euros.";
		
		anios++;
		capital = total;
		}while (anios <= anio_final );
}
		
