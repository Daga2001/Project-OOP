/*
  Archivo: Jugador.cpp
  Autores: Miguel Fernandez Villaquirán, David Alberto Guzmán.
  <fernandez.miguel@correounivalle.edu.co>
  <david.alberto.guzman@correounivalle.edu.co>
  Fecha creación: 2020-09-10
  Fecha última modificación: 2020-12-21
  Licencia: GNU-GPL
*/


#include "Jugador.h"
#include <iostream>
using namespace std;

Jugador::Jugador(string nombre): nombre(nombre)
{

}

Jugador::~Jugador()
{
  for(int cualLugar = 0; cualLugar < lugar.size(); cualLugar++)
  {
    delete lugar[cualLugar];
    lugar[cualLugar]=nullptr;
  }
}

string Jugador::stringMayor(vector<string> strings)
{
  int elString = strings.at(0).length();
  int otroString;
  string mayor = strings.at(0);

  if(strings.size() > 1)
  {
    for(int cualString = 1; cualString < strings.size(); cualString++)
    {
      otroString = strings.at(cualString).length();
      
      if(elString < otroString)
      {
        mayor = strings.at(cualString);  
      }
      
      elString = mayor.length();

      if(cualString == strings.size() - 1)
      {
        return mayor;
      }

    }
  }
  throw string("Debe insertar un vector de strings con al menos 2 elementos para comparar.");
}

string Jugador::ponerEspacios(string unString, string mayor)
{
  int tamanhoStringArbitrario = unString.length();
  int tamanhoStringMayor = mayor.length();

  if(tamanhoStringArbitrario > tamanhoStringMayor)
  {
    throw string("debes poner el string mas grande donde corresponde!.");
  }
  else
  {
    while(unString.length() != mayor.length())
    {
      unString += " ";
    }
    return unString + "   ";
  }
}

string Jugador::ponerEspacios(Lugar *elLugar, int numeroIndividuo)
{
  numeroIndividuo --;
  vector<string> losString;
  Individuo *elIndividuo = nullptr;
  
  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    elIndividuo = individuos.at(cualIndividuo);
    losString.push_back(elIndividuo->tipoDeIndividuo());
  }

  losString.push_back("BARCA");
  losString.push_back("IZQUIERDA");
  losString.push_back("DERECHA");

  if(numeroIndividuo < elLugar->cuantosIndividuos())
  {
    elIndividuo = elLugar->cualIndividuo(numeroIndividuo);
    
    string tipoIndividuo = elIndividuo->tipoDeIndividuo();

    string identificacion = to_string(elIndividuo->identificador());

    return ponerEspacios(tipoIndividuo + identificacion,stringMayor(losString));
  }

  else
  {
    return ponerEspacios(" ", stringMayor(losString));
  } 

}

void Jugador::conocerLugar(Lugar * elLugar)
{
  lugar.push_back(elLugar);
}

void Jugador::conocerIndividuo(Individuo *elIndividuo)
{
  individuos.push_back(elIndividuo);
}

bool Jugador::esUnNumero(string palabra)
{
  if(palabra.size() == 0)
  {
    throw string("la palabra es un string vacío.");
  }
  for(int letra = 0; letra < palabra.size(); letra++)
  {
    if(not isdigit(palabra[letra]))
    {
      return false;
    }
  }
  return true;
}

Lugar *Jugador::cualLugar(string unLugar)
{
  Lugar *elLugar = nullptr;

  for(int numeroLugar = 0; numeroLugar < lugar.size(); numeroLugar++)
  {
    elLugar = lugar.at(numeroLugar);

    if(elLugar->lugarActual() == unLugar)
    {
      return elLugar;
    }
  }
  return nullptr; 
}

Individuo *Jugador::individuo(string individuo, int identificacion)
{
  Individuo *elIndividuo = nullptr;
  int numeroIdentificador;

  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    elIndividuo = individuos.at(cualIndividuo);
    numeroIdentificador = elIndividuo->identificador();

    if(elIndividuo->tipoDeIndividuo() == individuo and numeroIdentificador == identificacion)
    {
      return elIndividuo;
    }
  }
  return nullptr;
}

