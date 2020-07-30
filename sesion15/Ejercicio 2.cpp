/*
Sobre el ejercicio anterior, implemente un m�todo para determinar
si un cuadrado contiene a otro. Un cuadrado C1 determinado por la esquina
(x1; y1) y la longitud l1 contiene a otro cuadrado C2 dado por (x2; y2) y l2 si se cumple
que x2 >= x1 y x2 + l2 <= x1 + l1 y y2 >= y1 y y2 + l2 <= y1 + l1
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927;

bool SonIguales(double uno, double otro){
    return abs(uno-otro) <= 1e-6;
}

class Punto2D{
private:
   double abscisa  = 0.0;
   double ordenada = 0.0;
public:
   Punto2D(double abscisaPunto, double ordenadaPunto)
   {
      SetCoordenadas(abscisaPunto, ordenadaPunto);
   }
   
   double Abscisa(){
      return abscisa;
   }
   
   double Ordenada(){
      return ordenada;
   }
   
   void SetCoordenadas(double abscisaPunto, double ordenadaPunto){
      if (! SonIguales(abscisaPunto, ordenadaPunto)){
         abscisa = abscisaPunto;
         ordenada = ordenadaPunto;
      }
   }
   
   bool EsIgual_a (Punto2D otro_punto){
      return (SonIguales(abscisa, otro_punto.abscisa)
              &&
              SonIguales(ordenada, otro_punto.ordenada));
   }
};

class SegmentoDirigido{
private:
   double x_1 = 0.0,
          y_1 = 0.0,
          x_2 = 0.0,
          y_2 = 0.0;
   
   bool SonCorrectos(double origen_abscisa, double origen_ordenada,
                     double final_abscisa,  double final_ordenada){
 
      return !(origen_abscisa == final_abscisa
               &&
               origen_ordenada == final_ordenada);
   }
   
public:
   SegmentoDirigido(double origen_abscisa, double origen_ordenada,
                    double final_abscisa, double final_ordenada){

      SetCoordenadas(origen_abscisa, origen_ordenada,
                     final_abscisa, final_ordenada);
   }
   
   void SetCoordenadas(double origen_abscisa, double origen_ordenada,
                       double final_abscisa,  double final_ordenada){
      if (SonCorrectos(origen_abscisa, origen_ordenada,
                       final_abscisa, final_ordenada)){
         x_1 = origen_abscisa;
         y_1 = origen_ordenada;
         x_2 = final_abscisa;
         y_2 = final_ordenada;
      }
   }
   
   double OrigenAbscisa(){
      return x_1;
   }
   
   double OrigenOrdenada(){
      return y_1;
   }
   
   double FinalAbscisa(){
      return x_2;
   }
   
   double FinalOrdenada(){
      return y_2;
   }
   
   double Longitud(){
      return sqrt((x_2 - x_1)*(x_2 - x_1) +
                  (y_2 - y_1)*(y_2 - y_1));
   }
   
   void TrasladaHorizontal(double unidades){
      x_1 = x_1 + unidades;
      x_2 = x_2 + unidades;
   }
   
   void TrasladaVertical(double unidades){
      y_1 = y_1 + unidades;
      y_2 = y_2 + unidades;
   }
};

class Circunferencia{
private:
   double centro_x = 0.0;
   double centro_y = 0.0;
   double radio    = 0.0;
      
   bool EsCorrectoRadio(double longitud_radio){
      return longitud_radio > 0; 
   }
public:
   Circunferencia(double abscisa_centro, double ordenada_centro,
                  double longitud_radio){
      SetCentro(abscisa_centro, ordenada_centro);
      SetRadio(longitud_radio);
   }
   
   void SetRadio(double longitud_radio){
      if (EsCorrectoRadio(longitud_radio))
         radio = longitud_radio;
   }
   
   void SetCentro(double abscisa_centro, double ordenada_centro){
      centro_x = abscisa_centro;
      centro_y = ordenada_centro;
   }

   double AbscisaCentro(){
      return centro_x;
   }
   
   double OrdenadaCentro(){
      return centro_y;
   }
   
   double Radio(){
      return radio;
   }
   
   double Longitud(){
      return 2*PI*radio;
   }
   
   double Area(){
      return PI*radio*radio;
   }
   
   void Traslada(double en_horizontal, double en_vertical){
      centro_x = centro_x + en_horizontal;
      centro_y = centro_y + en_vertical;
   }
};

class Cuadrado{
private:
   double esquina_abscisa;
   double esquina_ordenada;
   double longitud;

   bool EsCorrectaLongitud(double longitud){
      return longitud > 0; 
   }
public:
   Cuadrado(double esquina_abscisa_cuadrado,
            double esquina_ordenada_cuadrado,
            double longitud_cuadrado){

      SetLongitud(longitud_cuadrado);
      SetEsquinaInfIzq(esquina_abscisa_cuadrado, esquina_ordenada_cuadrado);
   }
   
   void SetLongitud(double longitud_cuadrado){
      if (EsCorrectaLongitud(longitud_cuadrado))
         longitud = longitud_cuadrado;
   }

   void SetEsquinaInfIzq(double esquina_abscisa_cuadrado,
                         double esquina_ordenada_cuadrado){
      esquina_abscisa = esquina_abscisa_cuadrado;
      esquina_ordenada = esquina_ordenada_cuadrado;
   }
   
   double AbscisaEsquina(){
      return esquina_abscisa;
   }

   double OrdenadaEsquina(){
      return esquina_ordenada;
   }

   double Longitud(){
      return longitud;
   }

   double Area(){
      return longitud * longitud;
   }

   double Perimetro(){
      return longitud*4;
   }

   SegmentoDirigido Lado1(){
      SegmentoDirigido lado(esquina_abscisa, esquina_ordenada, 
                            esquina_abscisa + longitud, esquina_ordenada);
      return lado;
   }
   
   SegmentoDirigido Lado2(){
      SegmentoDirigido lado(esquina_abscisa + longitud, esquina_ordenada, 
                            esquina_abscisa + longitud, esquina_ordenada + longitud);
      return lado;
   }
   
   SegmentoDirigido Lado3(){
      SegmentoDirigido lado(esquina_abscisa + longitud, esquina_ordenada + longitud, 
                            esquina_abscisa, esquina_ordenada + longitud);
      return lado;
   }
   
   SegmentoDirigido Lado4(){
      SegmentoDirigido lado(esquina_abscisa, esquina_ordenada + longitud, 
                            esquina_abscisa, esquina_ordenada);
      return lado;
   }
   
   Punto2D Centro(){
      
		double abscisa, ordenada;
		
		abscisa = esquina_abscisa + longitud / 2;
		ordenada = esquina_ordenada + longitud / 2;
		
		Punto2D centro(abscisa, ordenada);
		
      return centro;
   }

   Circunferencia CircunferenciaInscrita(){
   	
   	double radio;
      Punto2D centro(Centro());
      
      radio = longitud / 2;
      
      Circunferencia inscrita(centro.Abscisa(), centro.Ordenada(), radio);
      
      return inscrita;
      
   }

   Circunferencia CircunferenciaCircunscrita(){
      
      Punto2D centro(Centro());
      SegmentoDirigido segmento(centro.Abscisa(), centro.Ordenada(), esquina_abscisa, esquina_ordenada);
      Circunferencia circunscrita(centro.Abscisa(), centro.Ordenada(), segmento.Longitud());
      
      return circunscrita;
   }

   bool MayorArea_que(Cuadrado otro_cuadrado){
      
     return Area() >= otro_cuadrado.Area();   
   }
   
   bool Contiene(Cuadrado otro){
      return otro.AbscisaEsquina() >= esquina_abscisa && 
				(otro.Longitud() + otro.AbscisaEsquina()) <= (esquina_abscisa + Longitud()) && 
				esquina_ordenada >= otro.OrdenadaEsquina() &&
				(otro.Longitud() + otro.OrdenadaEsquina()) <= (esquina_ordenada + Longitud());
   }
};

int main(){
   double esquina_x, esquina_y, long_cuadrado;

   cout << "Introduzca la abscisa de la esquina inferior izquierda del cuadrado ";
   cin >> esquina_x;
   cout << "\nIntroduzca la ordenada de la esquina inferior izquierda del cuadrado  ";
   cin >> esquina_y;
   cout << "\nIntroduzca la longitud del cuadrado ";
   cin >> long_cuadrado;

   // Creamos el objeto cuadrado_A como un cuadrado con los datos anteriores

   Cuadrado cuadrado_A(esquina_x, esquina_y, long_cuadrado);      // Constructor usual con par�metros
   
   // Creamos las circunferencias inscritas y circunscritas a cuadrado_A
   // Las llamamos circunf_interior_cuadrado y circunf_exterior_cuadrado
   // Calculamos e imprimimos sus longitudes,
   // as� como las �reas de los correspondientes c�rculos
   // Imprimimos el �rea de cuadrado_A
   
   Circunferencia circunf_interior_cuadrado(cuadrado_A.CircunferenciaInscrita());
   Circunferencia circunf_exterior_cuadrado(cuadrado_A.CircunferenciaCircunscrita());

   cout << "\nCuadrado: ";
   cout << "\n�rea: " << cuadrado_A.Area();
   cout <<"\nLongitud: " << cuadrado_A.Perimetro();
   cout << "\n\nCircunferencia interior:";
   cout << "\nLongitud:     " << circunf_interior_cuadrado.Longitud();
   cout << "\n�rea circulo: " << circunf_interior_cuadrado.Area();
   cout << "\n\nCircunferencia exterior:";
   cout << "\nLongitud:     " << circunf_exterior_cuadrado.Longitud();
   cout << "\n�rea circulo: " << circunf_exterior_cuadrado.Area();

   // Creamos cuadrado_B a partr de los datos introducidos para el primero
   // Imprimimos las coordenas del punto central

   Cuadrado cuadrado_B(esquina_x + 1, esquina_y + 1, long_cuadrado - 2);   // Constructor usual con par�metros
   
   // Obtenemos el punto central de cuadrado_B
   
   Punto2D centro(cuadrado_B.Centro());
   
   cout << "\n\nSegundo cuadrado.";
   cout << "\nCoordenadas del punto central: ";
   cout << centro.Abscisa() << " , " << centro.Ordenada();
   
   if (cuadrado_B.Contiene(cuadrado_A))
      cout << "\nCuadrado B contiene a cuadrado A";
   else
      cout << "\nCuadrado B no contiene a cuadrado A";

   cout << "\n\n";
   system("pause");
}
