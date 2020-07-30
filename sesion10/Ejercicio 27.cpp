/*
Recuperad la solución del ejercicio 30 de la Relación de Problemas II (Empresa). Reescribid el programa principal usando una clase Ventas 
para gestionar los cómputos de las ventas realizadas. Únicamente se pide que se indiquen las cabeceras de los métodos públicos de la clase y 
las llamadas a éstos en el programa principal. No hay que implementar ninguno de los métodos.
Debe suponer que la clase gestionará las ventas de exactamente tres sucursales. Los códigos de dichas sucursales son enteros cualesquiera 
(no necesariamente 1, 2, 3, como ocurría en el ejercicio 30 de la Relación de Problemas II)
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
	
		// Método para actualizar las unidades
		
		void ActualizarUnidades(int sucursal, int cantidad){}
		
		// Métodos para obtener los números de las sucursales y las unidades de cada una
		
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
	
	cout << "\n--Introduzca un registro (Pulse -1 para salir)--\n~Sucursal (1, 2 ,3)\n~Código del producto (a, b, c)\n~Unidades vendidas\n\n";
	
	cin >> sucursal;

	while(sucursal != terminador){	
		
		cin >> producto;
		cin >> unidades;
		
		ventas_empresa.ActualizarUnidades(sucursal, unidades);
		
		cout << "\n--Introduzca un registro (Pulse -1 para salir)--\n~Sucursal (1, 2 ,3)\n~Código del producto (a, b, c)\n~Unidades vendidas\n\n";
		cin >> sucursal;
	}
		
			cout << ventas_empresa.GetSucursal1() << ventas_empresa.GetUnidadesSucursal1();
			cout << ventas_empresa.GetSucursal2() << ventas_empresa.GetUnidadesSucursal2();
			cout << ventas_empresa.GetSucursal3() << ventas_empresa.GetUnidadesSucursal3();
		
		cout << "\n\n";
system("pause");
}