bool Jugador::estaRepetido(string respuesta)
{
  //Esto vuelve la respuesta que dimos como mayuscula
  respuesta.front() = toupper(respuesta.front());
  //Variables auxiliares para el algoritmo.
  char laRespuesta = respuesta.at(0);
  char primeraLetraIndividuo;
  Individuo *individuo1;
  Individuo *individuo2;
  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    individuo1 = individuos.at(cualIndividuo);
    primeraLetraIndividuo = individuo1->tipoDeIndividuo().at(0);
    if(primeraLetraIndividuo == laRespuesta)
    {
      //si es el último individuo
      if(cualIndividuo == individuos.size()-1)
      { 
        return false;
      }
      else
      {
        for(int otroIndividuo = cualIndividuo+1; otroIndividuo < individuos.size(); otroIndividuo++)
        {
          individuo2 = individuos.at(otroIndividuo);
          if(individuo1->tipoDeIndividuo() == individuo2->tipoDeIndividuo())
          {
            return true;
          }
        }
      }  
    }
  }
  return false; 
}

void Jugador::comenzarPartida()
{
  Lugar *barca = cualLugar("Barca");
  Lugar *izquierda = cualLugar("Orilla Izquierda");
  Lugar *derecha = cualLugar("Orilla Derecha");
  Individuo *elIndividuo = nullptr;
  
  //este vector es para diseñar la parte grafica del juego.
  vector<string> losString;
  losString.push_back("IZQUIERDA");
  losString.push_back("DERECHA");
  losString.push_back("BARCA");

  //aca trato de meter los tipos de individuos en forma de string dentro del vector de strings.
  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    elIndividuo = individuos.at(cualIndividuo);
    losString.push_back(elIndividuo->tipoDeIndividuo());
  }

  string mayorString = stringMayor(losString);

  bool hayUnMuerto = false;
  bool hayUnAhogado = false;
  bool hayVictoria = false;

  cout << "cuál es tu nombre?" << endl;
  getline(cin, nombre);

  while(not hayUnMuerto and not hayUnAhogado and not hayVictoria)
  {

    cout << "------------------------------------------------------" << "\n";

    cout << "B para mover la barca" << "\n";
    cout << "C para que el conejo entre/salga de la barca" << "\n";
    cout << "L para que la lechuga entre/salga de la barca" << "\n";
    cout << "R para que el robot entre/salga de la barca" << "\n";
    cout << "Z para que el zorro entre/salga de la barca" << "\n";
    cout << "SI EL INDIVIDUO ESTÁ REPETIDO, DIGITE EL NÚMERO QUE LO IDENTIFICA, EL CUAL ESTÁ A SU LADO" << "\n";

    cout << "------------------------------------------------------" << "\n";

    //Acá se coloca el grafico del juego
    ponerGrafico(mayorString, izquierda, derecha, barca);

    cout << "------------------------------------------------------" << "\n";

    string identifier;
    int identificador;
    string respuesta;
    //este bucle while es para evitar que el usuario digite un string invalido.
    while(respuesta.length() != 1)
    {
      cout << nombre+"," << " ¿Qué deseas hacer?" << endl;
      getline(cin, respuesta);

      if(respuesta.length() == 1)
      {
        if(estaRepetido(respuesta))
        {
          cout << "cual individuo quieres mover? (menciona su numero identificador)" << endl;
          getline(cin, identifier);

          while(identifier.size() == 0 or not esUnNumero(identifier))
          {
            cout << "------------------------------------------------------" << "\n";
            cout << "Error, por favor inserta un número" << endl;
            getline(cin, identifier);
          }

          identificador = stoi(identifier);
          break;
        }
        else
        {
          identificador = 1;
        }  
      }
      else
      {
        cout << "------------------------------------------------------" << "\n";
        cout << "por favor inserta una letra." << endl;
      }
    }   
    
    if(respuesta == "b" or respuesta == "B")
    {
      if(barca->estaElIndividuo("Robot"))
      {
        barca->cualVecino()->cambiarVecino(nullptr);
        barca->moverse();
        barca->cualVecino()->cambiarVecino(barca);
      }
      else
      {
        cout << "------------------------------------------------------" << "\n";
        cout << "El robot no está en la barca, Error!" << endl;
      }
    }
    else
    { 
      jugar(respuesta, identificador, hayUnAhogado);
    }

    hayUnMuerto = barca->hayUnMuerto() or izquierda->hayUnMuerto() or derecha->hayUnMuerto();

    hayVictoria = derecha->cuantosIndividuos() == individuos.size();

    if(hayVictoria)
    {
      cout << "------------------------------------------------------" << "\n";

      cout << "GANASTE!!, Felicidades :D" << endl;
    }

    if(hayUnMuerto)
    {
      cout << "------------------------------------------------------" << "\n";

      cout << "Perdiste, un individuo fue devorado!, vuelve a intentarlo." << endl;
    }
  }
}

