/*
	Queremos modificar el ejercicio 7 para leer un car�cter letra_original desde teclado
y hacer lo siguiente:
	Si es una letra may�scula, almacenaremos en la variable letra_convertida
la correspondiente letra min�scula.
	Si es una letra min�scula, almacenaremos en la variable letra_convertida
la correspondiente letra may�scula.
	Si es un car�cter no alfab�tico, almacenaremos el mismo car�cter en la variable
letra_convertida
	El programa debe imprimir en pantalla el valor de letra_convertida e indicar si la
letra introducida era una min�scula, may�scula o no era una car�cter alfab�tico. No
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
		
			cout << "\nEl valor del car�cter pedido es " << letra_convertida;
		
}
