/*
Tenga en cuenta la observación al inicio de esta relación de problemas sobre la lectura de los caracteres. Para poder leer caracteres, incluyendo 
los espacios en blanco, hay que usar caracter = cin.get(), en vez de cin >> caracter.
En este ejercicio trabajaremos con un vector directamente en el main, sin utilizar clases.
Declare un vector de caracteres de tamaño 100. Lea las componentes considerando como terminador el carácter # (éste no forma parte de la secuencia)
y que no se introduzcan más de 100 caracteres. Las componentes leídas ocuparán las primeras posiciones contiguas del vector. El resto de las 
posiciones se quedarán con el valor indeterminado (basura) que el compilador le asignase al principio. Para conocer cuántas componentes se están 
utilizando, utilice una variable total_utilizados (que, obviamente, deberá ser menor de 100 en todo momento)
Implemente algoritmos para realizar las siguientes tareas:
a) Comprobar si el vector es un palíndromo, es decir, que se lee igual de izquierda a derecha que de derecha a izquierda. Por ejemplo, 
{'a','b','b','a'} sería un palíndromo, pero {'a','c','b','a'} no lo sería. Si la secuencia tiene un número impar de componentes, la que ocupa 
la posición central es descartada, por lo que {'a','b','j','b','a'} sería un palíndromo.
b) Invertir el vector. Si éste contenía, por ejemplo, los caracteres {'m','u','n','d','o'}, después de llamar al método se quedará con
{'o','d','n','u','m'}.
c) Contar el número de mayúsculas que contiene.
*/

#include <iostream>

using namespace std;

bool EsMayuscula (char letra){

	return 'A' <= letra && letra <= 'Z';
}

int main(){
	
	const int MAX_CARACTERES = 100;
	char caracter[MAX_CARACTERES];
	double total_utilizados = 0;
	int derecha;
	bool es_palindromo = true;
	char TERMINADOR = '#';
	int i = 0;
	double tope;
	int numero_mayusculas = 0;
	
	// lectura de datos
	
	cout << "Introduzca las componentes (pulse # para terminar): ";
	caracter[i] = cin.get();
	
	while (i < 100 && caracter[i] != TERMINADOR){
		i++;
		total_utilizados++;
		caracter[i] = cin.get();
	}
	
	// Comprobar si el vector es palíndromo
	
	derecha = total_utilizados - 1;
	tope = total_utilizados / 2;
	
	for (i = 0; i < tope ; i++){
		
		if (caracter[i] != caracter[derecha])
			
			es_palindromo = false;
		
		derecha--;	
	}
	
	if (es_palindromo)
		cout << "\nEs palíndromo";
	else
		cout << "\nNo es palíndromo";
	
	// El vector al revés
	
	cout << "\n\nLas componentes escritas al revés son: ";
	
	derecha = total_utilizados - 1;
	
	for (i = 0 ; i < total_utilizados ; i++){
		
		cout << caracter[derecha];
		derecha--;
	}
	
	// Contar el número de mayúsculas introducidas
	
	for (i = 0 ; i < total_utilizados ; i++){
		
		if (EsMayuscula(caracter[i]))
			numero_mayusculas++;
	}
	
	cout << "\n\nHa introducido " << numero_mayusculas << " mayúsculas";
	
	cout << "\n\n";
	system("pause");
}
	
