/*
	Cread un programa que lea el valor de la edad (dato de tipo entero) y salario (dato de
tipo real) de una persona. Subid el salario un 5% si éste es menor de 300 euros y la
persona es mayor de 65 años.
	¿Es mejor incluir otra variable nueva salario_final o es mejor modificar la variable
que teníamos?
	Imprimid el resultado por pantalla. En caso contrario imprimid el mensaje
"No es aplicable la subida". En ambos casos imprimid el salario resultante.
*/

#include <iostream>	// Inclusión de recursos E/S

using namespace std;

int main (){
	
	int edad;		
	double salario;	
	int EDAD_MAYOR = 65;
	double SALARIO_MINIMO = 300;
	double PORCIENTO_SALARIO = 0.05;	
	
	cout << "Introduzca la edad del empleado: ";
	cin >> edad;
	cout << "Introduzca el salario del empleado: ";
	cin >> salario;
	
	if (edad > EDAD_MAYOR && salario < SALARIO_MINIMO){
	
		salario = salario + PORCIENTO_SALARIO*salario;
		
		cout << "\nEl salario es de " << salario << " euros.";
}
	else
	
		cout <<"\nNo es aplicable la subida, el salario se queda en " << salario << " euros.";
}
