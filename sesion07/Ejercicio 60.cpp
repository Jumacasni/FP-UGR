/*
Se dice que un número es triangular si se puede poner como la suma de los primeros m valores enteros, para algún valor de m. Por ejemplo, 6 es triangular ya que 
6 = 1 + 2 + 3. Se pide construir un programa que obtenga todos los números triangulares que hay menores que un entero tope introducido desde teclado.
*/

#include <iostream>

using namespace std;

int main(){
	
	int inicio, tope;
	int numero_triangular = 1;
	
	cout << "Introduzca un número entero: ";
	cin >> tope;
	
	cout << "\nLos números triangulares que hay menores que el número introducido son el ";
	
	for(inicio = 2; numero_triangular <= tope; inicio++){
			
		cout << numero_triangular << " ";
			
		numero_triangular = numero_triangular + inicio;
		
}
cout << "\n";
system("pause");
}
		
		
