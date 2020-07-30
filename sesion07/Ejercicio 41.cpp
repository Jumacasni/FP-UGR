/*
Escribid un programa que lea cuatro valores de tipo char (min_izda, max_dcha, min_dcha, max_dcha) e imprima las parejas que
pueden formarse con un elemento del conjunto {min_izda ... max_izda} y otro elemento del conjunto {min_dcha ... max_dcha}. Por ejemplo, si
min_izda = b, max_izda = d, min_dcha = j, max_dcha = m, el programa debe imprimir las parejas que pueden formarse con un elemento de {b c d} y otro
elemento de {j k l m}.
*/

#include <iostream>

using namespace std;

int main(){
	
	char min_izda, max_izda, min_dcha, max_dcha, contador_izda, contador_dcha;
	
	cout << "Introduzca cuatro valores separados por un espacio: ";
	cin >> min_izda;
	cin >> max_izda;
	cin >> min_dcha;
	cin >> max_dcha;
	
	for (contador_izda = min_izda; contador_izda <= max_izda; contador_izda ++){
		cout << "\n";

		for (contador_dcha = min_dcha; contador_dcha <= max_dcha; contador_dcha ++){
		cout << contador_izda << contador_dcha << " ";
	}
}
system("pause");
}
	
