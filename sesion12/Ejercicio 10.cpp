/*
En este ejercicio no hay que definir ninguna clase. Todas las operaciones se realizan directamente en el main.
Construya un programa que vaya leyendo caracteres hasta que se encuentre un punto '.' y cuente el número de veces que aparece cada una de las 
letras mayúsculas. Imprimir el resultado.
Una posibilidad sería declarar un vector contador_mayusculas con tantas componentes como letras mayúsculas hay ('Z'-'A'+1) y conforme se va 
leyendo cada carácter, ejecutar lo siguiente:
cin >> letra;
if (letra == 'A')
contador_mayusculas[0] = contador_mayusculas[0] + 1;
else if (letra == 'B')
contador_mayusculas[1] = contador_mayusculas[1] + 1;
else if (letra == 'C')
contador_mayusculas[2] = contador_mayusculas[2] + 1;
else ....
Sin embargo, este código es muy redundante. Como solución se propone calcular de forma directa el índice entero que le corresponde a cada 
mayúscula, de forma que todos los if-else anteriores los podamos resumir en una única sentencia del tipo:
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
	
	// Asignamos una posición a cada letra mayúscula
	
	for (i = 0 ; i < TOTAL_MAYUSCULAS ; i++){
		mayuscula[i] = LETRA;
		LETRA++;
	}
	
	cout << "Introduzca las letras: ";
	cin >> caracter;
	
	// Comprueba que el carácter introducido no es '.'
	// Si es mayúscula, empieza a recorrer las posiciones de cada letra mayúscula
	// Suma 1 cuando la letra mayúscula introducida coincida con el vector de esa letra y se sale para pedir otro carácter
	
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
	
	// Recorre todas las posiciones y muestra las veces que se han repetido las letras mayúsculas introducidas
	
	for (i = 0 ; i < TOTAL_MAYUSCULAS ; i++){
		if (contador_mayusculas[i] > 0)
			cout << "\nLetra " << mayuscula[i] << " escrita " << contador_mayusculas[i] << " veces";
	}
			
cout << "\n\n";
system("pause");
	
}
