#include "Lampara.h"
using namespace std;

Lampara::Lampara():prendida(false), nivel(0.0f){}

Lampara::Lampara(bool prendida, float nivel):prendida(this -> prendida), nivel(this -> nivel){}
float Lampara::obtNivelEnergia(){
  return this -> nivel;
}

bool Lampara::estaPrendida(){
  return this -> prendida;
}

void Lampara::Consumir(float nivel){
  nivel = nivel - this ->nivel;
}

void Lampara::Cargar(float nivel){
  nivel = nivel + this -> nivel;
}

void Lampara::prender(){
  this -> prendida = true ;
}

void  Lampara::apagar(){
  this -> prendida = false;
}
