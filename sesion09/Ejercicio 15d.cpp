/*
d) En vez de usar un método para asignar un valor a cada dato miembro, defina un único método SetCoeficientes 
para asignar los tres a la misma vez. Observad que los métodos permiten definir la política de acceso a los datos miembro. Si tengo previsto 
cambiar por separado los coeficientes de la recta, usaré métodos de asignación individuales. En caso contrario, usaré un único método
que modifique a la misma vez todos los datos miembro. Incluso pueden dejarse en la clase ambos tipos de métodos para que así el cliente 
de la clase pueda usar los que estime oportunos en cada momento. Por ahora, mantenga únicamente el método de asignación en bloque SetCoeficientes.
*/

#include <iostream>

using namespace std;

class Recta{
	private:
		double coeficiente_A, coeficiente_B, coeficiente_C;
		
	public:
	
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
	
	Recta una_recta;
	Recta otra_recta;
	double PrimeraA, PrimeraB, PrimeraC, SegundaA, SegundaB, SegundaC, x, y;
	
	cout << "Introduzca los tres pimeros coeficientes de la primera recta (separados por un espacio): ";
	cin >> PrimeraA;
	cin >> PrimeraB;
	cin >> PrimeraC;
	
	una_recta.SetCoeficientes(PrimeraA, PrimeraB, PrimeraC);
	
	cout << "Introduzca los tres primeros coeficientes de la segunda recta (separados por un espacio): ";
	cin >> SegundaA;
	cin >> SegundaB;
	cin >> SegundaC;
	
	otra_recta.SetCoeficientes(SegundaA, SegundaB, SegundaC);
	
	cout << "Introduzca un valor de abscisa (x): ";
	cin >> x;
	cout << "Introduzca un valor de ordenada (y): ";
	cin >> y;
	
	cout << "\nLa pendiente de la primera recta es " << una_recta.Pendiente();
	cout << "\nLa pendiente de la segunda recta es " << otra_recta.Pendiente();
	cout << "\n\nEl valor de y en la primera recta en x = " << x << " es " << una_recta.Ordenada(x);
	cout << "\nEl valor de x en la primera recta en y = " << y << " es " << una_recta.Abscisa(y);

}
