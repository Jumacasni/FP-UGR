/*
	Recupere la soluci�n del ejercicio 8 y resu�lvalo separando entradas y salidas de
los c�mputos. Para ello, utilice una variable de tipo enumerado que represente las
opciones de que un car�cter sea una may�scula, una min�scula o un car�cter no
alfab�tico.
*/
	
#include <iostream>

using namespace std;

enum class TipoCaracter
	{mayuscula, minuscula, no_caracter};
	
int main (){
	
	char letra_original, letra_convertida; 
	bool letra_mayuscula, letra_minuscula;
	TipoCaracter tipo_caracter;
	
	cout << "Introduzca una letra: ";
	cin >> letra_original;
	
	letra_mayuscula = 'A' <= letra_original && letra_original <= 'Z';
	letra_minuscula = 'a' <= letra_original && letra_original <= 'z';
	
	if (letra_mayuscula){
		
		letra_convertida = 'a' + (letra_original - 'A');
		tipo_caracter = TipoCaracter::minuscula;
		
}
	else
	
		if (letra_minuscula){
	
		letra_convertida = 'A' + (letra_original - 'a');
		tipo_caracter = TipoCaracter::mayuscula;
		
}
		else{
		
		letra_convertida = letra_original;
		tipo_caracter = TipoCaracter::no_caracter;
}
	if (tipo_caracter == TipoCaracter::minuscula)
	
		cout << "\nLa letra en min�scula es " << letra_convertida;

	if (tipo_caracter == TipoCaracter::mayuscula)
	
		cout << "\nLa letra en may�scula es " << letra_convertida;

	if (tipo_caracter == TipoCaracter::no_caracter)
	
		cout << "\nNo es una letra.";

}
