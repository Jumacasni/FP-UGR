/*
	En clase de teoría se ha visto e implementado el siguiente ejemplo:
	En un programa de ventas, si la cantidad vendida es mayor de 100 unidades, se le
aplica un descuento del 3 %. Por otra parte, si el precio final de la venta es mayor de
700 euros, se aplica un descuento del 2 %. Ambos descuentos son acumulables.
	Vamos a cambiar el criterio de los descuentos. Supondremos que sólo se aplicará el
descuento del 2% (por una venta mayor de 700 euros) cuando se hayan vendido más
de 100 unidades, es decir, para ventas de menos de 100 unidades no se aplica el
descuento del 2% aunque el importe sea mayor de 700 euros.
	Cambiar el programa visto en clase para incorporar este nuevo criterio.
*/

#include <iostream>

using namespace std;

int main(){
	
	int unidades;
	double precio_venta;
	double PORCENTAJE_DESCUENTO_UNIDADES = 0.03;
	double PORCENTAJE_DESCUENTO_PRECIO = 0.02;
	int UNIDADES_MINIMAS_DESCUENTO = 100;
	int DINERO_MINIMO_DESCUENTO = 700;
	
	cout << "Introduzca las unidades vendidas: ";
	cin >> unidades;
	cout << "Introduzca el precio final de la venta: ";
	cin >> precio_venta;
		
	if (unidades > UNIDADES_MINIMAS_DESCUENTO && precio_venta > DINERO_MINIMO_DESCUENTO){
	
		precio_venta = precio_venta - precio_venta*(PORCENTAJE_DESCUENTO_UNIDADES + PORCENTAJE_DESCUENTO_PRECIO);
		
			cout << "\nEl precio final con el descuento es de " << precio_venta << " euros.";
}
	else
	
		if (unidades > UNIDADES_MINIMAS_DESCUENTO){
	
		precio_venta = precio_venta - PORCENTAJE_DESCUENTO_UNIDADES*precio_venta;
		
			cout << "\nEl precio final con el descuento es de " << precio_venta << " euros.";
}
		else
		
		cout << "\nNo se aplica ningún descuento";
}
		
