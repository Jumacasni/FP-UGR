/*
	Sobre el mismo ejercicio del capital y los intereses, construid un programa para calcular cu�ntos a�os han de pasar hasta llegar a doblar, como m�nimo, 
el capital inicial. Los datos que han de leerse desde teclado son el capital inicial y el inter�s anual.
*/
#include <iostream>

using namespace std;

int main (){
	
	double capital, capital_inicial, interes, total, doble_capital;
	int anios;
	
	cout << "Introduzca el capital: ";
	cin >> capital_inicial;
	cout << "Introduzca el inter�s: ";
	cin >> interes;
	
	doble_capital = 2*capital_inicial;
	capital = capital_inicial;
	anios = 0;
	
	do{
		total = capital + capital*(interes/100);
		anios++;
		capital = total;
	}while (capital < doble_capital);
	
	cout << "\nPasar�/n " << anios << " a�o/s hasta doblar el capital inicial.";
}
