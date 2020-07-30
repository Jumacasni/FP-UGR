/*
Sobre la soluci�n del ejercicio 19 de esta relaci�n de problemas, se pide lo siguiente. Supondremos que s�lo pueden introducirse intereses enteros (1, 2, 3, etc). 
Se pide calcular el capital obtenido al t�rmino de cada a�o, pero realizando los c�lculos para todos los tipos de inter�s enteros menores o iguales que el 
introducido (en pasos de 1). Por ejemplo, si el usuario introduce un inter�s igual a 5 y un n�mero de a�os igual a 3, hay que mostrar el capital ganado 
al t�rmino de cada uno de los tres a�os a un inter�s del 1 %, a continuaci�n, lo mismo para un inter�s del 2% y as� sucesivamente hasta llegar al 5 %.
*/

#include <iostream>

using namespace std;

int main (){
	
	double capital, total, copia_capital;
	int contador_anios, anio_final, interes, contador_interes;
	
	cout << "Introduzca el capital: ";
	cin >> capital;
	cout << "Introduzca el inter�s: ";
	cin >> interes;
	cout << "Introduzca el n�mero de a�os: ";
	cin >> anio_final;
	
	copia_capital = capital;
	
	for (contador_interes = 1; contador_interes <= interes; contador_interes++){
		cout << "\n\nC�lculos realizados al " << contador_interes << "%:\n";
		
		capital = copia_capital;																		// Reiniciamos el capital para hacer los mismos c�lculos pero con un inter�s mayor
		
		for (contador_anios = 1; contador_anios <= anio_final; contador_anios++){
			total = capital + capital*(contador_interes / 100);
			capital = total;
			
			cout << "\nDinero obtenido en el a�o n�mero " << contador_anios << ": " << total;
		}		
	}
system("pause");
}
