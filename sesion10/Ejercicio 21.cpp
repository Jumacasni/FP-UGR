/*
Se quiere construir una clase DepositoSimulacion para simular pr�stamos, ofreciendo la funcionalidad descrita en los ejercicios 19 (reinvierte 
capital e inter�s un n�mero de a�os) y 20 (reinvierte capital e inter�s hasta obtener el doble de la cantidad inicial) de la relaci�n de 
problemas II (p�gina RP-II.7). Por tanto, la clase debe proporcionar, para un capital y unos intereses dados, m�todos para:
a) Calcular el capital que se obtendr� al cabo de un n�mero de a�os,
b) Calcular el n�mero de a�os que deben pasar hasta obtener el doble de la cantidad
inicial.
�Cu�les son sus datos miembro? Parece claro que el capital y el inter�s s� lo
ser�n ya que cualquier operaci�n que se nos ocurra hacer con un objeto de la
clase DepositoSimulacion involucra a ambas cantidades. �Pero y el n�mero
de a�os?
 �Qu� constructor definimos?
 �Queremos modificar el capital y el inter�s una vez creado el objeto?
 �Queremos poder modificarlos de forma independiente?
 �Hay alguna restricci�n a la hora de asignar un valor al capital e inter�s?
 �Es mejor un m�todo para calcular el n�mero de a�os hasta obtener el doble de
la cantidad inicial, o por el contrario es mejor un m�todo para calcular el n�mero
de a�os hasta obtener una cantidad espec�fica?
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
		
		// M�todos para el constructor
		
		void SetCapital(double dinero_capital){
			capital = dinero_capital;
		}
		
		void SetInteres(double porcentaje_interes){
			interes = porcentaje_interes;
		}
		
		// M�todos para modificar el inter�s y el capital
		
		void IngresaCapital(double cantidad){
			if (CapitalCorrecto(cantidad))
				capital = capital + cantidad;
		}
		
		void IngresaInteres(double cantidad_interes){
			if (InteresCorrecto(cantidad_interes))
				interes = interes + cantidad_interes;
		}
		
		// M�todos para obtener el capital obtenido al cabo de unos a�os y el n�mero de a�os hasta doblar el capital
		
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
	cout << "Introduzca el inter�s: ";
	cin >> interes;
	cout << "Introduzca el n�mero de a�os: ";
	cin >> anio_final;
	
	DepositoSimulacion capital_obtenido(capital, interes);
	DepositoSimulacion anios_hasta_doblar(capital, interes);
	
	capital_final = capital_obtenido.CapitalObtenido(anio_final);
	anios = anios_hasta_doblar.AniosHastaDoblarCapital();
	
	cout << "\nEl capital obtenido al cabo de " << anio_final << " a�os es de " << capital_final << " euros.";
	cout << "\nPasar�/n " << anios << " a�o/s hasta doblar el capital inicial.";
}
