/*
Recupere la solución del ejercicio 30 de la Relación de Problemas IV (palabras similares).
Sobre la clase SecuenciaCaracteres, definid un método que compruebe si la secuencia es similar a otra.
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
		
		void EliminaMayusculas(){
			for (int i = 0; i < total_utilizados; i++){
				if (EsMayuscula(vector_privado[i])){
					Elimina(i);
					i--;
				}
			}
    	}
   	
		char Elemento(int indice){
			return vector_privado[indice];
		}
	
   	bool EsSimilar(SecuenciaCaracteres otra_secuencia){
   		
   		SecuenciaCaracteres procesados;
   		bool similar = true,
   				seguir = true;
   		
   		if (Elemento(0) == otra_secuencia.Elemento(0) && Elemento(9) == otra_secuencia.Elemento(9) && TotalUtilizados() == otra_secuencia.TotalUtilizados()){
		
				int numero_apariciones_una_palabra = 0;
				int numero_apariciones_otra_palabra = 0;
		
				for(int i = 1; i < TotalUtilizados() - 1 && similar; i++){
				
					for (int k = 0; 0 < procesados.TotalUtilizados(); i++){
						if (Elemento(i) == procesados.Elemento(k))
							seguir = false;
					}
				
					if (seguir){
						for (int j = 1; j < TotalUtilizados() - 1; j++){
							if (Elemento(j) == Elemento(i))
								numero_apariciones_una_palabra++;
						}
			
						for (int z = 1; z < otra_secuencia.TotalUtilizados() - 1; z++){
							if (otra_secuencia.Elemento(z) == Elemento(i))
								numero_apariciones_otra_palabra++;
						}
			
						if (numero_apariciones_una_palabra != numero_apariciones_otra_palabra)
							similar = false;
					}
				}
			}
				return similar;	
   	}
   	
   	string ToString(){
      	string cadena;
      
      	for (int i=0; i < total_utilizados; i++)
         	cadena = cadena + vector_privado[i];
      
      	return cadena;
   	}
};

int main(){
	
	SecuenciaCaracteres una_palabra, otra_palabra;
	
	una_palabra.Aniade('t');
	una_palabra.Aniade('o');
	una_palabra.Aniade('t');
	una_palabra.Aniade('a');
	una_palabra.Aniade('l');
	una_palabra.Aniade('m');
	una_palabra.Aniade('e');
	una_palabra.Aniade('n');
	una_palabra.Aniade('t');
	una_palabra.Aniade('e');
	
	otra_palabra.Aniade('t');
	otra_palabra.Aniade('t');
	otra_palabra.Aniade('a');
	otra_palabra.Aniade('l');
	otra_palabra.Aniade('o');
	otra_palabra.Aniade('m');
	otra_palabra.Aniade('n');
	otra_palabra.Aniade('t');
	otra_palabra.Aniade('e');
	otra_palabra.Aniade('e');
	
	if (una_palabra.EsSimilar(otra_palabra))
		cout << "Son similares";
	else
		cout << "No son similares";
}
