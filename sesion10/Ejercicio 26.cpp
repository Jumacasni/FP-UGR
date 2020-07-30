/*
Se quiere construir una clase para representar la tracción de una bicicleta, es decir, el conjunto de estrella (engranaje delantero), cadena y 
piñón (engranaje trasero). Supondremos que la estrella tiene tres posiciones (numeradas de 1 a 3, siendo 1 la estrella más pequeña) y el piñón 
siete (numeradas de 1 a 7, siendo 1 el piñón más grande). La posición inicial de marcha es estrella = 1 y piñón = 1.
La clase debe proporcionar métodos para cambiar la estrella y el piñón, sabiendo que la estrella avanza o retrocede de 1 en 1 y los piñones 
cambian a saltos de uno o de dos. Si ha llegado al límite superior (inferior) y se llama al método para subir (bajar) la estrella, la posición 
de ésta no variará. Lo mismo se aplica al piñón. Cread un programa principal que lea desde un fichero externo los movimientos realizados e 
imprima la situación final de la estrella y piñón. Los datos se leerán en el siguiente formato: tipo de plato (piñón o estrella) seguido del 
tipo de movimiento. Para codificar esta información se usarán las siguientes letras: E indica una estrella, P un piñón, S para subir una posición,
B para bajar una posición, T para subir dos posiciones y C para bajar dos posiciones. T y C sólo se aplicarán sobre los piñones.
E S P S P S P S P C E S E B #
En este ejemplo los movimientos serían: la estrella sube, el piñón sube en tres ocasiones sucesivas, el piñón baja dos posiciones de golpe, 
la estrella sube y vuelve a bajar. Supondremos siempre que la posición inicial de la estrella es 1 y la del piñón 1. Así pues, la posición final 
será Estrella=1 y Piñón=2. Mejorad la clase para que no permita cambiar la marcha (con la estrella o el piñón) cuando haya riesgo de que se 
rompa la cadena. Este riesgo se produce cuando la marcha a la que queremos cambiar es de la siguiente forma:
- Estrella igual a 1 y piñón mayor o igual que 5
- Estrella igual a 2 y piñón o bien igual a 1 o bien igual a 7
- Estrella igual a 3 y piñón menor o igual que 3
*/

#include <iostream>

using namespace std;

class Bicicleta{
	private:
		int estrella = 1, pinon = 1;
	
	// Métodos para comprobar si las posiciones que añadimos son correctas
	
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
		
		// Métodos para sumar o restar las diferentes posiciones
		
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
		
		// Métodos para obtener las posiciones finales
		
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
	
	cout << "Posición: ";
	cin >> posicion;
	
	// Realiza una operación mientras no se pulse '#'
	
	while(posicion != '#'){
	
		cout << "Operación: ";
		cin >> operacion;
		
		if (operacion == 'S')
		
			traccion.SubirUno(posicion);
		
		else if (operacion == 'B')
			
				traccion.BajarUno(posicion);
	
			else if (operacion == 'C')
					
					traccion.BajarDos();
						
					else if (operacion == 'T')
								
							traccion.SubirDos();

		cout << "Posición: ";
		cin >> posicion;
	};
	
	cout << "\nEstrella: " << traccion.PosicionEstrella();
	cout << "\nPiñón: " << traccion.PosicionPinon();
}
