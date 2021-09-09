/*
  Archivo: Lugar.h
  Autores: Miguel Fernandez Villaquirán, David Alberto Guzmán.
  <fernandez.miguel@correounivalle.edu.co>
  <david.alberto.guzman@correounivalle.edu.co>
  Fecha creación: 2020-09-10
  Fecha última modificación: 2020-12-20
  Licencia: GNU-GPL
*/

/*
  Clase: Lugar
  Atributos: tipoLugar, vecino, individuos.
  Funcionalidades:
    - Dice el tipo de lugar que es. 
    - Indica si hay un muerto. 
    - Hace que el lugar conozca al individuo. 
    - Determina si un individuo esta en el lugar.
    - Busca si un individuo esta en el lugar y lo muestra. 
    - Borra un individuo determinado. 
    - Dice la cantidad de individuos que hay actualmente.
    - Dice quien es el vecino actual.
    - Mueve el lugar.
    - Cambia quien es el vecino.
  Relaciones: Conoce a Individuo, conoce a lugar.
*/

#ifndef LUGAR_H
#define LUGAR_H

#include <vector>
#include <string>
#include "Individuo.h"
using namespace std;

class Lugar
{
  protected: 
    string tipoLugar;
    Lugar *vecino;
    vector <Individuo *> individuos; 
    

  public:
    //Constructor
    Lugar(string tipoLugar);

    //Destructor
    virtual ~Lugar();

    //Muestra el tipo de lugar
    virtual string lugarActual(); 

    //Determina si se pierde el juego, identificando si hay una presa y un cazador en el mismo sitio sin el robot.
    virtual bool hayUnMuerto(); 

    //introduce a un individuo en el vector de individuos
    virtual void conocerIndividuo(Individuo *personaje); 

    //Consulta si hay un individuo de un tipo determinado en el lugar.
    virtual bool estaElIndividuo(string tipoPersonaje);

    //Consulta si hay un individuo determinado con su identificador en el lugar.
    virtual bool estaElIndividuo(string tipoPersonaje, int identificacion);  

    //Consulta cual es el n-esimo inviduo que conoce el lugar.
    virtual Individuo *cualIndividuo(int numero); 

    //retorna una copia de un puntero de individuos con un individuo determinado, si lo hay
    virtual Individuo *cualIndividuo(string tipoDeIndividuo, int identificacion);

    //con esta función el lugar perderá un individuo determinado.
    virtual void cederIndividuo(string tipoDeIndividuo, int identificacion);

    //Dice cuantos individuos hay en el lugar
    virtual int cuantosIndividuos();

    //permite que el lugar se pueda mover. Es Virtual Pura, porque algunos lugares no pueden moverse.
    virtual void moverse() = 0;

    //revela el nombre del lugar vecino.
    virtual Lugar* cualVecino();
    
    //Modifica el vecino del lugar
    virtual void cambiarVecino(Lugar *nuevoVecino);

};

#else
class Lugar; //Declaración adelantada
#endif

