/*
Se quiere construir una clase DepositoSimulacion para simular préstamos, ofreciendo la funcionalidad descrita en los ejercicios 19 (reinvierte 
capital e interés un número de años) y 20 (reinvierte capital e interés hasta obtener el doble de la cantidad inicial) de la relación de 
problemas II (página RP-II.7). Por tanto, la clase debe proporcionar, para un capital y unos intereses dados, métodos para:
a) Calcular el capital que se obtendrá al cabo de un número de años,
b) Calcular el número de años que deben pasar hasta obtener el doble de la cantidad
inicial.
¿Cuáles son sus datos miembro? Parece claro que el capital y el interés sí lo
serán ya que cualquier operación que se nos ocurra hacer con un objeto de la
clase DepositoSimulacion involucra a ambas cantidades. ¿Pero y el número
de años?
 ¿Qué constructor definimos?
 ¿Queremos modificar el capital y el interés una vez creado el objeto?
 ¿Queremos poder modificarlos de forma independiente?
 ¿Hay alguna restricción a la hora de asignar un valor al capital e interés?
 ¿Es mejor un método para calcular el número de años hasta obtener el doble de
la cantidad inicial, o por el contrario es mejor un método para calcular el número
de años hasta obtener una cantidad específica?
*/

#include <iostream>

using namespace std;

class DepositoSimulacion{
	private:
		double capital, interes;
		int anios = 1;
		int anios_hasta_doblar = 0;

		bool CapitalCorrecto(double numero){
			return numero >= 0;
		}
		
		bool InteresCorrecto(double numero){
			return 0 <= numero && numero <= 100;
		}
	public:
		
		// Constructor
		
		DepositoSimulacion(double capital, double interes){
			
			SetCapital(capital);
			SetInteres(interes);
		}
		
		// Métodos para el constructor
		
		void SetCapital(double dinero_capital){
			capital = dinero_capital;
		}
		
		void SetInteres(double porcentaje_interes){
			interes = porcentaje_interes;
		}
		
		// Métodos para modificar el interés y el capital
		
		void IngresaCapital(double cantidad){
			if (CapitalCorrecto(cantidad))
				capital = capital + cantidad;
		}
		
		void IngresaInteres(double cantidad_interes){
			if (InteresCorrecto(cantidad_interes))
				interes = interes + cantidad_interes;
		}
		
		// Métodos para obtener el capital obtenido al cabo de unos años y el número de años hasta doblar el capital
		
		double CapitalObtenido(int anio_final){
			
			double capital_total = capital;
			double total;
			
			do{
				total = capital_total + capital_total*(interes/100);
		
				anios++;
				capital_total = total;
				
			}while (anios <= anio_final );
			
			return total;
		}
		
		double AniosHastaDoblarCapital(){
			
			double total;
			double capital_total = capital;
			double doble_capital = 2*capital;
			
			do{
				total = capital_total + capital_total*(interes/100);
				anios_hasta_doblar++;
				capital_total = total;
			}while (capital_total < doble_capital);
			
			return anios_hasta_doblar;
		}

};
int main (){
	
	double capital, interes, capital_final;
	int anios, anio_final;
	
	cout << "Introduzca el capital: ";
	cin >> capital;
	cout << "Introduzca el interés: ";
	cin >> interes;
	cout << "Introduzca el número de años: ";
	cin >> anio_final;
	
	DepositoSimulacion capital_obtenido(capital, interes);
	DepositoSimulacion anios_hasta_doblar(capital, interes);
	
	capital_final = capital_obtenido.CapitalObtenido(anio_final);
	anios = anios_hasta_doblar.AniosHastaDoblarCapital();
	
	cout << "\nEl capital obtenido al cabo de " << anio_final << " años es de " << capital_final << " euros.";
	cout << "\nPasará/n " << anios << " año/s hasta doblar el capital inicial.";
}
