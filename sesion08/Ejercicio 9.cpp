/*
Recuperad la solución del ejercicio 15 de la Relación de Problemas II (pasar de mayúscula a minúscula y viceversa usando un enumerado). Para que el tipo de dato 
enumerado sea accesible desde dentro de las funciones, debemos ponerlo antes de definir éstas, es decir, en un ámbito global a todo el fichero. Se pide definir 
las siguientes funciones y cread un programa principal de ejemplo que las llame:

a) Capitalizacion nos dice si un carácter pasado como parámetro es una minúscula, mayúscula u otro carácter. A dicho parámetro, llamadlo una_letra. La
función devuelve un dato de tipo enumerado.

b) Convierte_a_Mayuscula comprueba si un carácter pasado como parámetro es minúscula (para ello, debe llamar a la función Capitalizacion), en cuyo
caso lo transforma a mayúscula. Si el carácter no es minúscula debe dejar la letra igual. A dicho parámetro, llamadlo caracter.
Esta función hace lo mismo que la función tolower de la biblioteca cctype. Observad que el parámetro una_letra de la función Capitalizacion
podría llamarse igual que el parámetro caracter de la función Convierte_a_Mayuscula. Esto es porque están en ámbitos distintos y
para el compilador son dos variables distintas. Haced el cambio y comprobarlo.

c) Convierte_a_Minuscula análoga a la anterior pero convirtiendo a minúscula.
Observad que la constante de amplitud  const int AMPLITUD = 'a'-'A';
es necesaria declararla como constante local en ambas funciones. Para no repetir este código, ¿qué podemos hacer? Implemente la solución adoptada.

d) CambiaMayusculaMinuscula, a la que se le pase como parámetro un char
y haga lo siguiente:
- si el argumento es una letra en mayúscula, devuelve su correspondiente letra en minúscula,
- si el argumento es una letra en minúscula, devuelve su correspondiente letra en mayúscula,
- si el argumento no es ni una letra mayúscula, ni una letra mayúscula, devuelve el carácter pasado como argumento.
*/

#include <iostream>

using namespace std;

enum class TipoCaracter
	{mayuscula, minuscula, no_caracter};

// Saber qué tipo de carácter hemos introducido //

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

// Convertir una letra a mayúscula en caso de que sea minúscula //

char Convierte_a_mayuscula (char letra){
	
	TipoCaracter tipo_caracter;
	
	tipo_caracter = Capitalizacion(letra);
	
	if (tipo_caracter == TipoCaracter::minuscula)
	
	letra = letra - AMPLITUD;
	
	return letra;
}

// Convertir una letra a minúscula en caso de que sea mayúscula //

char Convierte_a_minuscula (char letra){
	
	TipoCaracter tipo_caracter;
	
	tipo_caracter = Capitalizacion(letra);
	
	if (tipo_caracter == TipoCaracter::mayuscula)
	
	letra = letra + AMPLITUD;
	
	return letra;
}

// Cambiar una letra a mayúscula en caso de que sea minúscula y viceversa //

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
			cout << "\nHa introducido una mayúscula";
	else
	
		if (primera_funcion == TipoCaracter::minuscula)
		cout << "\nHa introducido una minúscula";
		
		else
			cout << "\nHa introducido un carácter que no es una letra mayúscula o minúscula (no se convertirá en nada).";
	
	/*
	Apartado B
	*/
	
	segunda_funcion = Convierte_a_mayuscula(una_letra);
	
	cout << "\nSi es una letra minúscula se convierte en mayúscula: " << segunda_funcion;
	
	/*
	Apartado C
	*/
	
	
	tercera_funcion = Convierte_a_minuscula(una_letra);
	
	cout << "\nSi es una letra mayúscula se convierte en minúscula: " << tercera_funcion;
	
	/*
	Apartado D
	*/
	
	cuarta_funcion = CambiaMayusculaMinuscula(una_letra);
	
	cout << "\nSi es una letra mayúscula se convierte en minúscula y viceversa: " << cuarta_funcion;
	
	cout << "\n\n";
	
	system("pause");

}
