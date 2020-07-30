/*
Recupere la solución del ejercicio 28 de la Relación de Problemas IV. En este ejercicio se pedía construir una matriz suavizada promedio. 
Se quiere hacer lo mismo pero sobre una clase MatrizCuadradaReales, por lo que debe implementar el siguiente método:
MatrizCuadradaReales SuavizadaPromedio(){
En decsai se encuentra el código principal de la clase, así como de la clase SecuenciaReales y el programa principal. Complete el código 
implementando el método SuavizadaPromedio y la llamada desde el main.
*/

#include <iostream>
using namespace std;

class SecuenciaReales{
private:
   static  const  int  TAMANIO  =  50;
   double  vector_privado[TAMANIO];
   int  total_utilizados;
public:
   SecuenciaReales()
      :total_utilizados(0)
   {
   }

   int  TotalUtilizados(){
      return  total_utilizados;
   }

   void  Aniade(double nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   double Elemento(int indice){
      return  vector_privado[indice];
   }

   void Modifica(int indice_componente, double nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }

   void EliminaTodos(){
      total_utilizados = 0;
   }

   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, double buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }

   int PrimeraOcurrencia (double buscado){
      return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
   }
   

   void Ordena_por_Insercion(){
      int izda, i;
      int a_desplazar;

      for (izda = 1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i = izda; i>0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
};


/*
	Para obligar a que una matriz sea cuadrada,
   lo podemos hacer de varias formas. Por ejemplo:
   
	a) En el constructor de la matriz pasamos el número de columnas que
      tendrán todas las filas de la amtriz.
      
	b) En el constructor de la matriz pasamos una primera fila.
      La longitud actual de dicha fila será el valor que
      determine el número de columnas de todas las filas. 
      
	Para permitir ambas formas, sobrecargamos el constructor.
	
	En cualquier caso, es importante destacar que la matriz no
	estará en un estado válido hasta que se hayan añadido
	todas las filas, ya que es una matriz cuadrada.
	Para paliar este problema, añadimos un método EsCuadrada
	que nos dice si la matriz es cuadrada en un momento determinado.
*/

class MatrizCuadradaReales{
private:
   static const int MAX_FILAS_COLUMNAS = 40;
   double matriz_privada[MAX_FILAS_COLUMNAS][MAX_FILAS_COLUMNAS];
   const int util_fil_col = 0;
   int indice_ultima_fila_aniadida = -1;
   
   void AsignaFila (SecuenciaReales fila, int indice_fila){
      for (int i=0; i < util_fil_col; i++)
         matriz_privada[indice_fila][i] = fila.Elemento(i);
   }
public:
   MatrizCuadradaReales(SecuenciaReales primera_fila)
      :util_fil_col(primera_fila.TotalUtilizados())
   {
      AniadeFila(primera_fila);
      indice_ultima_fila_aniadida = 0;
   }

	MatrizCuadradaReales(int numero_columnas)
      :util_fil_col(numero_columnas)
   {
   }
   
   double Elemento (int fil, int col){
      return matriz_privada[fil][col];
   }

   int NumeroFilas_y_Columnas(){
      return util_fil_col;
   }
   
   bool EsCuadrada(){
      return util_fil_col == indice_ultima_fila_aniadida + 1;
   }

   void AniadeFila(SecuenciaReales nueva_fila){
      if (indice_ultima_fila_aniadida < MAX_FILAS_COLUMNAS){
         if (nueva_fila.TotalUtilizados() == util_fil_col){
            indice_ultima_fila_aniadida++;
            AsignaFila(nueva_fila, indice_ultima_fila_aniadida);
         }
      }
   }
   
   SecuenciaReales Fila(int indice_fila){
      SecuenciaReales fila;
      
      for (int i=0; i < util_fil_col; i++){
         fila.Aniade(matriz_privada[indice_fila][i]);
      }
      return fila;
   }
   
   MatrizCuadradaReales SuavizadaPromedio(){
      
      MatrizCuadradaReales suavizada(util_fil_col);
      SecuenciaReales fila;
      double matriz_suavizada[MAX_FILAS_COLUMNAS][MAX_FILAS_COLUMNAS];
      double numero_de_valores, suma, media;
      
     		/* Diagonal principal */
		
		for (int i = 0; i < util_fil_col; i++){
			matriz_suavizada[i][i] = matriz_privada[i][i];
		}	

		/* Triángulo superior e inferior*/
	
		for (int i = 0; i < util_fil_col; i++){
			for (int j = i + 1; j <= util_fil_col - 1; j++){
			
				suma = 0;
				numero_de_valores = 0;
			
				for (int z = j ; z < util_fil_col; z++){
					suma = suma + matriz_privada[i][z];
					numero_de_valores++;
				}
			
				media = suma / numero_de_valores;
				matriz_suavizada[i][j] = media;
				matriz_suavizada[j][i] = media;
			}
		}
		
		for (int i = 0; i < util_fil_col; i++){
			for (int j = 0; j < util_fil_col; j++){
				fila.Aniade(matriz_suavizada[i][j]);
			}
			suavizada.AniadeFila(fila);
			fila.EliminaTodos();
		}
		
    	return suavizada;
   }
};


int main(){
   int util_filas_matriz, util_filas_suavizada;
   double valor;
   SecuenciaReales fila;

   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas > 0
	cout << "Introduzca el número de filas: ";
   cin >> util_filas_matriz;
   
   MatrizCuadradaReales matriz(util_filas_matriz);

	cout << "\nIntroduzca su matriz:\n";
	
   for (int i=0; i<util_filas_matriz; i++){
      for (int j=0; j<util_filas_matriz; j++){
         cin >> valor;
         fila.Aniade(valor);
      }
      
      matriz.AniadeFila(fila);
      fila.EliminaTodos();
   }

   if (matriz.EsCuadrada()){
     	
		MatrizCuadradaReales suavizada(matriz.SuavizadaPromedio());
		
      util_filas_suavizada = suavizada.NumeroFilas_y_Columnas();
   	
      cout << "\n\n";
      cout << "Matriz suavizada:\n";

      for (int i=0; i<util_filas_suavizada; i++){
         cout << "\n";

         for (int j=0; j<util_filas_suavizada; j++)
            cout << suavizada.Elemento(i,j) << '\t';
      }
   }
  
   cout << "\n\n";

   // Entrada:
   // 4   9 7 4 5    2 18 2 12    7 9 1 5   0 1 2 3
   
   // Salida:
   /*
   9       5.33333 4.5     5
   5.33333 18      7       12
   4.5     7       1       5
   5       12      5       3
   */
}
