/*
  Archivo: Barca.h
  Autores: David Alberto Guzmán y Miguel Ángel Fernandez
  Emails: fernandez.miguel@correounivalle.edu.co y david.alberto.guzman@correounivalle.edu.co
  Fecha creación: 2020-10-09
  Fecha última modificación: 2020-12-20
  Versión: 1.0
  Licencia: GNU-GPL
*/

/*
  Clase: Barca
  Atributos: Vector Orillas, Las mismas que lugar.
  Funcionalidades:
    - Puede moverse a otra orilla.
    - Hace que conozca una orilla.
    - Menciona alguna orilla que conoce la barca.
    - Tiene las mismas Funcionalidades de lugar.
  Relaciones: Barca es parecido a un Lugar, conoce a Orilla.
*/

#ifndef BARCA_H
#define BARCA_H

#include<vector>
#include "Lugar.h"
#include "Orilla.h"
using namespace std;

class Barca: public Lugar
{
  protected:
    vector <Lugar *> orillas;

  public:
    //Constructor
    Barca();

    //Destructor
    virtual ~Barca();

    //Funcionalidades

    //Mueve la barca hacía una orilla.
    virtual void moverse(); 

    //sirve para que la barca conozca las orillas.
    virtual void conocerOrilla(Lugar *orilla);

    //extrae una orilla determinada del vector de orillas.
    virtual Lugar * laOrilla(string orillaABuscar);
};

#else
class Barca;
#endif 