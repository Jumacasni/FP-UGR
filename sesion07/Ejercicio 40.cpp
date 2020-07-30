/*
Sobre la solución del ejercicio 19 de esta relación de problemas, se pide lo siguiente. Supondremos que sólo pueden introducirse intereses enteros (1, 2, 3, etc). 
Se pide calcular el capital obtenido al término de cada año, pero realizando los cálculos para todos los tipos de interés enteros menores o iguales que el 
introducido (en pasos de 1). Por ejemplo, si el usuario introduce un interés igual a 5 y un número de años igual a 3, hay que mostrar el capital ganado 
al término de cada uno de los tres años a un interés del 1 %, a continuación, lo mismo para un interés del 2% y así sucesivamente hasta llegar al 5 %.
*/

#include <iostream>

using namespace std;

int main (){
	
	double capital, total, copia_capital;
	int contador_anios, anio_final, interes, contador_interes;
	
	cout << "Introduzca el capital: ";
	cin >> capital;
	cout << "Introduzca el interés: ";
	cin >> interes;
	cout << "Introduzca el número de años: ";
	cin >> anio_final;
	
	copia_capital = capital;
	
	for (contador_interes = 1; contador_interes <= interes; contador_interes++){
		cout << "\n\nCálculos realizados al " << contador_interes << "%:\n";
		
		capital = copia_capital;																		// Reiniciamos el capital para hacer los mismos cálculos pero con un interés mayor
		
		for (contador_anios = 1; contador_anios <= anio_final; contador_anios++){
			total = capital + capital*(contador_interes / 100);
			capital = total;
			
			cout << "\nDinero obtenido en el año número " << contador_anios << ": " << total;
		}		
	}
system("pause");
}
