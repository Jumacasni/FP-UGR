#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Login{
	private:
		int num_caracteres_a_coger;
	public:

		int palabras_introducidas = 1;
		
		Login (int numero_caracteres_a_coger)
			:num_caracteres_a_coger(numero_caracteres_a_coger){ 
			}
	
		string Codifica(string nombre_completo){
			
			string nombre_sugerido, palabra_extraida;
			int i, posicion_siguiente_caracter = 1;
			int j;
			const char SEPARADOR = ' ';
			
			for (i = 0 ; i < nombre_completo.size() ; i++){
				
				if(nombre_completo[i] == SEPARADOR)
					palabras_introducidas++;	
			}
			
			i = 0;
			
				while( i < palabras_introducidas){
				
					palabra_extraida = "";
					
					for (j = posicion_siguiente_caracter ; nombre_completo[j] != SEPARADOR ; j++){
						palabra_extraida.push_back(tolower(nombre_completo[j]));
					}
				
					for(int z = 0 ; z < num_caracteres_a_coger && z < palabra_extraida.size() ; z++){
						nombre_sugerido = nombre_sugerido + palabra_extraida[z];
					}
				
					posicion_siguiente_caracter = j + 1;
					i++;
			}
			
			return nombre_sugerido;	
		}
};
	
int main(){
	
	char caracter;
	char TERMINADOR = '#';
	int numero;
	string cadena;
	
	cout << "Introduzca un número: ";
	cin >> numero;
	
	Login usuario(numero);
	
	cout << "Introduzca un nombre: ";
	
	caracter = cin.get();
	to_string(caracter);

	while(caracter != TERMINADOR){
		
		cadena = cadena + caracter;
		to_string(caracter);
		caracter = cin.get();
	}
	
	cout << "\nUsuario sugerido: " << usuario.Codifica(cadena);	
}
