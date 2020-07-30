/*
		Leed desde teclado tres variables correspondientes a un n�mero de horas, minutos y segundos, respectivamente. Dise�ar un algoritmo que calcule las horas, minutos y
	segundos dentro de su rango correspondiente. Por ejemplo, dadas 10 horas, 119 minutos y 280 segundos, deber�a dar como resultado 12 horas, 3 minutos y 40 segundos.
	El programa no calcular� meses, a�os, etc sino que se quedar� en los d�as.
		Como consejo, utilizad el operador / que cuando trabaja sobre datos enteros, representa la divisi�n entera. Para calcular el resto de la divisi�n entera, usad el operador %.
*/

#include <iostream>	// Inclusi�n de recursos E/S

using namespace std;

int main(){
	
	int horas1;									// Declaro variables para guardar la hora inicial
	int minutos1;
	int segundos1;
	int horas2;									// Variables para guardar la hora final dentro de su rango correspondiente
	int minutos2;
	int segundos2;
	int minutos_exceso;						// Variable para guardar los minutos fuera del rango correspondiente y realizar las operaciones sin repetir c�digo
	const int segundos_minuto = 60;		// Constante que indica que un minuto tiene 60 segundos
	const int minutos_hora = 60;			// Constante que indica que una hora tiene 60 minutos
	
	cout << "Introduzca las horas iniciales: ";
	cin >> horas1;
	cout << "Introduzca los minutos iniciales: ";
	cin >> minutos1;
	cout << "Introduzca los segundos iniciales: ";
	cin >> segundos1;
	
	minutos_exceso = (segundos1 / segundos_minuto + minutos1);
	
	segundos2 = segundos1 % segundos_minuto;
	minutos2 = minutos_exceso % minutos_hora;
	horas2 = minutos_exceso / minutos_hora + horas1;
	
	cout << "\nLa hora dentro de su rango correspondiente es " << horas2 << " horas " << minutos2 << " minutos y " << segundos2 << " segundos.";
}
