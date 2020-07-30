/*
Recuperad el ejercicio 12 de esta relación de problemas sobre la función gaussiana.
En vez de trabajar con funciones, plantead la solución con una clase.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Gaussiana{
	private:
		double esperanza, desviacion, abscisa;
		
	public:
		
		// Constructor
		
		Gaussiana(double esperanza, double desviacion, double valor_abscisa){
			
			SetEsperanza(esperanza);
			SetDesviacion(desviacion);
			SetValorAbscisa(valor_abscisa);
		}
		
		// Métodos para el constructor
		
		void SetEsperanza(double valor_esperanza){
			esperanza = valor_esperanza;
		}
		
		void SetDesviacion(double valor_desviacion){
			desviacion = valor_desviacion;
		}
		void SetValorAbscisa(double valor_abscisa){
			abscisa = valor_abscisa;
		}
		
		// Métodos para obtener términos que nos hacen falta para calcular ambas fórmulas
		
		double Valor_Tipificado(){
			
			return (abscisa - esperanza) / desviacion;
		}
		
		double Exponente(){
		
			return -0.5 * Valor_Tipificado() * Valor_Tipificado();
		}
		
		// Métodos para calcular las funciones pedidas
		
		double Funcion_Gaussiana(double PI){
			
			return exp(Exponente()) / (desviacion * sqrt(2*PI));
		}
		
		double CDF(double b0, double b1, double b2, double b3, double b4, double b5, double PI){
			
			double t;
			
			t = 1 / (1 + b0*abscisa);
			return 1 - Funcion_Gaussiana(PI)*(b1 * t + b2 * pow(t, 2) + b3 * pow(t, 3) + b4 * pow(t, 4) + b5 * pow(t, 5));
		}
			
};

int main(){

	double esperanza, desviacion, valor_abscisa;                         
	int contador_numero_abscisa, numero_abscisa;
	const double PI = 3.1415927;
	const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782, b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
   
	cout << "Introduzca la esperanza: ";
	cin >> esperanza;
	cout << "Introduzca la desviacion: ";
	cin >> desviacion;
	cout << "Introduzca el número de abscisas que se van a procesar: ";
	cin >> numero_abscisa;
	cout << "Introduzca el valor de las abscisas (separado por espacios): ";
	
	// Cada valor de abscisa introducido calcula el valor de la función gaussiana y la distribución acumulada
	
	for (contador_numero_abscisa = 0; contador_numero_abscisa < numero_abscisa; contador_numero_abscisa++){
	
		cin >> valor_abscisa;
		
		Gaussiana un_valor(esperanza, desviacion, valor_abscisa);
	
		cout << "\nEl valor de la función gaussiana en " << valor_abscisa << " es " << un_valor.Funcion_Gaussiana(PI);
		
		cout << "\nLa distribución acumulada en x = " << valor_abscisa << " es " << un_valor.CDF(b0, b1, b2, b3, b4, b5, PI) << "\n";
		
	}
	cout << "\n\n";
	
	system("pause");
}
