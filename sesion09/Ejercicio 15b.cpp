/*
b) En vez de calcular la pendiente en el programa principal, vamos a ponerlo como un método de la clase y así lo reutilizaremos todas las veces 
que necesitemos. Añada un método para el cálculo de la pendiente y modificad el main para tener en cuenta este cambio.
¿Añadimos pendiente como dato miembro de la recta? La respuesta es que no ¿Por qué?
Añadir también los siguiente métodos:
	- Obtener la ordenada (y) dado un valor de abscisa x, aplicando la fórmula:
(-C -xA) / B
	- Obtener la abscisa (x) dado un valor de ordenada y, aplicando la fórmula:
(-C -yB) / A
En la función main leed un valor de abscisa e imprimir la ordenada según la recta y leed un valor de ordenada e imprimid la abscisa que le 
corresponde. Hacedlo sólo con la primera recta.
*/

#include <iostream>

using namespace std;

class Recta{
	public:
		
		double coeficiente_A, coeficiente_B, coeficiente_C;
		double x, y;
		
		double Pendiente(double coeficiente_A, double coeficiente_B){
		
			return - coeficiente_A / coeficiente_B;
		}
		
		double Ordenada (double x){
		
			return (-coeficiente_C - x*coeficiente_A) / coeficiente_B;
		}
		
		double Abscisa (double y){
		
			return (-coeficiente_C - y*coeficiente_B) / coeficiente_A;
		}
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
	cout << "Introduzca un valor de abscisa (x): ";
	cin >> una_recta.x;
	cout << "Introduzca un valor de ordenada (y): ";
	cin >> una_recta.y;
	
	cout << "\nLa pendiente de la primera recta es " << una_recta.Pendiente(una_recta.coeficiente_A, una_recta.coeficiente_B);
	cout << "\nLa pendiente de la segunda recta es " << otra_recta.Pendiente(otra_recta.coeficiente_A, otra_recta.coeficiente_B);
	cout << "\n\nEl valor de y en la primera recta en x = " << una_recta.x << " es " << una_recta.Ordenada(una_recta.x);
	cout << "\nEl valor de x en la primera recta en y = " << una_recta.y << " es " << una_recta.Abscisa(una_recta.y);

}
