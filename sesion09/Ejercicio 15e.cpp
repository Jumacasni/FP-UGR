/*
e) Modifique el programa principal del último apartado e imprima los valores de los datos miembros de una recta, antes de asignarles los 
coeficientes. Mostrará, obviamente, un valor indeterminado. Para evitar este problema, añada un constructor a la recta para que el objeto esté 
en un estado válido en el mismo momento de su definición. El constructor deberá tener como parámetros, obligatoriamente, los tres coeficientes 
de la recta. Tendrá que modificar convenientemente el main para tener en cuenta este cambio.
*/

#include <iostream>

using namespace std;

class Recta{
	private:
		double coeficiente_A, coeficiente_B, coeficiente_C;
		
	public:
		
		Recta(double A, double B, double C){
			SetCoeficientes(A, B, C);
		}
		
		void SetCoeficientes(double coefA, double coefB, double coefC){
			coeficiente_A = coefA;
			coeficiente_B = coefB;
			coeficiente_C = coefC;
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
