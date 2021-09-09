/*
  Archivo: Lugar.cpp
  Autores: Miguel Fernandez Villaquirán, David Alberto Guzmán.
  <fernandez.miguel@correounivalle.edu.co>
  <david.alberto.guzman@correounivalle.edu.co>
  Fecha creación: 2020-09-10
  Fecha última modificación: 2020-12-20
  Licencia: GNU-GPL
*/

#include "Lugar.h"
#include <iostream>
using namespace std;

Lugar::Lugar(string tipoLugar): tipoLugar(tipoLugar)
{
  this->vecino=nullptr;
}

Lugar::~Lugar()
{
  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    delete individuos[cualIndividuo];
    individuos[cualIndividuo]=nullptr;
  }
}

Lugar* Lugar::cualVecino()
{
  return vecino;
}

string Lugar::lugarActual()
{
  return tipoLugar;
}

void Lugar::conocerIndividuo(Individuo *personaje)
{
  personaje->cambiarUbicacion(tipoLugar);

  individuos.push_back(personaje);
}

bool Lugar::estaElIndividuo(string tipoPersonaje)
{
  Individuo *elIndividuo = nullptr;
  string tipoIndividuo;

  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    tipoIndividuo = individuos.at(cualIndividuo)->tipoDeIndividuo();
    if(tipoIndividuo == tipoPersonaje)
    {
      elIndividuo = individuos.at(cualIndividuo);
      if(elIndividuo->ubicacion() == lugarActual())
      {
        return true;
      }
    }
  }
  return false;
}

bool Lugar::estaElIndividuo(string tipoPersonaje, int identificacion)
{
  Individuo *elIndividuo = nullptr;
  int numeroIdentificacion;
  string tipoIndividuo;

  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    tipoIndividuo = individuos.at(cualIndividuo)->tipoDeIndividuo();
    numeroIdentificacion = individuos.at(cualIndividuo)->identificador();

    if(tipoIndividuo == tipoPersonaje and numeroIdentificacion == identificacion)
    {
      elIndividuo = individuos.at(cualIndividuo);
      if(elIndividuo->ubicacion() == lugarActual())
      {
        return true;
      }
    }
  }
  return false;
}

bool Lugar::hayUnMuerto()
{
  Individuo *elIndividuo = nullptr;
  Individuo *comestible = nullptr;

  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    elIndividuo = individuos.at(cualIndividuo);
    
    for(int numeroComestible = 0; numeroComestible < elIndividuo->cuantosComestibles(); numeroComestible++)
    {
      comestible= elIndividuo->cualComestible(numeroComestible);

      if(elIndividuo->ubicacion() == comestible->ubicacion() and not estaElIndividuo("Robot"))
      {
        cederIndividuo(elIndividuo->tipoDeIndividuo(), elIndividuo->identificador());
        return true;
      }
    }
  }
  return false;
}

void Lugar::cambiarVecino(Lugar *nuevoVecino)
{
  vecino = nuevoVecino;
}

Individuo *Lugar::cualIndividuo(int numero)
{
  int cuantosIndividuos = individuos.size();

  if(numero < cuantosIndividuos)
  {
    return individuos.at(numero);
  }
  else
  {
    return nullptr;
  }
}

Individuo *Lugar::cualIndividuo(string tipoDeIndividuo, int identificacion)
{
  Individuo *personaje = nullptr;
  string tipoIndividuo;
  int numeroIdentificador;

  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    Individuo *elPersonaje = individuos.at(cualIndividuo);
    string tipoIndividuo = elPersonaje->tipoDeIndividuo();
    numeroIdentificador = elPersonaje->identificador();

    if(tipoIndividuo == tipoDeIndividuo and numeroIdentificador == identificacion)
    {
      personaje = elPersonaje;
    }
  }
  return personaje;
}

void Lugar::cederIndividuo(string tipoDeIndividuo, int identificacion)
{
  string individuo;
  int numeroIdentificacion;

  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    individuo = individuos.at(cualIndividuo)->tipoDeIndividuo();
    numeroIdentificacion = individuos.at(cualIndividuo)->identificador(); 

    if(tipoDeIndividuo == individuo and identificacion == numeroIdentificacion)
    {
      individuos.erase(individuos.begin() + cualIndividuo);
      break;
    }
  }
}

int Lugar::cuantosIndividuos()
{
  return individuos.size();
}