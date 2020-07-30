/*
A�ada el m�todo IntercambiaComponentes para intercambiar dos componentes de la secuencia. Por ejemplo, si la secuencia contiene {'h','o','l','a'}, 
despu�s de intercambiar las componentes 1 y 3, se quedar�a con {'h','a','l','o'}.
�Qu� deber�a hacer este m�todo si los �ndices no son correctos? Modifique la implementaci�n del m�todo Invierte del ejercicio 4, para que lo 
haga llamando a IntercambiaComponentes. Imprima las componentes de la secuencia desde el main, antes y despu�s de llamar a dicho m�todo. 
Para ello, use el m�todo ToString() de la clase SecuenciaCaracteres.
*/

#include <iostream>

using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 100;
   char vector_privado[TAMANIO];
   int total_utilizados;
	
	bool EsMayuscula (char letra){
		return 'A' <= letra && letra <= 'Z';
	}
	
	bool IndicesCorrectos(int un_valor, int otro_valor){
		return (0 <= un_valor && un_valor < TAMANIO) && (0 <= otro_valor && otro_valor < TAMANIO);
	}
	
public:
   SecuenciaCaracteres()
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
   
   void Aniade(char nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, char nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }
	
   char Elemento(int indice){
      return vector_privado[indice];
   }
   
   string ToString(){
   	
      string cadena;
      
      for (int i = 0 ; i < total_utilizados ; i++)
         cadena = cadena + vector_privado[i];
      
      return cadena;
   }
   
   void Invierte (int uno, int otro){
		
		IntercambiaComponentes(uno, otro);
	}
	
	void IntercambiaComponentes(int i, int j){
		
		char copia_vector_i;
		
		if (IndicesCorrectos(i, j)){
			copia_vector_i = vector_privado[i];
			vector_privado[i] = vector_privado[j];
			vector_privado[j] = copia_vector_i;
		}
	}
};

int main(){
	
	SecuenciaCaracteres secuencia;
	double tope;
	int vectores_derecha;
	char caracter;
	char TERMINADOR = '#';
	
	// Lectura de datos
	
	cout << "Introduzca las componentes (pulse # para terminar): ";
	
	caracter = cin.get();
	
	while (caracter != TERMINADOR){
		
		secuencia.Aniade(caracter);
		caracter = cin.get();
	}
	
	// Imprimir las componentes antes de invertirlas
	
	cout << secuencia.ToString();
	
	// Intercambiar las componentes iniciales con las finales
	
	tope = secuencia.TotalUtilizados() / 2;
	vectores_derecha = secuencia.TotalUtilizados() - 1;
	
	for (int i = 0 ; i < tope ; i++){
		
		secuencia.IntercambiaComponentes(i, vectores_derecha);
		vectores_derecha--;
	}
	
	// Imprimir las componentes despu�s de invertirlas
	
	cout << "\n" << secuencia.ToString();
	
	cout << "\n\n";
	system("pause");	
}
