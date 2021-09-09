/*
  Archivo: main.cpp
  Autores: Miguel Fernandez Villaquirán, David Alberto Guzmán.
  <fernandez.miguel@correounivalle.edu.co>
  <david.alberto.guzman@correounivalle.edu.co>
  Fecha creación: 2020-09-10
  Fecha última modificación: 2020-12-20
  Licencia: GNU-GPL
*/
/*Historia: Hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del río hasta la otra orilla,usando una barca. En la barca solo cabe uno de los tres individuos, además del robot. El problema es que si el robot deja solos al zorro y el conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga. El jugador debe controlar que órdenes dar, para lograr que el robot transporte los tres individuos a la otra orilla sanos y salvos.
*/

#include "Barca.h"
#include "Orilla.h"
#include "Jugador.h"
#include "Individuo.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  try
  {
    //Jugador
    Jugador *jugador = new Jugador("");
  
    //Lugares
    Lugar *izquierda = new Orilla("Orilla Izquierda");
    Barca *barca = new Barca;
    Lugar *derecha = new Orilla("Orilla Derecha");
    
    //Individuos
    vector<Individuo *> individuos = 
    {
      new Individuo("El vecino", "Robot",izquierda->lugarActual(),1),
      new Individuo("Wolverine", "Zorro",izquierda->lugarActual(),1),
      new Individuo("Bad Bunny", "Conejo",izquierda->lugarActual(),1),
      new Individuo("laLechuga", "Lechuga",izquierda->lugarActual(),1),
      new Individuo("Good Bunny", "Conejo",izquierda->lugarActual(),2),
      new Individuo("Robot Guay", "Robot",izquierda->lugarActual(),2)
    };
  
    //La orilla izquierda conoce al principio todos los individuos y el jugador también.
    for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
    {
      Individuo *elIndividuo = individuos[cualIndividuo];
      izquierda->conocerIndividuo(elIndividuo);
      jugador->conocerIndividuo(elIndividuo);
    }

    //el jugador conoce los lugares también.
    jugador->conocerLugar(izquierda);
    jugador->conocerLugar(derecha);
    jugador->conocerLugar(barca);

    //La barca conoce las orillas. 
    barca->conocerOrilla(izquierda);
    barca->conocerOrilla(derecha);

    //acá trato de hacer que cada individuo conozca sus comestibles.
    for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
    {
      Individuo *elIndividuo = individuos[cualIndividuo];
     
      if(elIndividuo->tipoDeIndividuo() == "Zorro")
      {
        for(int numeroIndividuo = 0; numeroIndividuo < individuos.size(); numeroIndividuo++)
        {
          Individuo *otroIndividuo = individuos[numeroIndividuo];
          if(otroIndividuo->tipoDeIndividuo() == "Conejo")
          {
            elIndividuo->conocerIndividuoComestible(otroIndividuo);
          }
        }
      }
      if(elIndividuo->tipoDeIndividuo() == "Conejo")
      {
        for(int numeroIndividuo = 0; numeroIndividuo < individuos.size(); numeroIndividuo++)
        {
          Individuo *otroIndividuo = individuos[numeroIndividuo];
          if(otroIndividuo->tipoDeIndividuo() == "Lechuga")
          {
            elIndividuo->conocerIndividuoComestible(otroIndividuo);
          }
        }
      }
    }

    //aca relaciono a los vecinos 
    //La barca es vecina para la orilla izquierda y viceversa
    barca->cambiarVecino(izquierda);
    izquierda->cambiarVecino(barca); 

    //Comienza la partida.
    jugador->comenzarPartida();
    
    //Esta parte del código es para borrar memory leaks.
    delete jugador;
    jugador = nullptr;

  }
  catch(const string &mensaje)
  {
    cout << "ERROR: " << mensaje << endl;
  }

  return 0;
} 