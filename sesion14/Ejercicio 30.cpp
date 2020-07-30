/*
Sgeún un etsduio de una uivenrsdiad ignlsea, no ipmotra el odren en el que las ltears etsan ersciats, la úicna csoa ipormtnate es que la 
pmrirea y la útlima ltera etsén ecsritas en la psioción cocrrtea. El rsteo peuden estar ttaolmntee mal y aún pordás lerelo sin pobrleams. 
Etso es pquore no lemeos cada ltera por sí msima snio la paalbra cmoo un tdoo.
Diremos que dos palabras son similares si la primera letra de ambas palabras es igual, la última letra de ambas palabras también es igual y 
el resto de las letras son las mismas pero no están necesariamente en las mismas posiciones. De esta forma, las palabras ttalomntee y totalmente 
son similares.
Declare en el main dos objetos de la clase SecuenciaCaracteres y asígneles algunos caracteres de prueba. Implemente en el main un algoritmo 
que compruebe si los dos objetos son similares según el criterio anterior.
Si lo necesita, puede añadir los métodos que estime oportunos a la clase SecuenciaCaracteres.
Si le sirve de ayuda, utilice como base la descripción del siguiente algoritmo:
	Usaremos una secuencia de letras ya procesadas
		Comparar las primeras y últimas letras de cada palabra
		Si son iguales:
			Recorrer el resto de letras:
				Si la letra no está en la secuencia de procesadas:
					Añadirla a procesadas
					Contar el número de apariciones de la letra en cada palabra
					Si el número de apariciones es distinto, no son similares
*/

#include <iostream>

using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 100;
   char vector_privado[TAMANIO];
   int total_utilizados;
	
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
};

int main(){
	
	SecuenciaCaracteres una_palabra, otra_palabra;
	int numero_apariciones_una_palabra, numero_apariciones_otra_palabra;
	bool similar = true;
	
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
	
	if (una_palabra.Elemento(0) == otra_palabra.Elemento(0) && una_palabra.Elemento(9) == otra_palabra.Elemento(9) && una_palabra.TotalUtilizados() == otra_palabra.TotalUtilizados()){
		
		numero_apariciones_una_palabra = 0;
		numero_apariciones_otra_palabra = 0;
		
		for(int i = 1; i < una_palabra.TotalUtilizados() - 1 && similar; i++){
			
			for (int j = 1; j < una_palabra.TotalUtilizados() - 1; j++){
				if (una_palabra.Elemento(j) == una_palabra.Elemento(i))
					numero_apariciones_una_palabra++;
			}
			
			for (int z = 1; z < otra_palabra.TotalUtilizados() - 1; z++){
				if (otra_palabra.Elemento(z) == una_palabra.Elemento(i))
					numero_apariciones_otra_palabra++;
			}
			
			if (numero_apariciones_una_palabra != numero_apariciones_otra_palabra)
				similar = false;
		}
	}
	
	if (similar)
		cout << una_palabra.ToString() << " y " << otra_palabra.ToString() << " son palabras similares";
	else
		cout << una_palabra.ToString() << " y " << otra_palabra.ToString() << " no son palabras similares";
	
	cout << "\n\n";
	system("pause");
}
