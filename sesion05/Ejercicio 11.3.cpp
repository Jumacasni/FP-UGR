/*
	Modificad las soluciones de los ejercicios 3 y 5 para que no se mezclen E/S y C
(entradas/salidas y cómputos) dentro de la misma estructura condicional.
*/

#include <iostream>	// Inclusión de recursos E/S

using namespace std;

int main (){
	
	int edad;		
	double salario, salario_final;	
	int EDAD_MAYOR = 65;
	double SALARIO_MINIMO = 300;
	double PORCIENTO_SALARIO = 0.05;
	bool salario_minimo_y_persona_mayor;	
	
	cout << "Introduzca la edad del empleado: ";
	cin >> edad;
	cout << "Introduzca el salario del empleado: ";
	cin >> salario;
	
	salario_minimo_y_persona_mayor = edad > EDAD_MAYOR && salario < SALARIO_MINIMO;
	salario_final = salario + PORCIENTO_SALARIO*salario;
	
	if (salario_minimo_y_persona_mayor)
		
		cout << "\nEl salario es de " << salario_final << " euros.";

	else
	
		cout <<"\nNo es aplicable la subida, el salario se queda en " << salario << " euros.";
}
