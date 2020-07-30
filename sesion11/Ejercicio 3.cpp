/*
Recupere la solución del ejercicio 28 (ventas de empresa) de la relación de problemas III. Resuelva el problema pedido (calcular la sucursal 
con mayor número de ventas) pero ahora considere que no conoce a priori el número de sucursales que hay, aunque sabe que los códigos de éstas 
siempre son números entre 1 y 100 y que en total no hay más de 100 sucursales. Por lo tanto, tendrá que añadir como dato miembro de
la clase, un vector con un tamaño máximo de 100. Cree un programa principal de prueba.
*/

#include <iostream>
using namespace std;

class VentasSucursales{
private:

   int sucursal[100];
   int num_ventas[100] = {0};
   int total_sucursales;

public:
   
   VentasSucursales()
   	:total_sucursales(0)
   {
   }
   
   void Actualiza(int num_sucursal, int unidades_vendidas){
      if (unidades_vendidas > 0){
			for (int i = 0 ; i < total_sucursales ; i++){
				if (sucursal[i] == num_sucursal)
					num_ventas[i] = num_ventas[i] + unidades_vendidas; 
			}
		}
   }
   
   void Aniade(int num_sucursal){
		
		bool sucursal_no_repetida = true;
		
		if (total_sucursales == 0){
			sucursal[total_sucursales] = num_sucursal;
			total_sucursales++;
		}
	
		else{
			
		// Comprueba si la sucursal está repetida o no y si no está repetida suma una sucursal, si no, no hace nada
		
			for ( int i = 0 ; i < total_sucursales ; i++){
				if (sucursal_no_repetida){
					if (sucursal[i] == num_sucursal)
						sucursal_no_repetida = false;
				}
			}
			
			if (sucursal_no_repetida){
				sucursal[total_sucursales] = num_sucursal;
				total_sucursales++;
			}
   	}
   }
	
   int SucursalGanadora(){
   	int numero_max_ventas = num_ventas[0];
   	int identif_sucursal_max_ventas = sucursal[0];
   	
   	// Comprueba sucursal a sucursal las ventas que tiene y cuál es la que más ha vendido
   	
   	for (int i = 1 ; i < total_sucursales ; i++){
   		if (num_ventas[i] > numero_max_ventas){
   			numero_max_ventas = num_ventas[i];
   			identif_sucursal_max_ventas = sucursal[i];
   		}
   	}
   	
   	return identif_sucursal_max_ventas;
   }
   
   int UnidadesVendidas(int num_sucursal){
   	
   	int unidades;
   	
   	// De acuerdo a la sucursal ganadora, obtenemos el número de unidades vendidas
   	
   	for (int i = 0 ; i < total_sucursales ; i++){
   		if (sucursal[i] == num_sucursal)
   			unidades = num_ventas[i];
   	}
   	
   	return unidades;
   }
};
    
int main(){
	
	VentasSucursales ventas;
   const int TERMINADOR = -1;  
   int identif_sucursal, ID_sucursal_ganadora, unidades_vendidas;
   char cod_producto; 
   int  ventas_sucursal_ganadora;

   cout << "\n--Introduzca un registro (Pulse -1 para salir)--\n~Sucursal (1, 2 ,3)\n~Código del producto (a, b, c)\n~Unidades vendidas\n\n";
      
   cin >> identif_sucursal; 
   
   while (identif_sucursal != TERMINADOR){   
	
		ventas.Aniade(identif_sucursal);
		          
      cin >> cod_producto;
      cin >> unidades_vendidas;
         
      ventas.Actualiza(identif_sucursal, unidades_vendidas); 

      cin >> identif_sucursal;      
   }          
   
   ID_sucursal_ganadora = ventas.SucursalGanadora();
   ventas_sucursal_ganadora = ventas.UnidadesVendidas(ID_sucursal_ganadora);
   
	cout << "\nSucursal ganadora: " << ID_sucursal_ganadora;
	cout << "\nUnidades vendidas: " << ventas_sucursal_ganadora;
   
   cout << "\n\n";
   system("pause");
}