void Jugador::jugar(string respuesta, int cualIdentificador, bool &ahogado)
{  
  //Esto vuelve la respuesta que dimos como mayuscula
  respuesta.front() = toupper(respuesta.front());
  //Variables auxiliares para el algoritmo.
  char laRespuesta = respuesta.at(0);
  char primeraLetraIndividuo;
  int identificacion;
  string tipoIndividuo;
  string lugarDelIndividuo;
  //Punteros auxiliares para el algoritmo.
  Lugar *elLugar;
  Lugar *vecinoLugar;
  Individuo *elIndividuo;

  for(int numeroLugar = 0; numeroLugar < lugar.size(); numeroLugar++)
  {
    elLugar = lugar.at(numeroLugar);
    vecinoLugar = elLugar->cualVecino();
    
    if(elLugar->lugarActual() == "Barca")
    {
      for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
      {
        elIndividuo = individuos.at(cualIndividuo);
        tipoIndividuo = elIndividuo->tipoDeIndividuo();
        primeraLetraIndividuo = tipoIndividuo.at(0);
        lugarDelIndividuo = elIndividuo->ubicacion();
        identificacion = elIndividuo->identificador();

        //si quiero meter/sacar individuos de la barca.
        if(laRespuesta == primeraLetraIndividuo and identificacion == cualIdentificador)
        { 
          //si el individuo no se arroja al agua.
          if(cualLugar(lugarDelIndividuo)->cualVecino() != nullptr)
          {
            //si en la barca caben más individuos
            if(elLugar->cuantosIndividuos() < 2)
            {
              if(elLugar->estaElIndividuo(tipoIndividuo, identificacion))
              {
                vecinoLugar->conocerIndividuo(elLugar->cualIndividuo(tipoIndividuo,identificacion));
                elLugar->cederIndividuo(tipoIndividuo,identificacion);
                break;
              }
              else
              {
                elLugar->conocerIndividuo(vecinoLugar->cualIndividuo(tipoIndividuo,identificacion));
                vecinoLugar->cederIndividuo(tipoIndividuo,identificacion);
                break;
              }
            }
            else
            {
              //si quiero sacar al individuo de la barca
              if(elLugar->estaElIndividuo(tipoIndividuo,identificacion))
              {
                vecinoLugar->conocerIndividuo(elLugar->cualIndividuo(tipoIndividuo,identificacion));
                elLugar->cederIndividuo(tipoIndividuo,identificacion);
                break;
              }
              else
              { 
                cout << "------------------------------------------------------" << "\n";
                
                cout << "No se pueden tener más de 2 individuos en la barca, Error!" << endl;
                break;
              }
            }
          }
          else
          {
            cout << "------------------------------------------------------" << "\n";
            
            cout << elIndividuo->nombreDelIndividuo() << " se cayó al agua, perdiste!!" << endl;
            
            vecinoLugar->cederIndividuo(tipoIndividuo,identificacion);
            ahogado = true;

            break;
          }
        }
      }
    }
  }
}

void Jugador::ponerGrafico(string mayorString, Lugar *izquierda, Lugar *derecha, Lugar *barca)
{
  int contador = 1;
  
  if(barca->cualVecino()->lugarActual() == "Orilla Izquierda")
  {
    cout << "|" << ponerEspacios("IZQUIERDA", mayorString) << "|" << ponerEspacios("BARCA", mayorString) << "|" << ponerEspacios("", mayorString) << "|" << ponerEspacios("DERECHA", mayorString) << "|" << "\n";

    while(contador-1 != individuos.size())
    {
      cout << "|" << ponerEspacios(izquierda, contador) << "|" << ponerEspacios(barca, contador) << "|" << ponerEspacios("", mayorString) << "|" << ponerEspacios(derecha, contador) << "|" << "\n";

      contador++;
    }

  }
  if(barca->cualVecino()->lugarActual() == "Orilla Derecha")
  {
    cout << "|" << ponerEspacios("IZQUIERDA", mayorString) << "|" << ponerEspacios("", mayorString) << "|" << ponerEspacios("BARCA", mayorString) << "|" << ponerEspacios("DERECHA", mayorString) << "|" << "\n";

    while(contador-1 != individuos.size())
    {
      cout << "|" << ponerEspacios(izquierda, contador) << "|" << ponerEspacios("", mayorString) << "|" << ponerEspacios(barca, contador) << "|" << ponerEspacios(derecha, contador) << "|" << "\n";

      contador++;
    }

  }
}
