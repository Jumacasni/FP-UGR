/*
	Recupere la solución del ejercicio 8 y resuélvalo separando entradas y salidas de
los cómputos. Para ello, utilice una variable de tipo enumerado que represente las
opciones de que un carácter sea una mayúscula, una minúscula o un carácter no
alfabético.
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
	
		cout << "\nLa letra en minúscula es " << letra_convertida;

	if (tipo_caracter == TipoCaracter::mayuscula)
	
		cout << "\nLa letra en mayúscula es " << letra_convertida;

	if (tipo_caracter == TipoCaracter::no_caracter)
	
		cout << "\nNo es una letra.";

}
