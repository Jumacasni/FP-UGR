/*
	Modifiquemos el ejercicio 6 del capital y los intereses de la primera relaci�n. Supongamos ahora que se quiere reinvertir todo el dinero obtenido 
(el original C m�s los intereses producidos) en otro plazo fijo a un a�o y as�, sucesivamente. Construid un programa para que lea el capital, el inter�s y 
un n�mero de a�os N, y calcule e imprima todo el dinero obtenido durante cada uno de los N a�os, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente a�o.	
*/
#include <iostream>

using namespace std;

int main (){
	
	double capital, interes, total;
	int anios, anio_final;
	
	cout << "Introduzca el capital: ";
	cin >> capital;
	cout << "Introduzca el inter�s: ";
	cin >> interes;
	cout << "Introduzca el n�mero de a�os: ";
	cin >> anio_final;
	
	anios = 1;
	
	do{
		total = capital + capital*(interes/100);
		
		cout << "\nTotal en el a�o n�mero " << anios << ": " << total << " euros.";
		
		anios++;
		capital = total;
		}while (anios <= anio_final );
}
		
