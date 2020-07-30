/*
Cread un programa que ofrezca en pantalla la siguiente salida:
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
5 6 7 8 9 10
6 7 8 9 10 11
*/

#include <iostream>

using namespace std;

int main(){
	
	int TOPE_LINEAS_Y_NUMEROS = 6;
	int numeros_fila, numero, contador, copia_numero;
	
	copia_numero = 0;
	
	for (contador = 1; contador <= TOPE_LINEAS_Y_NUMEROS; contador++){
		
		copia_numero++;
		numero = copia_numero;
		
		for (numeros_fila = 1; numeros_fila <= TOPE_LINEAS_Y_NUMEROS; numeros_fila++){
			
			cout << numero << " ";
			numero++;			
		}
		
		cout << "\n";
	}
system("pause");
}
