/*
A�ada los m�todos EsPalindromo, Invierte y NumeroMayusculas a la clase SecuenciaCaracteres que implementen las tareas descritas en el 
ejercicio 1 de esta relaci�n de problemas. Incluya un programa principal de prueba similar al del ejercicio 1.
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
   
   // M�todo para comprobar si el vector es pal�ndromo
   
   bool EsPalindromo(){
   	
   	bool es_palindromo = true;
   	int derecha = total_utilizados - 1;
   	double tope = total_utilizados / 2;
   	
   	for (int i = 0; i < tope ; i++){
		
			if (vector_privado[i] != vector_privado[derecha])
			
				es_palindromo = false;
		
			derecha--;
		}
		
		return es_palindromo;
	}
	
	// M�todo para invertir las componentes
	
	char Invierte (int derecha){
		
		return vector_privado[derecha];
	}
	
	// M�todo para contar las may�sculas de las componentes
	// Recorrer todos los vectores y comprobar si son may�sculas
	
	int NumeroMayusculas(){
		
		int numero_mayusculas = 0;
	
		for (int i = 0 ; i < total_utilizados ; i++){
		
			if (EsMayuscula(vector_privado[i]))
				numero_mayusculas++;
		}
		
		return numero_mayusculas;
	}
	
};

int main(){
	
	SecuenciaCaracteres secuencia;
	int derecha;
	char caracter;
	char TERMINADOR = '#';
	
	// Lectura de datos
	
	cout << "Introduzca las componentes (pulse # para terminar): ";
	
	caracter = cin.get();
	
	while (i < 100 && caracter != TERMINADOR){
		
		secuencia.Aniade(caracter);
		caracter = cin.get();
	}
	
	// Llamada al m�todo EsPalindromo
	
	if (secuencia.EsPalindromo())
		cout << "\nEs un pal�ndromo";
	else
		cout << "\nNo es un pal�ndromo";
	
	// Llamada al metodo Invierte
	
	cout << "\n\nLas componentes escritas al rev�s son: ";
	
	derecha = secuencia.TotalUtilizados() - 1;
	
	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++){
		
		cout << secuencia.Invierte(derecha);
		derecha--;
	}
	
	// Llamada al m�todo NumeroMayusculas
	
	cout << "\n\nHa introducido " << secuencia.NumeroMayusculas() << " may�sculas";
	
	cout << "\n\n";
	system("pause");
}
