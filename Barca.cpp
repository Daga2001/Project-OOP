/*
  Archivo: Barca.cpp
  Autores: David Alberto Guzmán y Miguel Ángel Fernandez
  Emails: fernandez.miguel@correounivalle.edu.co y david.alberto.guzman@correounivalle.edu.co
  Fecha creación: 2020-10-09
  Fecha última modificación: 2020-12-20
  Versión: 1.0
  Licencia: GNU-GPL
*/

#include "Barca.h"
using namespace std;

Barca::Barca(): Lugar("Barca")
{
  
}

Barca::~Barca() 
{
  
} 

void Barca::conocerOrilla(Lugar *orilla)
{
  orillas.push_back(orilla);
}

Lugar *Barca::laOrilla(string orillaABuscar)
{
  Lugar *laOrilla = nullptr;
  for(int cualOrilla = 0; cualOrilla < orillas.size(); cualOrilla++)
  {
    laOrilla = orillas.at(cualOrilla);

    if(laOrilla->lugarActual()==orillaABuscar)
    {
      return laOrilla;
    }
  }
  return nullptr; 
}

void Barca::moverse()
{
  string vecinoActual = vecino->lugarActual();
  Lugar *orillaIzquierda = laOrilla("Orilla Izquierda");
  Lugar *orillaDerecha = laOrilla("Orilla Derecha");

  if(vecinoActual == "Orilla Izquierda" )
  {
    cambiarVecino(orillaDerecha);
  }
  
  if(vecinoActual == "Orilla Derecha" )
  {
    cambiarVecino(orillaIzquierda);
  }

}
