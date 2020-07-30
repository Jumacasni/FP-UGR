/*
Recuperad la soluci�n del ejercicio 30 de la Relaci�n de Problemas II (Empresa). Reescribid el programa principal usando una clase Ventas 
para gestionar los c�mputos de las ventas realizadas. �nicamente se pide que se indiquen las cabeceras de los m�todos p�blicos de la clase y 
las llamadas a �stos en el programa principal. No hay que implementar ninguno de los m�todos.
Debe suponer que la clase gestionar� las ventas de exactamente tres sucursales. Los c�digos de dichas sucursales son enteros cualesquiera 
(no necesariamente 1, 2, 3, como ocurr�a en el ejercicio 30 de la Relaci�n de Problemas II)
*/

#include <iostream>

using namespace std;

class Ventas{
	private:
		int sucursal1, sucursal2, sucursal3;
		int unidades1 = 0, unidades2 = 0, unidades3 = 0;
		
	public:
		
		// Constructor
		
		Ventas (int sucursal_1, int sucursal_2, int sucursal_3){}
		
		void SetSucursal1(int sucursal_1){}
		
		void SetSucursal2(int sucursal_2){}
		
		void SetSucursal3(int sucursal_3){}
	
		// M�todo para actualizar las unidades
		
		void ActualizarUnidades(int sucursal, int cantidad){}
		
		// M�todos para obtener los n�meros de las sucursales y las unidades de cada una
		
		double GetSucursal1(){}
		
		double GetSucursal2(){}
		
		double GetSucursal3(){}
		
		double GetUnidadesSucursal1(){}
		
		double GetUnidadesSucursal2(){}
		
		double GetUnidadesSucursal3(){}	
};

int main(){
	
	cin >> sucursal1;
	cin >> sucursal2;
	cin >> sucursal3;
	
	Ventas ventas_empresa(sucursal1, sucursal2, sucursal3);
	
	cout << "\n--Introduzca un registro (Pulse -1 para salir)--\n~Sucursal (1, 2 ,3)\n~C�digo del producto (a, b, c)\n~Unidades vendidas\n\n";
	
	cin >> sucursal;

	while(sucursal != terminador){	
		
		cin >> producto;
		cin >> unidades;
		
		ventas_empresa.ActualizarUnidades(sucursal, unidades);
		
		cout << "\n--Introduzca un registro (Pulse -1 para salir)--\n~Sucursal (1, 2 ,3)\n~C�digo del producto (a, b, c)\n~Unidades vendidas\n\n";
		cin >> sucursal;
	}
		
			cout << ventas_empresa.GetSucursal1() << ventas_empresa.GetUnidadesSucursal1();
			cout << ventas_empresa.GetSucursal2() << ventas_empresa.GetUnidadesSucursal2();
			cout << ventas_empresa.GetSucursal3() << ventas_empresa.GetUnidadesSucursal3();
		
		cout << "\n\n";
system("pause");
}



