/*
Escriba una función en C++ LeeOpcion2Alternativas que imprima en pantalla un mensaje, lea una opción como un carácter y 
sólo permita aceptar los caracteres 'S' o 'N' (mayúscula o minúscula). ¿Qué debería devolver la función? ¿El carácter
leído o un bool?. Aplique esta función en la solución del ejercicio 13 (Renta bruta y neta) de la relación de problemas II, 
para leer si una persona es pensionista o si es autónomo.
*/ 

#include <iostream>
#include <cctype>

using namespace std;

// Elegir una opción cuando solo hay 2 alternativas //

bool LeeOpcion2Alternativas (string mensaje){
	
	/* Introducimos una opción.
		Si la opción no es "S" o "N", la función sigue pidiendo una opción.
		Si la opción es "S" devuelve el valor true y si es "N" devuelve el valor false.
	*/
	
	char opcion;
	bool alternativa;
	
	cout << mensaje;
	cin >> opcion;
	opcion = toupper(opcion);
	
	while(opcion != 'N' && opcion != 'S'){
		cout << "Pulse S ó N: ";
		cin >> opcion;
		opcion = toupper(opcion);
}		

	alternativa = true;
	
	if (opcion == 'N')
		alternativa = false;
	
	return alternativa;
}

int main(){
	
	int casado;
	double RETENCION_AUTONOMO = 3;
	double RETENCION_NO_AUTONOMO_SI_PENSIONISTA = 1;
	double RETENCION_NO_AUTONOMO_NO_PENSIONISTA = 2;
	double RETENCION_RENTA_BRUTA = 2;
	double RETENCION_CASADOS_RENTA_BRUTA = 2.5;
	double RETENCION_SOLTEROS_RENTA_BRUTA = 3;
	double RENTA_MINIMA = 20000;
	double renta_bruta, retencion, renta_neta;
	bool es_autonomo, es_pensionista;
	
	es_autonomo = LeeOpcion2Alternativas("Indique si es autónomo (S/N): ");		
	es_pensionista = LeeOpcion2Alternativas("Introduzca si es pensionista (S/N): ");		
	cout << "Introduzca 0 si está casado y 1 si está soltero: ";
	cin >> casado;
	cout << "Introduzca la renta bruta: ";
	cin >> renta_bruta;
	cout << "Introduzca la retención a aplicar en porcentaje: ";
	cin >> retencion;
	
	if (es_autonomo)
	
		retencion = retencion - RETENCION_AUTONOMO;
	
	else
	
		if (!es_pensionista){
		
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
	cout << "\n\n";
	
	system("pause");
}




