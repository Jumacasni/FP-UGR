/*
En el ejercicio 12 de la relación de problemas I (página RP-I.4) se vio cómo obtener el valor de ordenada asignado por la función gaussiana, 
sabiendo el valor de abscisa x.
Cread un programa que lea un valor de esperanza y desviación y a continuación lea un número entero n que indique el número de abscisas que se van a procesar. Leed
un total de n valores reales e imprimid en pantalla el valor de la función gaussiana en dichos valores. El cómputo de la gaussiana debe hacerse en una función.
Ahora estamos interesados en obtener el área que cubre la función en el intervalo [-inf; x]. Dicho valor se conoce como la distribución acumulada 
(cumulative distribution function) en el punto x, abreviado CDF(x).
Cread otra función para calcular el área hasta un punto cualquiera x, es decir, CDF(x), usando la anterior aproximación. Modificad el programa principal para que
llame a esta función e imprima los valores de CDF correspondientes a los valores de abscisa leídos.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Calcular el valor de la función Gaussiana //

double Gaussiana (double esperanza, double desviacion, double valor_abscisa){
	
	const double PI = 3.1415927; 
	double valor_tipificado, exponente, resultado;
		
	valor_tipificado = (valor_abscisa - esperanza) / desviacion;
	exponente = -0.5 * valor_tipificado * valor_tipificado;

	resultado = exp(exponente) / ( desviacion * sqrt(2*PI) );
	
	return resultado;
}

// Calcular el valor de la distribución acumulada (CDF) //

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
	cout << "Introduzca el número de abscisas que se van a procesar: ";
	cin >> numero_abscisa;
	cout << "Introduzca el valor de las abscisas (separado por espacios): ";
	
	/*
	Calcular el valor de la función Gaussiana y de la distribución acumulada de todos los puntos que hayamos introducido
	*/
	
	for (contador_numero_abscisa = 0; contador_numero_abscisa < numero_abscisa; contador_numero_abscisa++){
	
		cin >> valor_abscisa;
		
		y = Gaussiana(esperanza, desviacion, valor_abscisa);
		cout << "\nEl valor de la función gaussiana en " << valor_abscisa << " es " << y;
		
		CDF = Integral(y, valor_abscisa);
		cout << "\nLa distribución acumulada en x = " << valor_abscisa << " es " << CDF << "\n";
		
}
	cout << "\n\n";
	
	system("pause");
}
