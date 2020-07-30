/*
Cread un programa que ofrezca en pantalla la siguiente salida:
1 2 3 4 5 6
2 3 4 5 6
3 4 5 6
4 5 6
5 6
6
*/

#include <iostream>

using namespace std;

int main(){
	
	int TOPE = 6;
	int contador, numero, copia_numero;
	
	copia_numero = 1;
	
	for (contador = 1; contador <= TOPE; contador++){
		for (numero = copia_numero; numero <= TOPE; numero++){
		cout << numero << " ";
}
	copia_numero++;	
	cout << "\n";
}
system("pause");
}
	
