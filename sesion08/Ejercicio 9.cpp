/*
Recuperad la soluci�n del ejercicio 15 de la Relaci�n de Problemas II (pasar de may�scula a min�scula y viceversa usando un enumerado). Para que el tipo de dato 
enumerado sea accesible desde dentro de las funciones, debemos ponerlo antes de definir �stas, es decir, en un �mbito global a todo el fichero. Se pide definir 
las siguientes funciones y cread un programa principal de ejemplo que las llame:

a) Capitalizacion nos dice si un car�cter pasado como par�metro es una min�scula, may�scula u otro car�cter. A dicho par�metro, llamadlo una_letra. La
funci�n devuelve un dato de tipo enumerado.

b) Convierte_a_Mayuscula comprueba si un car�cter pasado como par�metro es min�scula (para ello, debe llamar a la funci�n Capitalizacion), en cuyo
caso lo transforma a may�scula. Si el car�cter no es min�scula debe dejar la letra igual. A dicho par�metro, llamadlo caracter.
Esta funci�n hace lo mismo que la funci�n tolower de la biblioteca cctype. Observad que el par�metro una_letra de la funci�n Capitalizacion
podr�a llamarse igual que el par�metro caracter de la funci�n Convierte_a_Mayuscula. Esto es porque est�n en �mbitos distintos y
para el compilador son dos variables distintas. Haced el cambio y comprobarlo.

c) Convierte_a_Minuscula an�loga a la anterior pero convirtiendo a min�scula.
Observad que la constante de amplitud  const int AMPLITUD = 'a'-'A';
es necesaria declararla como constante local en ambas funciones. Para no repetir este c�digo, �qu� podemos hacer? Implemente la soluci�n adoptada.

d) CambiaMayusculaMinuscula, a la que se le pase como par�metro un char
y haga lo siguiente:
- si el argumento es una letra en may�scula, devuelve su correspondiente letra en min�scula,
- si el argumento es una letra en min�scula, devuelve su correspondiente letra en may�scula,
- si el argumento no es ni una letra may�scula, ni una letra may�scula, devuelve el car�cter pasado como argumento.
*/

#include <iostream>

using namespace std;

enum class TipoCaracter
	{mayuscula, minuscula, no_caracter};

// Saber qu� tipo de car�cter hemos introducido //

TipoCaracter Capitalizacion (char letra){

	bool letra_mayuscula, letra_minuscula;
	TipoCaracter tipo_caracter;
	
	letra_mayuscula = 'A' <= letra && letra <= 'Z';
	letra_minuscula = 'a' <= letra && letra <= 'z';
	
	if (letra_mayuscula)
		tipo_caracter = TipoCaracter::mayuscula;

	else
	
		if (letra_minuscula)
		tipo_caracter = TipoCaracter::minuscula;
		
		else
	
		tipo_caracter = TipoCaracter::no_caracter;
		
	return tipo_caracter;
}

const int AMPLITUD = 'a' - 'A';

// Convertir una letra a may�scula en caso de que sea min�scula //

char Convierte_a_mayuscula (char letra){
	
	TipoCaracter tipo_caracter;
	
	tipo_caracter = Capitalizacion(letra);
	
	if (tipo_caracter == TipoCaracter::minuscula)
	
	letra = letra - AMPLITUD;
	
	return letra;
}

// Convertir una letra a min�scula en caso de que sea may�scula //

char Convierte_a_minuscula (char letra){
	
	TipoCaracter tipo_caracter;
	
	tipo_caracter = Capitalizacion(letra);
	
	if (tipo_caracter == TipoCaracter::mayuscula)
	
	letra = letra + AMPLITUD;
	
	return letra;
}

// Cambiar una letra a may�scula en caso de que sea min�scula y viceversa //

char CambiaMayusculaMinuscula (char letra){
	
	TipoCaracter tipo_caracter;
	
	tipo_caracter = Capitalizacion(letra);
	
	if (tipo_caracter == TipoCaracter::minuscula)
	
	letra = letra - AMPLITUD;
	
	else
		if (tipo_caracter == TipoCaracter::mayuscula)
		
		letra = letra + AMPLITUD;
		
	return letra;
}
int main (){
	
	char segunda_funcion, una_letra, tercera_funcion, cuarta_funcion;
	TipoCaracter primera_funcion;
	
	cout << "Introduzca una letra: ";
	cin >> una_letra;
	
	/*
	Apartado A
	*/
	
	primera_funcion = Capitalizacion(una_letra);
		
	if (primera_funcion == TipoCaracter::mayuscula)
			cout << "\nHa introducido una may�scula";
	else
	
		if (primera_funcion == TipoCaracter::minuscula)
		cout << "\nHa introducido una min�scula";
		
		else
			cout << "\nHa introducido un car�cter que no es una letra may�scula o min�scula (no se convertir� en nada).";
	
	/*
	Apartado B
	*/
	
	segunda_funcion = Convierte_a_mayuscula(una_letra);
	
	cout << "\nSi es una letra min�scula se convierte en may�scula: " << segunda_funcion;
	
	/*
	Apartado C
	*/
	
	
	tercera_funcion = Convierte_a_minuscula(una_letra);
	
	cout << "\nSi es una letra may�scula se convierte en min�scula: " << tercera_funcion;
	
	/*
	Apartado D
	*/
	
	cuarta_funcion = CambiaMayusculaMinuscula(una_letra);
	
	cout << "\nSi es una letra may�scula se convierte en min�scula y viceversa: " << cuarta_funcion;
	
	cout << "\n\n";
	
	system("pause");

}
