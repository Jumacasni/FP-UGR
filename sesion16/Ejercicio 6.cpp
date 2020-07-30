/*
Recupere la solución del ejercicio 31 de la Relación de Problemas IV (elimina varios caracteres de una secuencia). 
Defina el método EliminaVarios sobre la clase SecuenciaCaracteres para que haga la tarea pedida. Tendrá que pasarle al método
un objeto de la clase SecuenciaEnteros con los índices de las posiciones a eliminar.
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

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 50;
  	char vector_privado[TAMANIO];
	int total_utilizados;
	   
	bool EsMayuscula (char letra){
	   return 'A' <= letra && letra <= 'Z';
	}
	
public:
   SecuenciaCaracteres()
     	:total_utilizados(0) {
   }
   	
  	int TotalUtilizados(){
  		return total_utilizados;
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
				
			for (int i = posicion ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];
				total_utilizados--;
		}
	}
   	
	char Elemento(int indice){
		return vector_privado[indice];
	}

	SecuenciaCaracteres EliminaVarios(SecuenciaEnteros numeros){
		
		int pos_escritura, pos_lectura;
		bool caracter_no_borrar;
		SecuenciaCaracteres nueva_palabra;
		
		numeros.Ordena();
	
		for (pos_lectura = 0; pos_lectura < TotalUtilizados(); pos_lectura++){
		
			caracter_no_borrar = true;
		
			for (int j = 0; j < numeros.TotalUtilizados() && caracter_no_borrar; j++){
				if (numeros.Elemento(j) == pos_lectura)
					caracter_no_borrar = false;
			}
		
			if (caracter_no_borrar){
			
				pos_escritura = pos_lectura;
				nueva_palabra.Aniade(Elemento(pos_escritura));
			}
		}
		return nueva_palabra;
	}
	
   string ToString(){
      string cadena;
      
      for (int i=0; i < total_utilizados; i++)
         cadena = cadena + vector_privado[i];
      
      return cadena;
   }
};

int main(){
	
	SecuenciaEnteros numeros;
	SecuenciaCaracteres palabra, nueva_palabra;
	int TERMINADOR1 = -1;
	char TERMINADOR = '#';
	char caracter;
	int numero;
	
	// LECTURA DE DATOS //
	
	cout << "Introduzca su palabra (pulse '#' para terminar): ";
	cin >> caracter;
	
	while (caracter != TERMINADOR){
		palabra.Aniade(caracter);
		cin >> caracter;
	}
	
	cout << "Introduzca las posiciones a eliminar (pulse -1 para terminar): ";
	cin >> numero;
	
	while (numero != TERMINADOR1){
		numeros.Aniade(numero);
		cin >> numero;
	}
	
	// CÓMPUTOS //
	
	nueva_palabra = palabra.EliminaVarios(numeros);
	
	// SALIDA DE DATOS //

	for (int i = 0; i < nueva_palabra.TotalUtilizados(); i++){
		cout << nueva_palabra.Elemento(i);
	}
	
	cout << "\n\n";
	system("pause");
}
