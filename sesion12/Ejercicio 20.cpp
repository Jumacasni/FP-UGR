/*
(Examen Septiembre Doble Grado 2013) Defina la clase SecuenciaEnteros análoga a SecuenciaCaracteres. Defina lo que sea necesario para calcular 
el número de secuencias ascendentes del vector. Por ejemplo, el vector {2,4,1,1,7,2,1} tiene 4 secuencias que son {2,4}, {1,1,7}, {2}, {1}.
*/

#include <iostream>
#include <string>

using namespace std;


class SecuenciaEnteros{
private:
   static const int TAMANIO = 50;
   int vector_privado[TAMANIO];
   int total_utilizados, total_secuencias;
   
public:
   SecuenciaEnteros()
      :total_utilizados(0), total_secuencias(0)	{
   }

   void Aniade(int nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
	void ContarSecuencias(){
		int i = 0;
		
   	for (i = 0 ; i < total_utilizados ; i++){
   		if (vector_privado[i] > vector_privado[i + 1]){
   			total_secuencias++;
   		}
   	}
   }
   
   int GetContarSecuencias(){
   	return total_secuencias;
   }
   		
   string ToString(){
      string cadena, numero;
      
      for (int i=0; i < total_utilizados; i++){
      	numero = to_string(vector_privado[i]);
         cadena = cadena + numero;
      }
      
      return cadena;
   }
};

int main(){
	
	SecuenciaEnteros secuencia;
	
	secuencia.Aniade(2);
	secuencia.Aniade(4);
	secuencia.Aniade(1);
	secuencia.Aniade(1);
	secuencia.Aniade(7);
	secuencia.Aniade(2);
	secuencia.Aniade(1);
	
	secuencia.ContarSecuencias();
	cout << secuencia.GetContarSecuencias();
	
	cout << "\n";
	system("pause");
}
	
