/* 
	Programa para calcular la población en China dentro de 2 años, considerando que la población actual es de 1.375.570.814 personas.
	Consideramos también que nace una persona cada 1.87 segundos, muere una persona cada 3.27 segundos y
	emigra una persona cada 71.9 segundos.
*/

#include <iostream>	// Inclusión de recursos de E/S
using namespace std;

int main(){															// Programa principal
	
	long long poblacion_final;									// Declaramos variable para guardar la población final de China
	const double poblacion_actual	= 1375570814;			// Población actual de China
	const double tiempo_nacimientos = 1.87; 				// Declaramos estas constantes porque nace una persona cada 1.87 segundos,
	const double tiempo_fallecimientos = 3.27;			// muere una persona cada 3.27 segundos,
	const double tiempo_emigraciones = 71.9;				// emigra una persona cada 71.9 segundos y
	const double segundos = 63072000;						// dos años son 63072000 segundos
	
	poblacion_final = segundos / tiempo_nacimientos - segundos / tiempo_fallecimientos - segundos / tiempo_emigraciones + poblacion_actual;
	
	cout << "\nLa población de China en dos años será de " << poblacion_final << " habitantes.";
}
	
	
