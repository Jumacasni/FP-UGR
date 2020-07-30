/*
Recupere la solución del ejercicio 32 de la Relación de Problemas IV (Replace). Defina sobre la clase SecuenciaCaracteres el método Replace para 
que haga la tarea pedida. Tendrá que pasarle al método la posición inicial, el número de caracteres a eliminar y el objeto de la clase
SecuenciaCaracteres conteniendo la secuencia de caracteres de reemplazo.
*/

#include <iostream>

using namespace std;

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
	
	void Modifica(int posicion, char nuevo){
		vector_privado[posicion] = nuevo;
	}
	
	void Replace (int inicio, int numero_caracteres_a_reemplazar, SecuenciaCaracteres secuencia_nueva){
		
		int componentes_a_desplazar, lectura, escritura, siguiente;
		
		componentes_a_desplazar = TotalUtilizados() - inicio - numero_caracteres_a_reemplazar;
		
		if (numero_caracteres_a_reemplazar > secuencia_nueva.TotalUtilizados()){
			// Hay que acortar //
			lectura = inicio + numero_caracteres_a_reemplazar;
			escritura = inicio + secuencia_nueva.TotalUtilizados() - 1;
			siguiente = 1;
		}
		
		else{
			// Hay que alargar //
			lectura = TotalUtilizados() - 1;
			escritura = TotalUtilizados() - 2 - numero_caracteres_a_reemplazar + secuencia_nueva.TotalUtilizados();
			siguiente = -1;
		}
		
		componentes_a_desplazar = TotalUtilizados() - inicio - numero_caracteres_a_reemplazar;
		for (int i = 0; i < componentes_a_desplazar; i++){
			vector_privado[escritura] = vector_privado[lectura];
			escritura = escritura + siguiente;
			lectura = lectura + siguiente;
		}
	
		for (int i = 1; i < secuencia_nueva.TotalUtilizados(); i++){
			vector_privado[inicio] = secuencia_nueva.Elemento(i);
			inicio++;
		}
		
		total_utilizados = total_utilizados - numero_caracteres_a_reemplazar + secuencia_nueva.TotalUtilizados() - 1;
	}
	
   string ToString(){
      string cadena;
      
      for (int i=0; i < total_utilizados; i++)
         cadena = cadena + vector_privado[i];
      
      return cadena;
   }
};

int main(){
	
	SecuenciaCaracteres secuencia, secuencia_replace;
	
	int pos, n;
	char caracter, caracter_a_reemplazar;
	char TERMINADOR = '#';
	
	// LECTURA DE DATOS //	
	
	cout << "Introduzca una cadena de caracteres: ";
	caracter = cin.get();

	while (caracter != TERMINADOR){
		secuencia.Aniade(caracter);
		caracter = cin.get();
	}
	
	cout << "\nIntroduzca los caracteres para reemplazar: ";
	caracter_a_reemplazar = cin.get();
	
	while (caracter_a_reemplazar != TERMINADOR){
		secuencia_replace.Aniade(caracter_a_reemplazar);
		caracter_a_reemplazar = cin.get();
	}
	
	cout << "\nIntroduzca la posición en la que va a empezar a reemplazar: ";
	cin >> pos;
	
	cout << "\nIntroduzca cuántos caracteres va a reemplazar: ";
	cin >> n;
	
	// CÓMPUTOS //
	
	secuencia.Replace(pos, n, secuencia_replace);
	
	// SALIDA DE DATOS //
	
	cout << "\n";
	
	for (int i = 0; i < secuencia.TotalUtilizados(); i++){
		
		cout << secuencia.Elemento(i);
	}
}
