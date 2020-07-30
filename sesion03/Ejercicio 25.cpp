/*
	Escribid una expresión lógica que sea verdadera si una variable de tipo carácter llamada letra es una letra minúscula y falso en otro caso.
	
	Escribid una expresión lógica que sea verdadera si una variable de tipo entero llamada edad es menor de 18 o mayor de 65.
	
	Escribid una expresión lógica que nos informe cuando un año es bisiesto. Los años bisiestos son aquellos que o bien son divisibles por 4 pero no por 100, o bien son
	divisibles por 400.
	
	Escribid un programa que lea las variables letra, edad y anio, calcule el valor de las expresiones lógicas anteriores e imprima el resultado. 
	
	Tened en cuenta que cuando se imprime por pantalla (con cout) una expresión lógica que es true, se imprime 1. Si es false, se imprime un 0. En el tema 2 veremos la razón.
*/

#include <iostream>	// Inclusión de recursos de E/S

using namespace std;

int main(){
	
	char letra;						// Declaración de variables para guardar la letra y la condición a cumplir
	bool condicion_caracter;
	int edad;						// Declaración de variables para guardar la edad y la condición a cumplir
	bool condicion_edad;
	int anio;						// Declaración de variables para guardar el año y la condición a cumplir
	bool condicion_anio;			
	
	cout << "Introduzca un carácter: ";
	cin >> letra;
	cout << "Introduzca la edad: ";
	cin >> edad;
	cout << "Introduzca el año: ";
	cin >> anio;
		
	condicion_caracter = 'a' <= letra && letra <= 'z';
	
	cout << "\nEl carácter es una letra minúscula si el valor es 1 y 0 si es otro carácter: " << condicion_caracter << "\n\n";	
	
	condicion_edad = edad < 18 || edad > 65;
	
	cout << "\nSi es menor de 18 o mayor de 65 el valor es 1 y si no es 0: " << condicion_edad << "\n\n";
	
	condicion_anio = (anio % 4) == 0 && (anio % 100) != 0 || (anio % 400) == 0;
	
	cout <<"\nEs un año bisiesto si el valor es 1 y si no es 0: " << condicion_anio << "\n\n";
		
}


	
	
