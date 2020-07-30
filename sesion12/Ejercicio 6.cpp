/*
Sobre la clase SecuenciaCaracteres, añada el método EliminaMayusculas para eliminar todas las mayúsculas. Por ejemplo, después de aplicar dicho 
método al vector {'S','o','Y',' ','y','O'}, éste debe quedarse con {'o',' ','y'}.
Un primer algoritmo para resolver este problema sería el siguiente (en ejercicios posteriores se verán métodos más eficientes):
	// Recorrer todas las componentes de la secuencia
	// Si la componente es una mayúscula, borrarla
Queremos implementarlo llamando al método Elimina (que borra un único carácter).La implementación de este método se ha visto en clase de teoría.
class SecuenciaCaracteres{
.........
void EliminaMayusculasError(){
for (int i=0; i<total_utilizados; i++)
if (isupper(vector_privado[i]))
Elimina(i);
}
};

El anterior código tiene un fallo. ¿Cuál? Pruébelo con cualquier secuencia que tenga dos mayúsculas consecutivas, proponer una solución e implementarla.
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
   
   	string ToString(){
      	string cadena;
      
      	for (int i=0; i < total_utilizados; i++)
         	cadena = cadena + vector_privado[i];
      
      	return cadena;
   	}
};

int main (){
	
	SecuenciaCaracteres secuencia;
	
	secuencia.Aniade('S');
	secuencia.Aniade('o');
	secuencia.Aniade('Y');
	secuencia.Aniade('Y');
	secuencia.Aniade('o');
	
	// Antes de eliminar las mayúsculas
	
	cout << secuencia.ToString();
	
	secuencia.EliminaMayusculas();
	
	// Después de eliminar las mayúsculas
	
	cout << "\n" << secuencia.ToString();
	
cout << "\n\n";
system("pause");
	
}
