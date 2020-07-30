/*
En este ejercicio no hay que construir ninguna función o clase. Todo se programará en el main. Defina dos matrices de reales original
y suavizada de tamaño 50 x 30. Lea desde teclado los valores de la matriz original, obligando a que sea simétrica. Para ello, lea el número de 
filas n y a continuación introduzca los n x n datos de la matriz.
Construya la matriz suavizada acorde a las siguientes indicaciones:
a) La tabla resultante será simétrica.
b) Los valores de la diagonal principal de la tabla resultante serán iguales a los de la tabla original.
c) Los valores del triángulo superior de la tabla resultante se calculan de la siguiente manera: si (i; j) es una posición en el 
triángulo superior de la tabla resultante, su valor es el valor medio de los valores que ocupan las posiciones de
las columnas j; j + 1; ... ; n - 1 en la fila i de la tabla original.
*/

#include <iostream>

using namespace std;

int main(){
	
	int NUM_FILAS = 50,
		 NUM_COLUMNAS = 30;
	int numero_filas, suma, numero_de_valores, media;
	double matriz_principal[NUM_FILAS][NUM_COLUMNAS],
			 matriz_suavizada[NUM_FILAS][NUM_COLUMNAS];
	bool es_simetrica = true;
	
	// LECTURA DE DATOS //
	
	cout << "Introduzca el número de filas: ";
	cin >> numero_filas;
	
		/* Comprobamos que el número de filas es correcto */
	
	while (numero_filas < 0 && numero_filas > 50){
		
		cout << "Introduzca el número de filas: ";
		cin >> numero_filas;
		
	}
	
	cout << "\nIntroduzca su matriz (tiene que ser simétrica):\n";
	
	for (int i = 0; i < numero_filas; i++){
		for (int j = 0; j < numero_filas; j++){
			cin >> matriz_principal[i][j];
		}
	}
	
	for (int i = 0; i < numero_filas && es_simetrica; i++){
		for (int j = 0; j < numero_filas && es_simetrica; j++){
			if (matriz_principal[i][j] != matriz_principal[j][i])
				es_simetrica = false;	
		}
	}
	
		/* Comprobamos que la matriz introducida es simétrica */
	
	while (!es_simetrica){
		
		cout << "\nIntroduzca su matriz (tiene que ser simétrica): ";
	
		for (int i = 0; i < numero_filas; i++){
			for (int j = 0; j < numero_filas; j++){
				cin >> matriz_principal[i][j];
			}
		}
		
		es_simetrica = true;
		
		for (int i = 0; i < numero_filas && es_simetrica; i++){
			for (int j = 0; j < numero_filas && es_simetrica; j++){
				if (matriz_principal[i][j] != matriz_principal[j][i])
					es_simetrica = false;	
			}
		}	
	}
	
	
	// CÓMPUTOS //
	
		/* Diagonal principal y triángulo inferior */
		
	for (int i = numero_filas - 1; i >= 0; i--){
		for (int j = i; j >= 0; j--){
			matriz_suavizada[i][j] = matriz_principal[i][j];
		}
	}	

		/* Triángulo superior */
	
	for (int i = 0; i < numero_filas; i++){
		for (int j = i + 1; j <= numero_filas - 1; j++){
			
			suma = 0;
			numero_de_valores = 0;
			
			for (int z = j ; z < numero_filas; z++){
				suma = suma + matriz_principal[i][z];
				numero_de_valores++;
			}
			
			media = suma / numero_de_valores;
			matriz_suavizada[i][j] = media;
		}
	}
	
	// SALIDA DE DATOS //
	
	cout << "\n";
	
	for (int i = 0; i < numero_filas; i++){
		for (int j = 0; j < numero_filas; j++){
			cout << matriz_suavizada[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n\n";
	system("pause");
}
