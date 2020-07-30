 /*
Definir la clase AlumnoFP, que almacene el nombre, el primer apellido, el DNI del alumno y cada una de las partes consideradas en la evaluación 
de la asignatura: teoría, parcial_pract1, parcial_pract2, participación_clase. La escala utilizada para evaluar cada parte es de 0 a 10.
- Construir los constructores necesarios para poder asignar valores a los miembros de la clase.
- Construir un método que calcule la nota final del alumno. Para ello se debe de tener en cuenta los porcentajes de las distintas partes 
consideradas: 70% teoría, 5% parcial 1, 15% parcial 2 y 10% participación.
- Construir un método que calcule la nota final del alumno.
- Construir un programa que lea los datos del alumno y en caso de haber obtenido una nota inferior a 5 en alguna de las partes que indique 
la nota obtenida en dicha parte.
*/

#include <iostream>

using namespace std;

class AlumnoFP{
	private:
		string nombre, apellido;
		int dni;
		double teoria = 0, parcial_pract1 = 0, parcial_pract2 = 0, participacion_clase = 0;
		double PORCENTAJE_TEORIA = 0.7;
		double PORCENTAJE_PRIMER_PARCIAL = 0.05;
		double PORCENTAJE_SEGUNDO_PARCIAL = 0.15;
		double PORCENTAJE_PARTICIPACION = 0.1;
		
		bool NotaCorrecta (double nota_correcta){
			return 0 <= nota_correcta && nota_correcta <= 10;
		}
		
	public:

		// Constructor
		
		AlumnoFP(string nombre, string apellido, int dni, double teoria, double parcial_pract1, double parcial_pract2, double participacion_clase){
			
			SetNombre(nombre);
			SetApellido(apellido);
			SetDni(dni);
			SetTeoria(teoria);
			SetPrimerParcial(parcial_pract1);
			SetSegundoParcial(parcial_pract2);
			SetParticipacionClase(participacion_clase);
		}
		
		// Métodos para el constructor
		
		void SetNombre (string nombre_alumno){
			nombre = nombre_alumno;
		}
		
		void SetApellido (string apellido_alumno){
			apellido = apellido_alumno;
		}
		
		void SetDni (int dni_alumno){
			dni = dni_alumno;
		}
		
		void SetTeoria (double examen_teoria){
			if (NotaCorrecta(examen_teoria))
				teoria = examen_teoria;
		}
		
		void SetPrimerParcial (double primer_parcial){
			if (NotaCorrecta(primer_parcial))
				parcial_pract1 = primer_parcial;
		}
		
		void SetSegundoParcial (double segundo_parcial){
			if (NotaCorrecta(segundo_parcial))
				parcial_pract2 = segundo_parcial;
		}
		
		void SetParticipacionClase (double participacion){
			if (NotaCorrecta(participacion))
				participacion_clase = participacion;				
		}
		
		// Métodos para obtener las notas independientes y la nota final
		
		double GetTeoria(){
			return teoria;
		}
		
		double GetPrimerParcial(){
			return parcial_pract1;
		}
		
		double GetSegundoParcial(){
			return parcial_pract2;
		}
		
		double GetParticipacion(){
			return participacion_clase;
		}
		
		double NotaFinal (){
			
			return teoria * PORCENTAJE_TEORIA + parcial_pract1 * PORCENTAJE_PRIMER_PARCIAL + parcial_pract2 * PORCENTAJE_SEGUNDO_PARCIAL + participacion_clase * PORCENTAJE_PARTICIPACION;
		}
			
};

int main(){
	
	string nombre, apellido;
	int dni;
	double teoria, primer_parcial, segundo_parcial, participacion_clase, nota_final;
	
	cout << "Nombre del alumno: ";
	cin >> nombre;
	cout << "Apellido del alumno: ";
	cin >> apellido;
	cout << "DNI del alumno (sin letra): ";
	cin >> dni;
	cout << "Nota del examen de teoría: ";
	cin >> teoria;
	cout << "Nota del primer parcial: ";
	cin >> primer_parcial;
	cout << "Nota del segundo parcial: ";
	cin >> segundo_parcial;
	cout << "Nota de la participación en clase: ";
	cin >> participacion_clase;
	
	AlumnoFP un_alumno(nombre, apellido, dni, teoria, primer_parcial, segundo_parcial, participacion_clase);
	
	nota_final = un_alumno.NotaFinal();
	
	cout << "\nNota final del alumno: " << nota_final << "\n";
	
	// Si alguna nota está suspensa, se notifica
	
	if (un_alumno.GetTeoria() < 5)
		
		cout <<"\nEl alumno ha obtenido un " << un_alumno.GetTeoria() << " en el examen de teoría";
	
	if (un_alumno.GetPrimerParcial() < 5)
		
		cout <<"\nEl alumno ha obtenido un " << un_alumno.GetPrimerParcial() << " en el primer parcial";
		
	if (un_alumno.GetSegundoParcial() < 5)
	
		cout <<"\nEl alumno ha obtenido un " << un_alumno.GetSegundoParcial() << " en el segundo parcial";
	
	if (un_alumno.GetParticipacion() < 5)
	
		cout <<"\nEl alumno ha obtenido un " << un_alumno.GetParticipacion() << " en la participación en clase";
	
	cout << "\n";
	system("pause");
}

