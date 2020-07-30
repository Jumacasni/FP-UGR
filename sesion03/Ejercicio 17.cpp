/*
		Realizar un programa que declare las variables x, y y z, les asigne los valores 10, 20 y 30 e intercambien entre sí sus valores de forma que el valor de x pasa a y, el de y
	pasa a z y el valor de z pasa a x (se pueden declarar variables auxiliares aunque se pide que se use el menor número posible).
*/

#include <iostream>	// Inclusión de recursos de E/S

using namespace std;

int main(){
	
	int numero1 = 10;		// Declara variables para guardar los tres números a intercambiar
	int numero2 = 20;
	int numero3 = 30;
	int copia1;						// Variables para guardar auxiliares
	int copia2;
	
	cout << "Los números iniciales son x = " << numero1 << ", y = " << numero2 << ", z = " << numero3;
	
	copia1 = numero1;
	copia2 = numero3;
	numero1 = copia2;
	copia2 = numero2;
	numero2 = copia1;
	numero3 = copia2;
	
	cout << "\nLos números intercambiados son x = " << numero1 << ", y = " << numero2 << ", z = " << numero3;
}
