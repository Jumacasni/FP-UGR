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
	
	void EliminaRepetidos(){
		const int TAMANIO_SIN_REPETIDOS = 50;
		char vector_sin_repetidos[TAMANIO_SIN_REPETIDOS];
		bool repetida;
		int total_sin_repetidos = 0;
		
		vector_sin_repetidos[0] = vector_privado[0];
		total_sin_repetidos++;
		
		for (int i = 1 ; i < total_utilizados ; i++){
			
			repetida = false;
			
			for  (int j = 0 ; j < total_sin_repetidos && !repetida ; j++){
				if (vector_privado[i] == vector_sin_repetidos[j])
					repetida = true;
			}
			
			if (!repetida){
				vector_sin_repetidos[total_sin_repetidos] = vector_privado[i];
				total_sin_repetidos++;
			}
			
		}
		
		EliminaTodos();
		for (int i = 0 ; i < total_sin_repetidos ; i++){
			Aniade(vector_sin_repetidos[i]);
		}
			
	}
	
	void EliminaTodos(){
      total_utilizados = 0;
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
		
   string ToString(){
      string cadena;
      
      for (int i=0; i < total_utilizados; i++)
         cadena = cadena + vector_privado[i];
      
      return cadena;
   }
};

int main (){
	
	SecuenciaCaracteres secuencia;
	
	secuencia.Aniade('b');
	secuencia.Aniade('a');
	secuencia.Aniade('a');
	secuencia.Aniade('h');
	secuencia.Aniade('a');
	secuencia.Aniade('a');
	secuencia.Aniade('a');
	secuencia.Aniade('a');
	secuencia.Aniade('c');
	secuencia.Aniade('a');
	secuencia.Aniade('a');
	secuencia.Aniade('a');
	secuencia.Aniade('g');
	
	// Antes de eliminar repetidos
	
	cout << "\n" << secuencia.ToString();
	
	secuencia.EliminaRepetidos();
	
	// Después de eliminar repetidos
	
	cout << "\n" << secuencia.ToString();
	
}
	
	
	
