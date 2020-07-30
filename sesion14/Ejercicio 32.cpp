/*
Existe un método para la clase string de C++, denominado replace, que cambia n caracteres de una cadena cad1, empezando en
una determinada posición pos, por los caracteres presentes en una segunda cadena cad2. La llamada al método es cad1.replace(pos, n, cad2). 
Ejemplos del funcionamiento de replace son:
	string cad1="Fundament Programación        ";
		cad1.replace(9,2,"os de la"); // "al" -> "os de la" // Ahora cad1 tiene "Fundamentos de la Programación"
		cad1.replace(12,5,"en"); // "de la" -> "en" // Ahora cad1 tiene "Fundamentos en Programación"
Puede observar que, dependiendo de la cadena a insertar y de las posiciones especificadas, la secuencia final puede ser más grande o más pequeña 
que la original. Se quiere realizar esta tarea pero directamente en el main, trabajando sobre dos vectores de corchetes y sin ninguna clase. 
Se pide construir un programa que leerá caracteres hasta el terminador # y los almacenará en el primer vector y de nuevo leerá
caracteres hasta llegar a un segundo # y almacenará los datos en el segundo vector. A continuación, el programa leerá dos enteros pos y n 
y procederá a reemplazar los n caracteres que hay a partir de la posición pos del primer vector, con los caracteres del segundo vector.
Restricciones para este ejercicio: No se puede utilizar la clase string en ninguna parte del programa, debe hacerse lo más eficiente posible y 
no puede utilizarse un tercer vector en el que se vaya almacenando el resultado, es decir, las modificaciones deben hacerse directamente sobre el primer vector.
*/

#include <iostream>

using namespace std;

int main(){
	
	int NUM_CARACTERES = 100, total_utilizados_primer_vector = 0, total_utilizados_segundo_vector = 0;
	int pos, n, z, j, k;
	char primer_vector[NUM_CARACTERES], segundo_vector[NUM_CARACTERES], caracter, caracter_a_reemplazar;
	char TERMINADOR = '#';
	
	// LECTURA DE DATOS //	
	
	cout << "Introduzca una cadena de caracteres: ";
	caracter = cin.get();

	while (caracter != TERMINADOR){
		primer_vector[total_utilizados_primer_vector] = caracter;
		total_utilizados_primer_vector++;
		caracter = cin.get();
	}
	
	cout << "\nIntroduzca los caracteres para reemplazar: ";
	caracter_a_reemplazar = cin.get();
	
	while (caracter_a_reemplazar != TERMINADOR){
		segundo_vector[total_utilizados_segundo_vector] = caracter_a_reemplazar;
		total_utilizados_segundo_vector++;
		caracter_a_reemplazar = cin.get();
	}
	
	cout << "\nIntroduzca la posición en la que va a empezar a reemplazar: ";
	cin >> pos;
	
	cout << "\nIntroduzca cuántos caracteres va a reemplazar: ";
	cin >> n;
	
	// CÓMPUTOS //
	
		/* Eliminar los caracteres que se van a reemplazar */
		
	z = 0;
	
	while (z < n){
		
		for (int i = pos; i < total_utilizados_primer_vector; i++){
		
			primer_vector[i] = primer_vector[i+1];
		}
		
		z++;
	}


	
	// SALIDA DE DATOS //
	
	cout << "\n";
	
	for (int i = 0; i < total_utilizados_primer_vector + total_utilizados_segundo_vector - 1; i++){
		
		cout << primer_vector[i];
	}
}
