/*
Dos números amigos son dos números naturales a y b, tales que la suma de los divisores propios de a más uno es igual a b, y viceversa. Un
ejemplo de números amigos es el par de naturales (220; 284), ya que:
- Los divisores propios de 220 son 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110, que suman 283, y 283 + 1 = 284.
- Los divisores propios de 284 son 2, 4, 71 y 142, que suman 219, y 219 + 1 = 220.
Realice un programa que implemente estas dos tareas:
a) En primer lugar debe leer dos números naturales e indicar si son o no amigos.
b) A continuación leerá otro número natural, n, e informará si existe algún número
amigo de n en el intervalo centrado en n y de radio 3.
Utilice las funciones que estime oportuno.
*/

#include <iostream> 
using namespace std;  

// Calcular los divisores propios de un número //

int DivisoresPropios(int numero){
	
	/*
	Dividir el número entre todos los números menores que su mitad empezando por el divisor 2.
	Comprobar si al dividirlo su resto es 0.
	Sumar todos los divisores propios.
	*/
	
	int divisor, ultimo_divisor_posible, suma_divisores;
	
	divisor = 2;
   ultimo_divisor_posible = numero/2;
   suma_divisores = 0;
   
	while (divisor <= ultimo_divisor_posible){    
		if (numero % divisor == 0)
			suma_divisores = suma_divisores + divisor;

		divisor++;
	}

	return suma_divisores;
}

// Comprobar si 2 números son amigos //

bool NumerosAmigos(int numero_a, int numero_b){
	
	/*
	Calcular la suma de todos los divisores propios de los dos números.
	Comprobar si son amigos.
	*/
	
	int suma_divisores_a, suma_divisores_b, numeros_amigos;
	bool son_numeros_amigos = false;
	
	suma_divisores_a = DivisoresPropios(numero_a);
	suma_divisores_b = DivisoresPropios(numero_b);
	
	numeros_amigos = (suma_divisores_a + 1 == numero_b && suma_divisores_b + 1 == numero_a);
	
	if (numeros_amigos)
		son_numeros_amigos = true;
	
	return son_numeros_amigos;
}
int main(){    

	int numero_a, numero_b, numero_n, intervalo;
	int RADIO = 3;
	bool numeros_amigos;
	
	/*
	Apartado A: comprobar si los números introducidos son amigos.
	*/
	
	do{
		cout << "Introduzca un número natural: ";
		cin >> numero_a;
		cout << "Introduzca otro número natural: ";
		cin >> numero_b;
	}while (numero_a && numero_b <= 0);
	
	numeros_amigos = NumerosAmigos(numero_a, numero_b);
	
	if (numeros_amigos)
		cout << "\nLos números introducidos son números amigos";
	
	else
		cout << "\nLos números introducidos no son números amigos";
	
	/*
	Apartado B: introducir otro número y comprobar si tiene algún número amigo en el intervalo centrado en él y de radio 3.
	*/
	
	cout << "\n\nIntroduzca otro número natural: ";
	cin >> numero_n;
	
	for (intervalo = numero_n - RADIO; intervalo <= numero_n + RADIO; intervalo++){
		
		numeros_amigos = NumerosAmigos(intervalo, numero_n);
		
		if (numeros_amigos)
			cout << "El número " << intervalo << " es amigo de " << numero_n;
}

	cout << "\n\n";
	
	system("pause");
}
