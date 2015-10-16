#include <iostream>
#include "Difusores.h"

Difusor::Difusor() : anguloDifusion(0.0f){}

Difusor::Difusor(float anguloDifusion):anguloDifusion(anguloDifusion){}

float  Difusor::obtAnguloDifusion(){
  return anguloDifusion;
}

bool Difusor::potenciaDifusion(float potencia) {}

void Difusor::estAnguloDifusion(float anguloDifusion){
  this->anguloDifusion = anguloDifusion; 
}  

Difusor::~Difusor(){}

DifusorCentral::DifusorCentral():difusorCentral(0.0f),Difusor(){}
DifusorCentral::DifusorCentral(float difusorCentral,float anguloDifusion): difusorCentral(difusorCentral), Difusor(anguloDifusion) {}

bool  DifusorCentral::potenciaDifusion(float potencia) {
  if(obtAnguloDifusion() + difusorCentral == potencia ){
    return true; 
  }
    return false;
}

void DifusorCentral::establecerDifusorCentral(float difusorCentral){
  this->difusorCentral = difusorCentral; 
}

DifusorCentral::~DifusorCentral(){}

DifusorBivalente::DifusorBivalente():anguloPost(0.0f),Difusor(){}
  
DifusorBivalente::DifusorBivalente(float anguloPost, float anguloDifusion):anguloPost(anguloPost),Difusor(anguloDifusion){}

void DifusorBivalente::estAnguloPost(float anguloPost){
  this->anguloPost = anguloPost;
}

float DifusorBivalente::obtAnguloPost(){
  return anguloPost;
}

DifusorBivalente::~DifusorBivalente(){}

DifusorBivalenteCentral::DifusorBivalenteCentral():difusorBic(0.0f),DifusorBivalente(){}

DifusorBivalenteCentral::DifusorBivalenteCentral(float difusorBic, float anguloPost, float anguloDifusion):difusorBic(difusorBic), DifusorBivalente(anguloPost, anguloDifusion){}



void DifusorBivalenteCentral::establecerDifusorBic(float difusorBic){
  this->difusorBic = difusorBic; 
}

bool DifusorBivalenteCentral::potenciaDifusion(float potencia){
  if((obtAnguloPost() + obtAnguloDifusion()) *2 ==  potencia)
    return true;

    return false;
} 

DifusorBivalenteCentral::~DifusorBivalenteCentral(){}

