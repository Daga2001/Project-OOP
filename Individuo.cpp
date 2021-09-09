/*
  Archivo: Individuo.cpp
  Autores: Miguel Fernandez Villaquirán, David Alberto Guzmán.
  <fernandez.miguel@correounivalle.edu.co>
  <david.alberto.guzman@correounivalle.edu.co>
  Fecha creación: 2020-09-10
  Fecha última modificación: 2020-12-20
  Licencia: GNU-GPL
*/

#include "Individuo.h"

Individuo::Individuo(string nombreIndividuo, string tipoIndividuo, string lugar, int numeroIdentificador): nombreIndividuo(nombreIndividuo), tipoIndividuo(tipoIndividuo), lugar(lugar), numeroIdentificador(numeroIdentificador)
{

}

Individuo::~Individuo()
{
  
}

string Individuo::nombreDelIndividuo()
{
  return nombreIndividuo;
}

string Individuo::tipoDeIndividuo()
{
  return tipoIndividuo;
}

string Individuo::ubicacion()
{
  return lugar;
}

int Individuo::identificador()
{
  return numeroIdentificador;
}

void Individuo::cambiarUbicacion(string nuevaUbicacion)
{
  lugar = nuevaUbicacion;
}

void Individuo::conocerIndividuoComestible(Individuo *personaje)
{
  individuosComestibles.push_back(personaje);
}

int Individuo::cuantosComestibles()
{
  return individuosComestibles.size();
}

Individuo *Individuo::cualComestible(int numeroComestible)
{
  return individuosComestibles.at(numeroComestible);
}