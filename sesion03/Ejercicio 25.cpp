/*
	Escribid una expresi�n l�gica que sea verdadera si una variable de tipo car�cter llamada letra es una letra min�scula y falso en otro caso.
	
	Escribid una expresi�n l�gica que sea verdadera si una variable de tipo entero llamada edad es menor de 18 o mayor de 65.
	
	Escribid una expresi�n l�gica que nos informe cuando un a�o es bisiesto. Los a�os bisiestos son aquellos que o bien son divisibles por 4 pero no por 100, o bien son
	divisibles por 400.
	
	Escribid un programa que lea las variables letra, edad y anio, calcule el valor de las expresiones l�gicas anteriores e imprima el resultado. 
	
	Tened en cuenta que cuando se imprime por pantalla (con cout) una expresi�n l�gica que es true, se imprime 1. Si es false, se imprime un 0. En el tema 2 veremos la raz�n.
*/

#include <iostream>	// Inclusi�n de recursos de E/S

using namespace std;

int main(){
	
	char letra;						// Declaraci�n de variables para guardar la letra y la condici�n a cumplir
	bool condicion_caracter;
	int edad;						// Declaraci�n de variables para guardar la edad y la condici�n a cumplir
	bool condicion_edad;
	int anio;						// Declaraci�n de variables para guardar el a�o y la condici�n a cumplir
	bool condicion_anio;			
	
	cout << "Introduzca un car�cter: ";
	cin >> letra;
	cout << "Introduzca la edad: ";
	cin >> edad;
	cout << "Introduzca el a�o: ";
	cin >> anio;
		
	condicion_caracter = 'a' <= letra && letra <= 'z';
	
	cout << "\nEl car�cter es una letra min�scula si el valor es 1 y 0 si es otro car�cter: " << condicion_caracter << "\n\n";	
	
	condicion_edad = edad < 18 || edad > 65;
	
	cout << "\nSi es menor de 18 o mayor de 65 el valor es 1 y si no es 0: " << condicion_edad << "\n\n";
	
	condicion_anio = (anio % 4) == 0 && (anio % 100) != 0 || (anio % 400) == 0;
	
	cout <<"\nEs un a�o bisiesto si el valor es 1 y si no es 0: " << condicion_anio << "\n\n";
		
}


	
	
