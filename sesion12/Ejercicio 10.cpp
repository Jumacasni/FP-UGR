/*
En este ejercicio no hay que definir ninguna clase. Todas las operaciones se realizan directamente en el main.
Construya un programa que vaya leyendo caracteres hasta que se encuentre un punto '.' y cuente el n�mero de veces que aparece cada una de las 
letras may�sculas. Imprimir el resultado.
Una posibilidad ser�a declarar un vector contador_mayusculas con tantas componentes como letras may�sculas hay ('Z'-'A'+1) y conforme se va 
leyendo cada car�cter, ejecutar lo siguiente:
cin >> letra;
if (letra == 'A')
contador_mayusculas[0] = contador_mayusculas[0] + 1;
else if (letra == 'B')
contador_mayusculas[1] = contador_mayusculas[1] + 1;
else if (letra == 'C')
contador_mayusculas[2] = contador_mayusculas[2] + 1;
else ....
Sin embargo, este c�digo es muy redundante. Como soluci�n se propone calcular de forma directa el �ndice entero que le corresponde a cada 
may�scula, de forma que todos los if-else anteriores los podamos resumir en una �nica sentencia del tipo:
contador_mayusculas[indice] = contador_mayusculas[indice] + 1;
Hacedlo, declarando el vector directamente dentro del main.
*/

#include <iostream>

using namespace std;

bool EsMayuscula (char caracter){
	
	return 'A' <= caracter && caracter <= 'Z';
}

int main(){
	
	int TOTAL_MAYUSCULAS = 'Z' - 'A' + 1;
	int contador_mayusculas[TOTAL_MAYUSCULAS] = {0};
	char mayuscula[TOTAL_MAYUSCULAS];
	char caracter;
	char LETRA = 'A';
	char TERMINADOR = '.';
	int i;
	bool mayuscula_repetida;
	
	// Asignamos una posici�n a cada letra may�scula
	
	for (i = 0 ; i < TOTAL_MAYUSCULAS ; i++){
		mayuscula[i] = LETRA;
		LETRA++;
	}
	
	cout << "Introduzca las letras: ";
	cin >> caracter;
	
	// Comprueba que el car�cter introducido no es '.'
	// Si es may�scula, empieza a recorrer las posiciones de cada letra may�scula
	// Suma 1 cuando la letra may�scula introducida coincida con el vector de esa letra y se sale para pedir otro car�cter
	
	while (caracter != TERMINADOR){
		
		mayuscula_repetida = false;
		
		if (EsMayuscula(caracter)){
			for (i = 0 ; i < TOTAL_MAYUSCULAS && !mayuscula_repetida ; i++){
				if (caracter == mayuscula[i]){
					contador_mayusculas[i] = contador_mayusculas[i] + 1;
					mayuscula_repetida = true;
				}
			}
		}
		
		cin >> caracter;
	}
	
	// Recorre todas las posiciones y muestra las veces que se han repetido las letras may�sculas introducidas
	
	for (i = 0 ; i < TOTAL_MAYUSCULAS ; i++){
		if (contador_mayusculas[i] > 0)
			cout << "\nLetra " << mayuscula[i] << " escrita " << contador_mayusculas[i] << " veces";
	}
			
cout << "\n\n";
system("pause");
	
}
