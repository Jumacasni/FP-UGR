/*
Se desea implementar una clase Recta para representar una recta en el plano. Una recta viene determinada por tres coeficientes 
A, B, C, de forma que todos los puntos (x,y) que pertenecen a la recta verifican lo siguiente (ecuación general de la recta):
Ax + By + C = 0

a) Definición de la clase y creación de objetos
Defina la clase Recta. En este apartado utilice únicamente datos miembro públicos. Cree un programa principal que haga lo siguiente:
	- Defina dos objetos de la clase Recta.
	- Lea seis reales desde teclado.
	- Le asigne los tres primeros a los coeficientes de una recta y los otros tres a la segunda recta.
	- Calcule e imprima la pendiente de cada recta aplicando la fórmula:
pendiente = - A / B
*/

#include <iostream>

using namespace std;

class Recta{
	public:
		
		double coeficiente_A, coeficiente_B, coeficiente_C;
		double pendiente;
		
};

int main(){
	
	Recta una_recta;
	Recta otra_recta;
	
	cout << "Introduzca los tres pimeros coeficientes de la primera recta (separados por un espacio): ";
	cin >> una_recta.coeficiente_A;
	cin >> una_recta.coeficiente_B;
	cin >> una_recta.coeficiente_C;
	cout << "Introduzca los tres primeros coeficientes de la segunda recta (separados por un espacio): ";
	cin >> otra_recta.coeficiente_A;
	cin >> otra_recta.coeficiente_B;
	cin >> otra_recta.coeficiente_C;
	
	una_recta.pendiente = - una_recta.coeficiente_A / una_recta.coeficiente_B;
	otra_recta.pendiente = - otra_recta.coeficiente_A / otra_recta.coeficiente_B;
	
	cout << "\nLa pendiente de la primera recta es " << una_recta.pendiente;
	cout << "\nLa pendiente de la segunda recta es " << otra_recta.pendiente;

}
	
