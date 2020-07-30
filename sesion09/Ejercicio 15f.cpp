/*
f) Suprima ahora el método SetCoeficientes. De esta forma, una vez creado el objeto (pasándole los datos apropiados en el constructor) 
ya no podremos modificar los datos miembro. Esto es útil en aquellas situaciones en las que no queremos permitir que el estado del objeto 
cambie, una vez se ha creado.
*/

#include <iostream>

using namespace std;

class Recta{
	private:
		double coeficiente_A = 1, coeficiente_B = 1, coeficiente_C = 1;
		
	public:
		
		Recta(double A, double B, double C){
			coeficiente_A = A;
			coeficiente_B = B;
			coeficiente_C = C;
		}

		double Pendiente(){
			
			return -coeficiente_A / coeficiente_B;
		}
		
		double Ordenada (double x){
		
			return (-coeficiente_C - x*coeficiente_A) / coeficiente_B;
		}
		
		double Abscisa (double y){
		
			return (-coeficiente_C - y*coeficiente_B) / coeficiente_A;
		}
};

int main(){
	
	double PrimeraA, PrimeraB, PrimeraC, SegundaA, SegundaB, SegundaC, x, y;
	
	cout << "Introduzca los tres pimeros coeficientes de la primera recta (separados por un espacio): ";
	cin >> PrimeraA;
	cin >> PrimeraB;
	cin >> PrimeraC;

	Recta una_recta (PrimeraA, PrimeraB, PrimeraC);
	
	cout << "Introduzca los tres primeros coeficientes de la segunda recta (separados por un espacio): ";
	cin >> SegundaA;
	cin >> SegundaB;
	cin >> SegundaC;

	Recta otra_recta (SegundaA, SegundaB, SegundaC);
	
	cout << "Introduzca un valor de abscisa (x): ";
	cin >> x;
	cout << "Introduzca un valor de ordenada (y): ";
	cin >> y;
	
	cout << "\n\nLa pendiente de la primera recta es " << una_recta.Pendiente();
	cout << "\nLa pendiente de la segunda recta es " << otra_recta.Pendiente();
	cout << "\n\nEl valor de y en la primera recta en x = " << x << " es " << una_recta.Ordenada(x);
	cout << "\nEl valor de x en la primera recta en y = " << y << " es " << una_recta.Abscisa(y);

}
