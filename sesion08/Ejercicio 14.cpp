/*
En el ejercicio 28 se ped�a presentar un men� de operaciones al usuario. Resolved
este ejercicio definiendo una funci�n para leer la opci�n del usuario y definiendo otra
para calcular el m�ximo de dos n�meros.
*/

#include <iostream>
#include <cctype>

using namespace std;

// M�ximo de 2 n�meros //

double Maximo (double numero1, double numero2){
	
	/*
	Calcular el m�ximo de los 2 n�meros introducidos
	*/
	
	if (numero1 > numero2)
		return numero1;
	
	else
		return numero2;

}

// Elegir opci�n en el men� //

char Menu (string mensaje){
	
	/*
	Mostrar el men� para elegir opci�n.
	Repetir el men� mientras la opci�n elegida sea incorrecta.
	*/
	
	bool opciones_menu;
	char opcion;
	
do{
	
	cout << mensaje;
	cin >> opcion;
	opcion = toupper(opcion);
	
	opciones_menu = (opcion != 'S' && opcion != 'P' && opcion != 'M' && opcion != 'I' && opcion != 'R');
	
	}while(opciones_menu);

	return opcion;
}

int main(){
	
	double numero1, numero2, resultado;
	char opcion;
	
	cout << "Introduzca dos n�meros (separados por un espacio): ";
	cin >> numero1;
	cin >> numero2;
	
	opcion = Menu("--------------------\nI.\tIntroducir n�meros\nS.\tSuma\nP.\tProducto\nM.\tM�ximo\nR.\tSalir\n--------------------\nIntroduzca opci�n: ");

/*
Seguir trabajando con el men� mientras no seleccionemos la opci�n de salir
*/

while(opcion != 'R'){
	
	if (opcion == 'I'){
		cout << "Introduzca dos n�meros (separados por un espacio): ";
		cin >> numero1;
		cin >> numero2;
		cout << "\n\n";
		
}
	else
		if (opcion == 'S'){
			resultado = numero1 + numero2;
			cout << "\n" << resultado << "\n\n";
}
		else
			if (opcion == 'P'){
				resultado = numero1 * numero2;
				cout << "\n" << resultado << "\n\n";
}
			else
				if (opcion == 'M'){
					resultado = Maximo(numero1, numero2);
					cout << "\n" << resultado << "\n\n";
}

	opcion = Menu("--------------------\nI.\tIntroducir n�meros\nS.\tSuma\nP.\tProducto\nM.\tM�ximo\nR.\tSalir\n--------------------\nIntroduzca opci�n: ");
}

	cout << "\nFin del ejercicio";
	
	cout << "\n\n";
	
	system("pause");	
}
