/*
Cread una función que calcule el máximo entre tres double. La cabecera de la función será la siguiente:
double Max(double un_valor, double otro_valor, double el_tercero)
Construid un programa principal que llame a dicha función con unos valores leídos desde teclado. Supongamos que dichos valores los leemos con cin dentro 
de la propia función, en vez de hacerlo en el main. El suspenso está garantizado ¿Por qué?
*/

#include <iostream>

using namespace std;

double Max(double un_valor, double otro_valor, double el_tercero){		// Si leemos con cin dentro de la función, cuando termine la función los valores de los cin
																								// "se pierden" y ya no vamos a poder utilizarlos en el main
	if (un_valor >= otro_valor && un_valor >= el_tercero)
		return un_valor;
	else
		if (otro_valor >= un_valor && otro_valor >= el_tercero)
			return otro_valor;
		else
			return el_tercero;
}
int main(){
	
	double valor1, valor2, valor3, maximo;
	
	cout << "Introduzca tres valores (separados por un espacio en blanco): ";
	cin >> valor1;
	cin >> valor2;
	cin >> valor3;
	
	maximo = Max(valor1, valor2, valor3);
	
	cout << "\nEl máximo de los números introducidos es el " << maximo << "\n";
	
system("pause");
}
