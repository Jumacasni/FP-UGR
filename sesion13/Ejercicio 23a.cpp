/*
En este ejercicio, no hay que construir ninguna clase ni función. Es un ejercicio sobre recorridos de una matriz declarada directamente en 
el main.
Leed desde teclado dos variables util_filas y util_columnas y leed los datos de una matriz de enteros de tamaño util_filas x util_columnas. 
Sobre dicha matriz, se pide lo siguiente:
a) Calcular la traspuesta de la matriz, almacenando el resultado en otra matriz.
*/

#include <iostream>

using namespace std;

int main(){
	
	const int MAX_FILAS = 50, MAX_COLUMNAS = 50;
	int util_filas, util_columnas;
	int matriz [MAX_FILAS][MAX_COLUMNAS];
	int matriz_traspuesta [MAX_FILAS][MAX_COLUMNAS];
	
	cout << "Introduzca el número de filas de la matriz: ";
	cin >> util_filas;
	cout << "Introduzca el número de columnas de la matriz: ";
	cin >> util_columnas;
	
	// Pedimos datos
	
	cout << "Introduzca los datos de la matriz:\n";
	
	for (int i = 0 ; i < util_filas ; i++){
		for (int j = 0 ; j < util_columnas ; j++){
			cin >> matriz[i][j];
		}
	}
	
	// Cómputos
	
	for (int i = 0 ; i < util_filas ; i++){
		for (int j = 0 ; j < util_columnas ; j++){
			matriz_traspuesta[j][i] = matriz[i][j];
		}
	}
	
	// Salida 
	
	cout << "La matriz traspuesta es:\n";
	
	for (int i = 0 ; i < util_filas ; i++){
		for (int j = 0 ; j < util_columnas ; j++){
			cout << matriz_traspuesta[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n\n";
	system("pause");	
}
