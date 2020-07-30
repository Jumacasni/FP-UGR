/*
	Cread un programa que lea los datos fiscales da una persona, reajuste su renta bruta
según el criterio que se indica posteriormente e imprima su renta neta final.
*/

#include <iostream>

using namespace std;

int main(){
	
	int autonomo, pensionista, casado;
	double RETENCION_AUTONOMO = 3;
	double RETENCION_NO_AUTONOMO_SI_PENSIONISTA = 1;
	double RETENCION_NO_AUTONOMO_NO_PENSIONISTA = 2;
	double RETENCION_RENTA_BRUTA = 2;
	double RETENCION_CASADOS_RENTA_BRUTA = 2.5;
	double RETENCION_SOLTEROS_RENTA_BRUTA = 3;
	double RENTA_MINIMA = 20000;
	double renta_bruta, retencion, renta_neta;

	
	cout << "Introduzca 0 si es autónomo y 1 si no lo es: ";
	cin >> autonomo;
	cout << "Introduzca 0 si es pensionista y 1 si no lo es: ";
	cin >> pensionista;
	cout << "Introduzca 0 si está casado y 1 si está soltero: ";
	cin >> casado;
	cout << "Introduzca la renta bruta: ";
	cin >> renta_bruta;
	cout << "Introduzca la retención a aplicar en porcentaje: ";
	cin >> retencion;

	if (autonomo == 0)
	
		retencion = retencion - RETENCION_AUTONOMO;
	
	else
	
		if (pensionista == 1){
		
			retencion = retencion + RETENCION_NO_AUTONOMO_NO_PENSIONISTA;
			
			if (renta_bruta < RENTA_MINIMA)
			
				retencion = retencion + RETENCION_RENTA_BRUTA;
			
			else
			
				if (casado == 0)
				
					retencion = retencion + RETENCION_CASADOS_RENTA_BRUTA;
					
				else
				
					retencion = retencion + RETENCION_SOLTEROS_RENTA_BRUTA;
}
		else
		
			retencion = retencion + RETENCION_NO_AUTONOMO_SI_PENSIONISTA;

renta_neta = renta_bruta - renta_bruta * retencion / 100;
		
	cout <<"\nLa renta final es de " << renta_neta << " euros.";
}

	
		
		
		
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
