/*
En este ejercicio, no hay que construir ninguna clase ni función. Es un ejercicio sobre recorridos de una matriz declarada directamente en 
el main.
Leed desde teclado dos variables util_filas y util_columnas y leed los datos de una matriz de enteros de tamaño util_filas x util_columnas. 
Sobre dicha matriz, se pide lo siguiente:
d) Leer los datos de otra matriz y multiplicar ambas matrices (las dimensiones de la
segunda matriz han de ser compatibles con las de la primera para poder hacer la
multiplicación)
*/

#include <iostream>

using namespace std;

int main(){
	
	const int MAX_FILAS = 50, MAX_COLUMNAS = 50;
	int filas_primera_matriz, filas_segunda_matriz, columnas_primera_matriz, columnas_segunda_matriz, digito;
	int una_matriz [MAX_FILAS][MAX_COLUMNAS];
	int otra_matriz [MAX_FILAS][MAX_COLUMNAS];
	int matriz_multiplicada [MAX_FILAS][MAX_COLUMNAS];
	bool se_puede_multiplicar;
	
	cout << "Introduzca el número de filas de la primera matriz: ";
	cin >> filas_primera_matriz;
	cout << "Introduzca el número de columnas de la primera matriz: ";
	cin >> columnas_primera_matriz;
	cout << "Introduzca los datos de la primera matriz:\n\n";
	
	for (int i = 0 ; i < filas_primera_matriz ; i++){
		for (int j = 0 ; j < columnas_primera_matriz ; j++){
			una_matriz[i][j] = cin.get();
		}
	}
	
	cout << "\nIntroduzca el número de filas de la segunda matriz: ";
	cin >> filas_segunda_matriz;
	cout << "Introduzca el número de columnas de la segunda matriz: ";
	cin >> columnas_segunda_matriz;
	cout << "Introduzca los datos de la segunda matriz:\n\n";
	
	for (int i = 0 ; i < filas_segunda_matriz ; i++){
		for (int j = 0 ; j < columnas_segunda_matriz ; j++){
			otra_matriz[i][j] = cin.get();
		}
	}
	
	se_puede_multiplicar = (columnas_primera_matriz == filas_segunda_matriz);
	
	if (se_puede_multiplicar){
		
		for(int i = 0; i < filas_primera_matriz ; i++){
        	for(int j = 0 ; j < columnas_segunda_matriz; j++){
        		
        		digito = 0;
        		
         	for(int t = 0 ; t < columnas_primera_matriz; t++){
         		
                matriz_multiplicada[i][j] = digito + una_matriz[i][t] * otra_matriz[t][j];
                digito = matriz_multiplicada[i][j];
             }
          }
       }
	
		cout << "\nLa matriz multiplicada es:\n\n";
	
		for (int i = 0 ; i < filas_segunda_matriz ; i++){
			for (int j = 0 ; j < columnas_primera_matriz ; j++){
				cout << matriz_multiplicada[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	else
	
	cout << "\nLa matriz no se puede multiplicar";

	cout << "\n\n";
	system("pause");	
}
