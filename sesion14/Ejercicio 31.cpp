/*
Defina la clase SecuenciaEnteros análoga a SecuenciaCaracteres pero para que trabaje sobre enteros. Defina en el main un vector clásico 
de corchetes de tipo de dato char. Lea desde el main varios caracteres y asígnelos al vector de char. Lea
también varios enteros y asígnelos a un objeto de la clase SecuenciaEnteros. Implemente ahora directamente en el main un algoritmo para que 
elimine eficientemente todas las posiciones indicadas en la secuencia de enteros. Por ejemplo, si el vector de caracteres contiene Fundamentos, 
después de eliminar el conjunto de posiciones dado por 2 5 3, el vector se quedará como Fuaentos.
Se recomienda implementar el siguiente algoritmo:
	Utilizar dos índices: pos_escritura y pos_lectura que marquen las posiciones de lectura y escritura en el vector de char
	
	Ordenar la secuencia de enteros
	
	Recorrer con pos_lectura los caracteres del vector de char
		Si el carácter actual no está en una posición a borrar, colocarlo en pos_escritura.
*/

#include <iostream>

using namespace std;

class SecuenciaEnteros{
private:
   static const int TAMANIO = 100;
   int vector_privado[TAMANIO];
   int total_utilizados;
	
public:
   SecuenciaEnteros()
      :total_utilizados(0) {
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Aniade(int nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Ordena(){
		
		int izda, i;
		int a_desplazar;
		
		for (izda = 1; izda < total_utilizados; izda++){
			a_desplazar = vector_privado[izda];
			
			for (i = izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
				vector_privado[i] = vector_privado[i-1];
				
		vector_privado[i] = a_desplazar;
		}
	}
	
   void Modifica(int posicion, int nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }
	
   char Elemento(int indice){
      return vector_privado[indice];
   }
};

int main(){
	
	SecuenciaEnteros numeros;
	int numero, pos_escritura, pos_lectura;
	int NUM_CARACTERES = 20, TERMINADOR1 = -1, i = 0, total_utilizados = 0;
	char TERMINADOR = '#';
	char palabra[NUM_CARACTERES], palabra_nueva[NUM_CARACTERES], caracter;
	bool caracter_no_borrar;
	
	// LECTURA DE DATOS //
	
	cout << "Introduzca su palabra (pulse '#' para terminar): ";
	cin >> caracter;
	
	while (caracter != TERMINADOR){
		palabra[i] = caracter;
		i++;
		cin >> caracter;
	}
	
	cout << "Introduzca varios enteros (pulse -1 para terminar): ";
	cin >> numero;
	
	while (numero != TERMINADOR1){
		numeros.Aniade(numero);
		cin >> numero;
	}
	
	// CÓMPUTOS //
	
	numeros.Ordena();
	
	for (pos_lectura = 0; pos_lectura < i; pos_lectura++){
		
		caracter_no_borrar = true;
		
		for (int j = 0; j < numeros.TotalUtilizados() && caracter_no_borrar; j++){
			if (numeros.Elemento(j) == pos_lectura)
				caracter_no_borrar = false;
		}
		
		if (caracter_no_borrar){
			
			pos_escritura = pos_lectura;
			palabra_nueva[total_utilizados] = palabra[pos_escritura];
			total_utilizados++;
		}
	}
	
	// SALIDA DE DATOS //
	
	i = 0;
	
	while (i < total_utilizados){
		cout << palabra_nueva[i];
		i++;
	}
	
	cout << "\n\n";
	system("pause");
}
