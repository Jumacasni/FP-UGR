/*
En el ejercicio 7 de esta relaci�n de problemas se definieron varias funciones para operar sobre una progresi�n geom�trica. Definid ahora 
una clase para representar una progresi�n geom�trica.
a) Dise�ad la clase pensando cu�les ser�an los datos miembro esenciales que definen una progresi�n geom�trica, as� como el constructor 
de la clase.
b) Definir un m�todo Termino que devuelva el t�rmino k-�simo.
c) Definid los m�todos SumaHastaInfinito, SumaHasta, MultiplicaHasta.
d) Cread un programa principal que lea los datos miembro de una progresi�n, cree el objeto correspondiente y a continuaci�n lea un entero 
tope e imprima los tope primeros t�rminos de la progresi�n, as� como la suma hasta tope de dichos t�rminos.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Progresion{
	private:
		double a_1, constante_r;
		
	public:
		
		// Constructor
		
		Progresion (int valor_inicial, int razon){
			
			SetValorInicial(valor_inicial);
			SetRazon(razon);
		}
		
		// M�todos para el constructor
		
		void SetValorInicial (int valor_inicial){
			a_1 = valor_inicial;
		}
		
		void SetRazon (int razon){
			constante_r = razon;
		}
		
		// M�todo para obtener el t�rmino independiente
		
		double Termino(int tope){
			return a_1 * pow(constante_r, tope);
		}
		
		// M�todos para las diferentes operaciones
		
		double SumaHasta(int tope){
			
			int suma = 0;
			int i;
			
			for(i = 0; i < tope ; i++){
				suma = suma + a_1*pow(constante_r, i);
			}
			
			return suma;
		}
		
		double SumaHastaInfinito(){
	
			return a_1 / (1 - constante_r);
		}
		
		double MultiplicaHasta(int tope){
			
			return sqrt(pow(a_1 * Termino(tope), tope));
		}
};

int main(){

	double constante_r, primer_valor, tope;
	
	cout << "Introduzca el primer elemento (a1): ";
	cin >> primer_valor;
	cout << "Introduzca el valor de la constante r: ";
	cin >> constante_r;
	
	Progresion una_progresion(primer_valor, constante_r);
	
	cout << "Introduzca el tope (k): ";
	cin >> tope;
	
	cout << "\nLa suma de todos los elementos es " << una_progresion.SumaHasta(tope);
	
	cout << "\nEl producto de todos los elementos es " << una_progresion.MultiplicaHasta(tope);
	
	/* 
	Tres posibilidades en la funci�n 3: valor absoluto de la raz�n menor que 1, igual que 1 o mayor que 1.
	*/
	
	if (abs(constante_r) < 1)

		cout << "\nLa suma hasta infinito es " <<	una_progresion.SumaHastaInfinito();
	
	else if (constante_r == 1)
		
		cout <<"\nLa suma hasta infinito no tiene soluci�n real";

		else
		
			cout << "\nLa suma hasta infinito es infinito";
		
	cout << "\n\n";
	
	system("pause");
}
