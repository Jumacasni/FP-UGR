/*
Recupere la soluci�n del ejercicio 6 de esta relaci�n de problemas (c�mputo del salario en funci�n de las horas trabajadas). Defina una clase 
Nomina para gestionar el c�mputo del salario final. Suponga que el porcentaje de incremento en la cuant�a de las horas extras (50 %) y el 
n�mero de horas que no se tarifan como extra (40) son valores que podr�an cambiar, aunque no de forma continua. El n�mero de horas trabajadas
y la cuant�a a la que se paga cada hora extraordinaria, s� son cantidades que var�an de un trabajador a otro.
*/

#include <iostream>

using namespace std;

class Nomina{
	private:
		double horas, sueldo_hora;

	public:
		
		// Constructor
		
		Nomina (double horas_trabajadas, double precio_hora){
			
			SetHorasTrabajadas(horas_trabajadas);
			SetSueldo(precio_hora);
		}
		
		// M�todos para el constructor
		
		void SetHorasTrabajadas (double horas_trabajadas){
			horas = horas_trabajadas;
		}
		
		void SetSueldo (double precio_hora){
			sueldo_hora = precio_hora;
		}
		
		// M�todos para cambiar las horas trabajadas y el precio de cada hora de cada trabajador
		
		void SetNuevasHorasTrabajadas(double numero_horas){
			horas = numero_horas;
		}
		
		void SetNuevoPrecioHora(double nuevo_precio_hora){
			sueldo_hora = nuevo_precio_hora;
		}
		
		// M�todo para calcular el salario del trabajador
		
		double SalarioTrabajador(int MINIMO_HORAS_EXTRA, double INCREMENTO){
			
			double salario;
			
			if (horas > MINIMO_HORAS_EXTRA){
      		salario = (horas - MINIMO_HORAS_EXTRA) *  sueldo_hora;
      		salario = salario + salario * INCREMENTO;
      		salario = salario + MINIMO_HORAS_EXTRA * sueldo_hora;               
   		}
   		
   		else
      		salario = horas * sueldo_hora;
   		
   		return salario;
   	}
};

int main(){
	
	int horas;
	double precio_hora;
	int MINIMO_HORAS_EXTRA = 40;
	double INCREMENTO = 0.5;
	
	cout << "Introduzca el n�mero total de horas trabajadas: ";
	cin >> horas;
	cout << "Introduzca el precio por cada hora trabajada: ";
	cin >> precio_hora;
	
	Nomina un_trabajador(horas, precio_hora);
	
	cout << "\nEl trabajador va a cobrar " << un_trabajador.SalarioTrabajador(MINIMO_HORAS_EXTRA, INCREMENTO) << " euros.";
	cout << "\n\n";
	
	system("pause");
}
	
