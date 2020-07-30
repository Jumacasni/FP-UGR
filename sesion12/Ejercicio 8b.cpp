/*
Sobre la clase SecuenciaCaracteres, añada un método EliminaRepetidos que quite los elementos repetidos, de forma que cada componente sólo 
aparezca una única vez. Se mantendrá la primera aparición, de izquierda a derecha. Por ejemplo, si la secuencia contiene
{'b','a','a','h','a','a','a','a','c','a','a','a','g'} después de quitar los repetidos, se quedaría como sigue:
{'b','a','h','c','g'}
Implemente los siguientes algoritmos para resolver ester problema:
a) Usando un vector local sin_repetidos en el que almacenamos una única aparición de cada componente:
	//Recorrer todas las componentes de la secuencia original
		Si la componente NO está en "sin_repetidos", añadirla (al vector "sin_repetidos")
	// Asignar las componentes de "sin_repetidos" a la secuencia
b) El problema del algoritmo anterior es que usa un vector local, lo que podría suponer una carga importante de memoria si trabajásemos con 
vectores grandes. Por lo tanto, vamos a resolver el problema sin usar vectores locales.
Si una componente está repetida, se borrará de la secuencia. Para borrar una componente, llamamos al método Elimina.
*/

#include <iostream>

using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 50;
   char vector_privado[TAMANIO];
   int total_utilizados;

public:
   SecuenciaCaracteres()
      :total_utilizados(0) {
   }
	
	char Elemento(int indice){
		return vector_privado[indice];
	}
	
   void Aniade(char nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }	
	
	void Elimina (int posicion){
		if (posicion >= 0 && posicion < total_utilizados){
			int tope = total_utilizados-1;
		
			for (int i = posicion ; i < tope ; i++){
				vector_privado[i] = vector_privado[i+1];
			}
			
			total_utilizados--;
		}
	}
	
	void EliminaRepetidos(){
		
		for (int i = 0 ; i < total_utilizados ; i++){
			for (int j = 0 ; j < total_utilizados ; j++){
				if (vector_privado[i] == vector_privado[j] && j != i){
					Elimina(j);
					j--;
				}
			}
		}
	}
		
   string ToString(){
      string cadena;
      
      for (int i=0; i < total_utilizados; i++)
         cadena = cadena + vector_privado[i];
      
      return cadena;
   }

};

int main (){
	
	SecuenciaCaracteres secuencia;
	
	secuencia.Aniade('a');
	secuencia.Aniade('l');
	secuencia.Aniade('v');
	secuencia.Aniade('a');
	secuencia.Aniade('r');
	secuencia.Aniade('o');

	
	// Antes de eliminar repetidos
	
	cout << "\n" << secuencia.ToString();
	
	secuencia.EliminaRepetidos();
	
	// Después de eliminar repetidos
	
	cout << "\n" << secuencia.ToString();
	
}
