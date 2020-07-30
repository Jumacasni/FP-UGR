/*
Implementar los métodos de la clase Ventas del ejercicio anterior.
*/

#include <iostream>

using namespace std;

class Ventas{
	private:
		int sucursal1, sucursal2, sucursal3;
		int unidades1 = 0, unidades2 = 0, unidades3 = 0;
		
	public:
		
		// Constructor
		
		Ventas (int sucursal_1, int sucursal_2, int sucursal_3){
			SetSucursal1(sucursal_1);
			SetSucursal2(sucursal_2);
			SetSucursal3(sucursal_3);
		}
		
		// Métodos para el constructor
		
		void SetSucursal1(int sucursal_1){
			sucursal1 = sucursal_1;
		}
		
		void SetSucursal2(int sucursal_2){
			sucursal2 = sucursal_2;
		}
		
		void SetSucursal3(int sucursal_3){
			sucursal3 = sucursal_3;
		}
		
		// Método para actualizar las unidades de cada sucursal
		
		void ActualizarUnidades(int sucursal, int cantidad){
			if (sucursal == sucursal1)
				unidades1 = unidades1 + cantidad;
			else
				if (sucursal == sucursal2)
					unidades2 = unidades2 + cantidad;
				else
					if (sucursal == sucursal3)
						unidades3 = unidades3 + cantidad;
		}
		
		// Métodos para obtener los números de las sucursales y sus unidades vendidas
		
		double GetSucursal1(){
			return sucursal1;
		}
		double GetSucursal2(){
			return sucursal1;
		}
		double GetSucursal3(){
			return sucursal3;
		}
		
		double GetUnidadesSucursal1(){
			return unidades1;
		}
		double GetUnidadesSucursal2(){
			return unidades2;
		}
		double GetUnidadesSucursal3(){
			return unidades3;
		}
};

int main(){
	
	int sucursal, unidades, sucursal1, sucursal2, sucursal3;
	int terminador = -1;
	char producto;
	bool Sucursal1Maxima, Sucursal2Maxima;
	
	cout << "Introduzca las 3 sucursales (separadas por un espacio): ";
	cin >> sucursal1;
	cin >> sucursal2;
	cin >> sucursal3;
	
	Ventas ventas_empresa(sucursal1, sucursal2, sucursal3);
	
	// Introducimos una sucursal, el código del producto y las unidades vendidas.
	// Se actualizan las unidades vendidas mientras la sucursal no sea -1.
	
	cout << "\n--Introduzca un registro (Pulse -1 para salir)--\n~Sucursal (1, 2 ,3)\n~Código del producto (a, b, c)\n~Unidades vendidas\n\n";
	cin >> sucursal;

	while(sucursal != terminador){	
		
		cin >> producto;
		cin >> unidades;
		
		ventas_empresa.ActualizarUnidades(sucursal, unidades);
		
		cout << "\n--Introduzca un registro (Pulse -1 para salir)--\n~Sucursal (1, 2 ,3)\n~Código del producto (a, b, c)\n~Unidades vendidas\n\n";
		cin >> sucursal;
	}
	
	// Sucursal que más unidades ha vendido
	
		Sucursal1Maxima = ventas_empresa.GetUnidadesSucursal1() >= ventas_empresa.GetUnidadesSucursal2() && ventas_empresa.GetUnidadesSucursal1() >= ventas_empresa.GetUnidadesSucursal3();
		Sucursal2Maxima = ventas_empresa.GetUnidadesSucursal2() >= ventas_empresa.GetUnidadesSucursal1() && ventas_empresa.GetUnidadesSucursal2() >= ventas_empresa.GetUnidadesSucursal3();
				
		if (Sucursal1Maxima)
		
			cout << "\nLa sucursal " << ventas_empresa.GetSucursal1() << " ha sido la que más ha vendido con " << ventas_empresa.GetUnidadesSucursal1() << " unidades.";
		
		else if (Sucursal2Maxima)
					
				cout << "\nLa sucursal " << ventas_empresa.GetSucursal2() << " ha sido la que más ha vendido con " << ventas_empresa.GetUnidadesSucursal2() << " unidades.";
				
				else
					
					cout << "\nLa sucursal " << ventas_empresa.GetSucursal3() << " ha sido la que más ha vendido con " << ventas_empresa.GetUnidadesSucursal3() << " unidades.";
		
		cout << "\n\n";
system("pause");
}
