/*
c) Cambie ahora los datos miembro públicos y póngalos privados. Tendrá que añadir métodos para asignar y ver los valores de los datos miembro. 
Añada métodos para asignar un valor a cada uno de los tres datos miembro. Modifique el main para tener en cuenta estos cambios.
*/

#include <iostream>

using namespace std;

class Recta{
	private:
		double coeficiente_A = 0, coeficiente_B = 0, coeficiente_C = 0;
		
	public:
	
		void SetValorA(double coefA){
			coeficiente_A = coefA;
		}
		
		void SetValorB(double coefB){
			coeficiente_B = coefB;
		}
		
		void SetValorC(double coefC){
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
	
	Recta una_recta;
	Recta otra_recta;
	double PrimeraA, PrimeraB, PrimeraC, SegundaA, SegundaB, SegundaC, x, y;
	
	cout << "Introduzca los tres pimeros coeficientes de la primera recta (separados por un espacio): ";
	cin >> PrimeraA;
	cin >> PrimeraB;
	cin >> PrimeraC;
	
	una_recta.SetValorA(PrimeraA);
	una_recta.SetValorB(PrimeraB);
	una_recta.SetValorC(PrimeraC);
	
	cout << "Introduzca los tres primeros coeficientes de la segunda recta (separados por un espacio): ";
	cin >> SegundaA;
	cin >> SegundaB;
	cin >> SegundaC;
	
	otra_recta.SetValorA(SegundaA);
	otra_recta.SetValorB(SegundaB);
	otra_recta.SetValorC(SegundaC);
	
	cout << "Introduzca un valor de abscisa (x): ";
	cin >> x;
	cout << "Introduzca un valor de ordenada (y): ";
	cin >> y;
	
	cout << "\nLa pendiente de la primera recta es " << una_recta.Pendiente();
	cout << "\nLa pendiente de la segunda recta es " << otra_recta.Pendiente();
	cout << "\n\nEl valor de y en la primera recta en x = " << x << " es " << una_recta.Ordenada(x);
	cout << "\nEl valor de x en la primera recta en y = " << y << " es " << una_recta.Abscisa(y);

}
