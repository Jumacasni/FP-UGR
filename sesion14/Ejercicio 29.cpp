/*
(Examen Septiembre 2015) Buscaminas es un juego muy conocido cuyo objetivo es encontrar todas las minas existentes en un tablero rectangular, 
sin abrir ninguna. Si el jugador abre una mina, pierde la partida.
Se pide definir la clase TableroBuscaMinas conteniendo lo siguiente:
a) Para representar el tablero se trabajará con una matriz de datos 50 x 30 en la que todas las filas tienen el mismo número de columnas y 
los datos son de tipo bool. Contendrá un valor true en caso de haber una mina en la casilla especificada y false en caso contrario. 
Esta matriz será un dato miembro de la clase y al principio, todos los valores estarán a false.
b) Un método para incluir una mina en una determinada casilla.
c) Un método que reciba las coordenadas (i; j) de una casilla y devuelva un valor entero que indique el número de minas que rodean a la 
misma (será un número entre 0 y 8). En caso de que la casilla contenga una mina, se devolverá el valor -1.
Hay que tener especial cuidado con las casillas que hay en los bordes de la matriz ya que la casilla en la posición [0][0], por ejemplo, 
sólo tiene tres vecinos rodeándola.
Incluya un pequeño programa de prueba para asignar algunas minas y obtener las minas que hay alrededor de algunas casillas.
*/

#include <iostream>

using namespace std;

class TableroBuscaMinas{
	private:
		
		int NUM_FILAS = 50,
			 NUM_COLUMNAS = 30;
		bool matriz[50][30] = {{false},{false}};
		
		bool FilaCorrecta(int fila){
			return fila >= 0 && fila < NUM_FILAS;
		}
		
		bool ColumnaCorrecta(int columna){
			return columna >= 0 && columna < NUM_COLUMNAS;
		}
		
	public:
		
		void IncluirMina(int fila, int columna){
			if (FilaCorrecta(fila) && ColumnaCorrecta(columna))
				matriz[fila][columna] = true;
		}
		
		int BuscadorMinas(int fila, int columna){
			
			int numero_minas = 0;
			
			if (matriz[fila][columna])
				numero_minas = -1;
			
			else{
				for (int i = fila - 1; i <= fila + 1; i++){
					if (FilaCorrecta(i))
						for (int j = columna - 1; j <= columna + 1; j++){
							if (ColumnaCorrecta(j) && matriz[i][j])
								numero_minas++;
						}
				}
			}
			
			return numero_minas;	
		}
};

int main(){
	
	TableroBuscaMinas buscaminas;
	
	buscaminas.IncluirMina(0, 1);
	buscaminas.IncluirMina(1, 0);
	buscaminas.IncluirMina(1, 1);
	buscaminas.IncluirMina(21, 6);
	buscaminas.IncluirMina(21, 5);
	buscaminas.IncluirMina(19, 4);
	buscaminas.IncluirMina(19, 6);
	
	cout << buscaminas.BuscadorMinas(0, 0);
	cout << "\n" << buscaminas.BuscadorMinas(20, 5);
	

	
}
