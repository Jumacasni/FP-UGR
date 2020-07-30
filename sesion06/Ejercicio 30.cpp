/*
Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con
tres números, el identificador de la sucursal (1, 2 o 3), el código del producto codificado
como un carácter (a, b ó c) y el número de unidades vendidas. Diseñar
un programa que lea desde el teclado una serie de registros compuestos por
sucursal, producto, unidades y diga cuál es la sucursal que más productos
ha vendido. La serie de datos termina cuando la sucursal introducida vale -1.
*/

#include <iostream>

using namespace std;

int main(){
	
	int sucursal, unidades;
	int terminador = -1;
	int suma_unidades_sucursal_1 = 0, suma_unidades_sucursal_2 = 0, suma_unidades_sucursal_3 = 0, maximo1 = 0, maximo2 = 0, maximo3 = 0;
	bool salir_del_registro, sucursal_1_mayor, sucursal_2_mayor, sucursal_3_mayor;
	char producto;

	cout << "--Introduzca un registro (Pulse -1 para salir)--\n~Sucursal (1, 2 ,3)\n~Código del producto (a, b, c)\n~Unidades vendidas\n\n";
	cin >> sucursal;
	
	salir_del_registro = (sucursal == terminador);
	
	if (salir_del_registro)
		cout << "\nNo ha introducido ningún registro";
	
	else{
	while(sucursal != terminador){	
	
		cin >> producto;
		cin >> unidades;
		
		if (sucursal == 1){
			
			suma_unidades_sucursal_1 = suma_unidades_sucursal_1 + unidades;
			maximo1 = suma_unidades_sucursal_1;
}
		else
			if (sucursal == 2){

			suma_unidades_sucursal_2 = suma_unidades_sucursal_2 + unidades;
			maximo2 = suma_unidades_sucursal_2;
}
			else
				if (sucursal == 3){
					
			suma_unidades_sucursal_3 = suma_unidades_sucursal_3 + unidades;
			maximo3 = suma_unidades_sucursal_3;	
}


		cin >> sucursal;
}

	sucursal_1_mayor = (maximo1 > maximo2 && maximo1 > maximo3);
	sucursal_2_mayor = (maximo2 > maximo1 && maximo2 > maximo3);
	sucursal_3_mayor = (maximo3 > maximo1 && maximo3 > maximo2);
	
	if (sucursal_1_mayor)
		cout << "\nLa sucursal 1 ha sido la que más ha vendido con " << maximo1 << " unidades.\n";
	else
		if (sucursal_2_mayor)
			cout << "\nLa sucursal 2 ha sido la que más ha vendido con " << maximo2 << " unidades.\n";
		else
			if (sucursal_3_mayor)
			cout << "\nLa sucursal 3 ha sido la que más ha vendido con " << maximo3 << " unidades.\n";
}
system("pause");
}

