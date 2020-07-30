/*
Se quiere construir una clase para representar la tracci�n de una bicicleta, es decir, el conjunto de estrella (engranaje delantero), cadena y 
pi��n (engranaje trasero). Supondremos que la estrella tiene tres posiciones (numeradas de 1 a 3, siendo 1 la estrella m�s peque�a) y el pi��n 
siete (numeradas de 1 a 7, siendo 1 el pi��n m�s grande). La posici�n inicial de marcha es estrella = 1 y pi��n = 1.
La clase debe proporcionar m�todos para cambiar la estrella y el pi��n, sabiendo que la estrella avanza o retrocede de 1 en 1 y los pi�ones 
cambian a saltos de uno o de dos. Si ha llegado al l�mite superior (inferior) y se llama al m�todo para subir (bajar) la estrella, la posici�n 
de �sta no variar�. Lo mismo se aplica al pi��n. Cread un programa principal que lea desde un fichero externo los movimientos realizados e 
imprima la situaci�n final de la estrella y pi��n. Los datos se leer�n en el siguiente formato: tipo de plato (pi��n o estrella) seguido del 
tipo de movimiento. Para codificar esta informaci�n se usar�n las siguientes letras: E indica una estrella, P un pi��n, S para subir una posici�n,
B para bajar una posici�n, T para subir dos posiciones y C para bajar dos posiciones. T y C s�lo se aplicar�n sobre los pi�ones.
E S P S P S P S P C E S E B #
En este ejemplo los movimientos ser�an: la estrella sube, el pi��n sube en tres ocasiones sucesivas, el pi��n baja dos posiciones de golpe, 
la estrella sube y vuelve a bajar. Supondremos siempre que la posici�n inicial de la estrella es 1 y la del pi��n 1. As� pues, la posici�n final 
ser� Estrella=1 y Pi��n=2. Mejorad la clase para que no permita cambiar la marcha (con la estrella o el pi��n) cuando haya riesgo de que se 
rompa la cadena. Este riesgo se produce cuando la marcha a la que queremos cambiar es de la siguiente forma:
- Estrella igual a 1 y pi��n mayor o igual que 5
- Estrella igual a 2 y pi��n o bien igual a 1 o bien igual a 7
- Estrella igual a 3 y pi��n menor o igual que 3
*/

#include <iostream>

using namespace std;

class Bicicleta{
	private:
		int estrella = 1, pinon = 1;
	
	// M�todos para comprobar si las posiciones que a�adimos son correctas
	
	bool PosicionCorrectaEstrella(int posicion_estrella_propuesta){
		return 1 <= posicion_estrella_propuesta && posicion_estrella_propuesta <= 3;
	}
	
	bool PosicionCorrectaPinon(int posicion_pinon_propuesta){
		return 1 <= posicion_pinon_propuesta && posicion_pinon_propuesta <= 7;
	}
	
	bool Riesgo1(int posicion_estrella_propuesta, int posicion_pinon_propuesta){
		return !(posicion_estrella_propuesta == 1 && posicion_pinon_propuesta >= 5);
	}
	
	bool Riesgo2(int posicion_estrella_propuesta, int posicion_pinon_propuesta){
		return !(posicion_estrella_propuesta == 2 && (posicion_pinon_propuesta == 1 || posicion_pinon_propuesta == 7));
	}
	
	bool Riesgo3(int posicion_estrella_propuesta, int posicion_pinon_propuesta){
		return !(posicion_estrella_propuesta == 3 && posicion_pinon_propuesta <= 3);
	} 
		
	public:
		
		// M�todos para sumar o restar las diferentes posiciones
		
		void SubirUno(char posicion){
			double posicion_estrella, posicion_pinon;
			
			if (posicion == 'E'){
				posicion_estrella = estrella + 1;
				if (PosicionCorrectaEstrella(posicion_estrella)){
					if (Riesgo1(posicion_estrella, pinon) && Riesgo2(posicion_estrella, pinon) && Riesgo3(posicion_estrella, pinon))
						estrella = posicion_estrella;
				}
			}
			
			else{
				if (posicion == 'P')
					posicion_pinon = pinon + 1;
					if (PosicionCorrectaPinon(posicion_pinon)){
						if (Riesgo1(estrella, posicion_pinon) && Riesgo2(estrella, posicion_pinon) && Riesgo3(estrella, posicion_pinon))
							pinon = posicion_pinon;
					}
			}
		}
		
		void BajarUno(char posicion){
			double posicion_estrella, posicion_pinon;
			
			if (posicion == 'E'){
				posicion_estrella = estrella - 1;
				if (PosicionCorrectaEstrella(posicion_estrella)){
					if (Riesgo1(posicion_estrella, pinon) && Riesgo2(posicion_estrella, pinon) && Riesgo3(posicion_estrella, pinon))
						estrella = posicion_estrella;
				}
			}
			else{
				if (posicion == 'P')
					posicion_pinon = pinon - 1;
					if (PosicionCorrectaPinon(posicion_pinon)){
						if (Riesgo1(estrella, posicion_pinon) && Riesgo2(estrella, posicion_pinon) && Riesgo3(estrella, posicion_pinon))
							pinon = posicion_pinon;
					}				
			}
		}
		
		void SubirDos(){
			double posicion_pinon;
			
			posicion_pinon = pinon + 2;
			if (PosicionCorrectaPinon(posicion_pinon)){
				if (Riesgo1(estrella, posicion_pinon) && Riesgo2(estrella, posicion_pinon) && Riesgo3(estrella, posicion_pinon))
					pinon = posicion_pinon;
			}
		}
		
		void BajarDos(){
			double posicion_pinon;
			
			posicion_pinon = pinon - 2;
			if (PosicionCorrectaPinon(posicion_pinon)){
				if (Riesgo1(estrella, posicion_pinon) && Riesgo2(estrella, posicion_pinon) && Riesgo3(estrella, posicion_pinon))
					pinon = posicion_pinon;
			}
		}
		
		// M�todos para obtener las posiciones finales
		
		int PosicionEstrella(){
			return estrella;
		}
		
		int PosicionPinon(){
			return pinon;
		}
		
};

int main (){
	
	Bicicleta traccion;
	char posicion, operacion;
	
	cout << "Posici�n: ";
	cin >> posicion;
	
	// Realiza una operaci�n mientras no se pulse '#'
	
	while(posicion != '#'){
	
		cout << "Operaci�n: ";
		cin >> operacion;
		
		if (operacion == 'S')
		
			traccion.SubirUno(posicion);
		
		else if (operacion == 'B')
			
				traccion.BajarUno(posicion);
	
			else if (operacion == 'C')
					
					traccion.BajarDos();
						
					else if (operacion == 'T')
								
							traccion.SubirDos();

		cout << "Posici�n: ";
		cin >> posicion;
	};
	
	cout << "\nEstrella: " << traccion.PosicionEstrella();
	cout << "\nPi��n: " << traccion.PosicionPinon();
}
