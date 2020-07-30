/*
(Examen Septiembre 2014) �Cu�ntas veces aparece el d�gito 9 en todos los n�meros que hay entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los n�meros 19 y
92 mientras que aparece dos veces en el 99. Pretendemos dise�ar un algoritmo que responda a esta sencilla pregunta, pero de forma suficientemente generalizada. 
Para ello, se pide construir un programa que lea una cifra (entre 1 y 9), dos enteros min y max y calcule el n�mero de apariciones del d�gito cifra en los 
n�meros contenidos en el intervalo cerrado [min, max].
*/

#include <iostream>

using namespace std;

int main(){
	
	int min, max, cifra, copia_min, digito, digito_cifra;
	int contador_apariciones = 0;
	
	cout << "--Introduzca un intervalo--\n\n~Introduzca el m�nimo: ";
	cin >> min;
	cout << "~Introduzca el m�ximo: ";
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

	cout << "\nEl d�gito aparece " << contador_apariciones << " veces en el intervalo introducido\n";

system("pause");
}
