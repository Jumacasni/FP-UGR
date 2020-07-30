/*
Sobre la clase SecuenciaCaracteres, a�ada el m�todo EliminaMayusculas para eliminar todas las may�sculas. Por ejemplo, despu�s de aplicar dicho 
m�todo al vector {'S','o','Y',' ','y','O'}, �ste debe quedarse con {'o',' ','y'}.
Un primer algoritmo para resolver este problema ser�a el siguiente (en ejercicios posteriores se ver�n m�todos m�s eficientes):
	// Recorrer todas las componentes de la secuencia
	// Si la componente es una may�scula, borrarla
Queremos implementarlo llamando al m�todo Elimina (que borra un �nico car�cter).La implementaci�n de este m�todo se ha visto en clase de teor�a.
class SecuenciaCaracteres{
.........
void EliminaMayusculasError(){
for (int i=0; i<total_utilizados; i++)
if (isupper(vector_privado[i]))
Elimina(i);
}
};

El anterior c�digo tiene un fallo. �Cu�l? Pru�belo con cualquier secuencia que tenga dos may�sculas consecutivas, proponer una soluci�n e implementarla.
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
	
	// Antes de eliminar las may�sculas
	
	cout << secuencia.ToString();
	
	secuencia.EliminaMayusculas();
	
	// Despu�s de eliminar las may�sculas
	
	cout << "\n" << secuencia.ToString();
	
cout << "\n\n";
system("pause");
	
}
