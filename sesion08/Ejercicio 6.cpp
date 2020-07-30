/*
A un trabajador le pagan según sus horas trabajadas y la tarifa está a un valor por hora. Si la cantidad de horas trabajadas es mayor de 40 horas, la tarifa 
por hora se incrementa en un 50% para las horas extras (las que haya por encima de 40). Construir una función que dado el número total de horas trabajadas 
y el precio por hora, devuelva el salario del trabajador.
*/

#include <iostream>

using namespace std;

// Calcular el salario del trabajador //

double SalarioTrabajador(int horas_trabajadas, double precio_hora){
	
	/* Comrpobar hora por hora si el número de horas es mayor de 40.
		Sumar el salario de cada hora.
	*/
	
	int MAS_DE_40 = 40;
	int contador_horas;
	double INCREMENTO = 0.5;
	double copia_precio_hora;
	
	copia_precio_hora = precio_hora;
	
	for(contador_horas = 1; contador_horas < horas_trabajadas; contador_horas++){
		
		if (contador_horas < MAS_DE_40)
			precio_hora = copia_precio_hora + precio_hora;
		else
			precio_hora = (copia_precio_hora + copia_precio_hora * INCREMENTO) + precio_hora;
	}	
	
		return precio_hora;	
}

int main(){
	
	int horas;
	double salario, precio_hora;
	
	cout << "Introduzca el número total de horas trabajadas: ";
	cin >> horas;
	cout << "Introduzca el precio por cada hora trabajada: ";
	cin >> precio_hora;
	
	salario = SalarioTrabajador(horas, precio_hora);
	
	cout << "\nEl trabajador va a cobrar " << salario << " euros.";
	cout << "\n\n";
	
	system("pause");
}
	
