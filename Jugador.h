/*
  Archivo: Barca.h
  Autores: David Alberto Guzmán y Miguel Ángel Fernandez
  Emails: fernandez.miguel@correounivalle.edu.co y david.alberto.guzman@correounivalle.edu.co
  Fecha creación: 2020-10-09
  Fecha última modificación: 2020-12-21
  Versión: 1.1
  Licencia: GNU-GPL
*/

/*
  Clase: Jugador
  Atributos: nombre, lugar, individuos.
  Funcionalidades:
    -Inicia el juego con su parte gráfica.
    -Gráfica el juego y recibe los movimientos.
    -Compara si un individuo esta repetido.
    -Hace que el jugador conozca a los lugares.
    -Hace que el jugador conozca a los individuos.
    -Verifica si un string es un numero.
    -Muestra un lugar determinado.
    -Muestra un individuo determinado.
    -Determina que string es mayor.
    -Crea espacios para el gráfico del juego.
    -Ubica dentro de los espacios.
    -Determina el gráfico.
  Relaciones: Conoce a lugar y a individuo.
*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Individuo.h"
#include "Lugar.h"
#include "Barca.h"
#include<vector>
#include<string>
using namespace std;

class Jugador
{
  private:

    string nombre; 

    vector <Individuo *> individuos;

    vector <Lugar *> lugar;
    
  public:
    //Constructor
    Jugador(string nombre);

    //Destructor
    virtual ~Jugador();

    //Funcionalidades

    //inicia la partida
    virtual void comenzarPartida();

    //Establece los graficos del juego y recibe las respuestas del jugador para mover a los personajes.
    virtual void jugar(string respuesta, int cualIdentificador, bool &hayUnahogado);

    //logra identificar a individuos repetidos conociendo la respuesta del jugador.
    virtual bool estaRepetido(string respuesta); 

    //esta funcion le permite al jugador identificar los lugares del juego.
    virtual void conocerLugar(Lugar * elLugar);

    //introduce a un individuo en el vector de individuos
    virtual void conocerIndividuo(Individuo *elIndividuo);

    //Corrobora que un string sea un numero
    virtual bool esUnNumero(string palabra);

    //muestra un lugar determinado de todos los posibles
    virtual Lugar *cualLugar(string unLugar);

    //muestra un individuo determinado de todos los posibles. No se usa.
    virtual Individuo *individuo(string individuo, int identificacion);

    //Determina cual string es mayor
    virtual string stringMayor(vector<string> strings);

    //pone los espacios para el grafico del juego.
    virtual string ponerEspacios(string unString, string mayor);

    //Ubica a los individuos dentro de los espacios del grafico del juego.
    virtual string ponerEspacios(Lugar *elLugar, int numeroIndividuo);

    //pone el grafico del juego
    virtual void ponerGrafico(string stringMayor, Lugar *izquierda, Lugar *derecha, Lugar *barca);

};

#else
class Jugador;
#endif