/*
	Queremos modificar el ejercicio 7 para leer un carácter letra_original desde teclado
y hacer lo siguiente:
	Si es una letra mayúscula, almacenaremos en la variable letra_convertida
la correspondiente letra minúscula.
	Si es una letra minúscula, almacenaremos en la variable letra_convertida
la correspondiente letra mayúscula.
	Si es un carácter no alfabético, almacenaremos el mismo carácter en la variable
letra_convertida
	El programa debe imprimir en pantalla el valor de letra_convertida e indicar si la
letra introducida era una minúscula, mayúscula o no era una carácter alfabético. No
pueden usarse las funciones tolower ni toupper de la biblioteca cctype.
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
}
	else
	
		if ('a' <= letra_original && letra_original <= 'z'){
	
		letra_convertida = 'A' + (letra_original - 'a');
}
		else
		
		letra_convertida = letra_original;
		
			cout << "\nEl valor del carácter pedido es " << letra_convertida;
		
}
