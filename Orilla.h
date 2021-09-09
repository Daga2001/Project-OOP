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
  Clase: Orilla
  Atributos: cualOrilla.
  Funcionalidades:
    - Tiene las funcionalidades de Lugar.
  Relaciones: Orilla es un lugar.
*/

#ifndef ORILLA_H
#define ORILLA_H

#include <string>
#include "Lugar.h"
using namespace std;

class Orilla: public Lugar
{
  protected:

  public:
    //Constructor
    Orilla(string tipoLugar);
    
    //Destructor
    virtual ~Orilla();

    // Esta función es inutil acá, pues la orilla no se mueve.
    virtual void moverse();
    
};

#else
class Orilla; 
#endif