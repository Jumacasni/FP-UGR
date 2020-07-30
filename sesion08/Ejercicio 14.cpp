/*
En el ejercicio 28 se pedía presentar un menú de operaciones al usuario. Resolved
este ejercicio definiendo una función para leer la opción del usuario y definiendo otra
para calcular el máximo de dos números.
*/

#include <iostream>
#include <cctype>

using namespace std;

// Máximo de 2 números //

double Maximo (double numero1, double numero2){
	
	/*
	Calcular el máximo de los 2 números introducidos
	*/
	
	if (numero1 > numero2)
		return numero1;
	
	else
		return numero2;

}

// Elegir opción en el menú //

char Menu (string mensaje){
	
	/*
	Mostrar el menú para elegir opción.
	Repetir el menú mientras la opción elegida sea incorrecta.
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
	
	cout << "Introduzca dos números (separados por un espacio): ";
	cin >> numero1;
	cin >> numero2;
	
	opcion = Menu("--------------------\nI.\tIntroducir números\nS.\tSuma\nP.\tProducto\nM.\tMáximo\nR.\tSalir\n--------------------\nIntroduzca opción: ");

/*
Seguir trabajando con el menú mientras no seleccionemos la opción de salir
*/

while(opcion != 'R'){
	
	if (opcion == 'I'){
		cout << "Introduzca dos números (separados por un espacio): ";
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

	opcion = Menu("--------------------\nI.\tIntroducir números\nS.\tSuma\nP.\tProducto\nM.\tMáximo\nR.\tSalir\n--------------------\nIntroduzca opción: ");
}

	cout << "\nFin del ejercicio";
	
	cout << "\n\n";
	
	system("pause");	
}
