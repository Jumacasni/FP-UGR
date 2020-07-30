/*
Calcular mediante un programa en C++ el combinatorio (n|m) con n, m valores enteros. No pueden usarse las funciones de la biblioteca cmath.
El combinatorio de n sobre m (con n >= m) es un número entero que se define como
(n|m) = n! / (m! * (n - m)!)
*/

#include <iostream>

using namespace std;

int main(){
	
	int numero_n, numero_m, factorial_n, factorial_m, diferencia_n_m, factorial_n_m, combinatorio, contador;
	
	cout << "Introduzca un número entero n: ";
	cin >> numero_n;
	cout << "Introduzca un número entero m (menor que n): ";
	cin >> numero_m;
	
	while(numero_n <= numero_m){
		cout << "Introduzca un número entero m (menor que n): ";
		cin >> numero_m;
	}
	
	diferencia_n_m = numero_n - numero_m;
	
	// FACTORIAL DEL NÚMERO N //
	
	if (numero_n == 0)
		factorial_n = 1;
		
	else{
		factorial_n = numero_n - 1;
	
		for(contador = factorial_n ; contador > 1 ; contador--){
		
			numero_n = numero_n * factorial_n;
			factorial_n--;
	}
	
		factorial_n = numero_n;
}
	// FACTORIAL DEL NÚMERO M //
	
	if (numero_m == 0)
		factorial_m = 1;
		
	else{
		factorial_m = numero_m - 1;
	
		for(contador = factorial_m ; contador > 1 ; contador--){
		
			numero_m = numero_m * factorial_m;
			factorial_m--;
	}
	
		factorial_m = numero_m;
}
	// FACTORIAL DEL NÚMERO N - M //
	
	if (diferencia_n_m == 0)
		factorial_n_m = 1;
	
	else{
		factorial_n_m = diferencia_n_m - 1;
	
		for(contador = factorial_n_m ; contador > 1 ; contador--){
		
			diferencia_n_m = diferencia_n_m * factorial_n_m;
			factorial_n_m--;
	}
	
		factorial_n_m = diferencia_n_m;
}
	// CALCULAMOS EL COMBINATORIO //
	
	combinatorio = factorial_n / (factorial_m * factorial_n_m);
	
	cout << "\nEl combinatorio de n sobre m es " << combinatorio;
}
	
	
	
	
		
		
		
		
