/*
En el ejercicio 12 de la relaci�n de problemas I (p�gina RP-I.4) se vio c�mo obtener el valor de ordenada asignado por la funci�n gaussiana, 
sabiendo el valor de abscisa x.
Cread un programa que lea un valor de esperanza y desviaci�n y a continuaci�n lea un n�mero entero n que indique el n�mero de abscisas que se van a procesar. Leed
un total de n valores reales e imprimid en pantalla el valor de la funci�n gaussiana en dichos valores. El c�mputo de la gaussiana debe hacerse en una funci�n.
Ahora estamos interesados en obtener el �rea que cubre la funci�n en el intervalo [-inf; x]. Dicho valor se conoce como la distribuci�n acumulada 
(cumulative distribution function) en el punto x, abreviado CDF(x).
Cread otra funci�n para calcular el �rea hasta un punto cualquiera x, es decir, CDF(x), usando la anterior aproximaci�n. Modificad el programa principal para que
llame a esta funci�n e imprima los valores de CDF correspondientes a los valores de abscisa le�dos.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Calcular el valor de la funci�n Gaussiana //

double Gaussiana (double esperanza, double desviacion, double valor_abscisa){
	
	const double PI = 3.1415927; 
	double valor_tipificado, exponente, resultado;
		
	valor_tipificado = (valor_abscisa - esperanza) / desviacion;
	exponente = -0.5 * valor_tipificado * valor_tipificado;

	resultado = exp(exponente) / ( desviacion * sqrt(2*PI) );
	
	return resultado;
}

// Calcular el valor de la distribuci�n acumulada (CDF) //

double Integral (double valor_gaussiana, double valor_abscisa){
	
	double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782, b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429, t, resultado;
	
	t = 1 / (1 + b0*valor_abscisa);

	resultado = 1 - valor_gaussiana*(b1 * t + b2 * pow(t, 2) + b3 * pow(t, 3) + b4 * pow(t, 4) + b5 * pow(t, 5));

	return resultado;
}
int main(){

	double esperanza, desviacion, valor_abscisa;   
	double y, CDF;	                       
	int contador_numero_abscisa, numero_abscisa;
   
	cout << "Introduzca la esperanza: ";
	cin >> esperanza;
	cout << "Introduzca la desviacion: ";
	cin >> desviacion;
	cout << "Introduzca el n�mero de abscisas que se van a procesar: ";
	cin >> numero_abscisa;
	cout << "Introduzca el valor de las abscisas (separado por espacios): ";
	
	/*
	Calcular el valor de la funci�n Gaussiana y de la distribuci�n acumulada de todos los puntos que hayamos introducido
	*/
	
	for (contador_numero_abscisa = 0; contador_numero_abscisa < numero_abscisa; contador_numero_abscisa++){
	
		cin >> valor_abscisa;
		
		y = Gaussiana(esperanza, desviacion, valor_abscisa);
		cout << "\nEl valor de la funci�n gaussiana en " << valor_abscisa << " es " << y;
		
		CDF = Integral(y, valor_abscisa);
		cout << "\nLa distribuci�n acumulada en x = " << valor_abscisa << " es " << CDF << "\n";
		
}
	cout << "\n\n";
	
	system("pause");
}
