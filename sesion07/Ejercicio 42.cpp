/*
(Examen Septiembre 2014) ¿Cuántas veces aparece el dígito 9 en todos los números que hay entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los números 19 y
92 mientras que aparece dos veces en el 99. Pretendemos diseñar un algoritmo que responda a esta sencilla pregunta, pero de forma suficientemente generalizada. 
Para ello, se pide construir un programa que lea una cifra (entre 1 y 9), dos enteros min y max y calcule el número de apariciones del dígito cifra en los 
números contenidos en el intervalo cerrado [min, max].
*/

#include <iostream>

using namespace std;

int main(){
	
	int min, max, cifra, copia_min, digito, digito_cifra;
	int contador_apariciones = 0;
	
	cout << "--Introduzca un intervalo--\n\n~Introduzca el mínimo: ";
	cin >> min;
	cout << "~Introduzca el máximo: ";
	cin >> max;
	cout << "\nIntroduzca la cifra a contar: ";
	cin >> cifra;

	for (digito = min; digito <= max; digito++){			
		copia_min = digito;
											
		while (copia_min != 0){
			digito_cifra = copia_min % 10;																			
			if (digito_cifra == cifra)												
				contador_apariciones++;

			copia_min = copia_min / 10;								
		}
}

	cout << "\nEl dígito aparece " << contador_apariciones << " veces en el intervalo introducido\n";

system("pause");
}
