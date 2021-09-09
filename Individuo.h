/*
  Archivo: Individuo.h
  Autores: Miguel Fernandez Villaquirán, David Alberto Guzmán.
  <fernandez.miguel@correounivalle.edu.co>
  <david.alberto.guzman@correounivalle.edu.co>
  Fecha creación: 2020-09-10
  Fecha última modificación: 2020-12-20
  Licencia: GNU-GPL
*/

/*
  Clase: Individuo
  Atributos: posicionIndividuo, tipoIndividuo, puedeComer, esComestible, individuosComestibles, *lugar.
  Funcionalidades:
    - Dice el nombre del individuo.
    - Menciona que tipo de individuo se definió.
    - Da la ubicación del individuo.
    - Da el número que identifica al individuo.
    - Cambia la ubicación del individuo.
    - Conoce a los individuos comestibles.
    - Dice cuántos individuos se puede comer el individuo actual.
    - Encuentra un individuo comestible si lo hay.
    - Accede a un individuo comestible.
  Relaciones: Individuo conoce a Individuo.
*/

#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include "Lugar.h"
#include <string>
#include <vector>
using namespace std;

class Individuo
{
  protected:
    string nombreIndividuo; 
    string tipoIndividuo;
    string lugar;
    int numeroIdentificador;
    vector <Individuo *> individuosComestibles;

  public:
    // Constructor
    Individuo (string nombreIndividuo, string tipoIndividuo, string lugar, int numeroIdentificador);

    //Destructor
    virtual ~Individuo();                   
    
    //revela el nombre del individuo
    virtual string nombreDelIndividuo(); 

    //accede al atributo "tipoIndividuo"
    virtual string tipoDeIndividuo();

    //expone el lugar donde se encuentra el individuo
    virtual string ubicacion();

    //muestra el número que identifica al individuo
    virtual int identificador();

    //cambia la ubicacion del individuo
    virtual void cambiarUbicacion(string nuevaUbicacion);

    //con esta función el individuo conoce a un personaje comestible.
    virtual void conocerIndividuoComestible(Individuo *personaje);

    //Dice cuantos individuos se pueden comer.
    virtual int cuantosComestibles();

    //accede a algun individuo comestible dependiendo del numero de individuo.
    virtual Individuo *cualComestible(int numeroIndividuo);
    
};

#else
class Individuo; //Declaración adelantada
#endif
