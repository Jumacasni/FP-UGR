/*
	Se quiere leer un carácter letra_original desde teclado, y comprobar con una
estructura condicional si es una letra mayúscula. En dicho caso, hay que calcular
la minúscula correspondiente almacenando el resultado en una variable llamada
letra_convertida. En el caso de que no sea una mayúscula, le asignaremos a
letra_convertida el valor que tenga letra_original. Finalmente, imprimiremos
en pantalla el valor de letra_convertida. No pueden usarse las funciones
tolower ni toupper de la biblioteca cctype.	
*/

#include <iostream>

using namespace std;

int main (){
	
	char letra_original;
	char letra_convertida;
	
	cout << "Introduzca una letra: ";
	cin >> letra_original;
	
	if ('A' <= letra_original && letra_original <= 'Z'){
		
		letra_convertida = 'a' + (letra_original - 'A');
		
		cout << "\nEl valor de la letra pedida es " << letra_convertida;
}
	else
	
		if ('a' <= letra_original && letra_original <= 'z'){
	
		letra_convertida = letra_original;
		
			cout << "\nEl valor de la letra pedida es " << letra_convertida;
}
		else
		
			cout << "\nNo es una letra";

}
