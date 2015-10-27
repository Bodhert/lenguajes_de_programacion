#include "bateries.h"
Batery::Batery(){}

Batery::~Batery(){}

B2Batery::B2Batery(float charge[2]):charge(),prop(){
  this->charge[0] = charge[0];
  this->charge[1] = charge[1];
  this->prop[0] = charge[0]/getTotalCharge();
  this->prop[1] = charge[1]/getTotalCharge();
}
B2Batery::~B2Batery(){}

float B2Batery::getTotalCharge(){
  return charge[0] + charge[1];
}

float B2Batery::getCharge(int pos){
  return charge[pos];
}

float B2Batery::setDischarge(float amount){
  if(getTotalCharge() > 0 ){
    charge[0] -= amount * prop[0];
    charge[1] -= amount * prop[1];
  }else{
    charge[0] = 0;
    charge[1] = 0;
  }
    return getTotalCharge();
}

float getTotalBateries(Batery **bateries, int nBateries){
  float acum = 0;
  for(int i = 0 ; i < nBateries ; i++){
    acum += bateries[i] -> getTotalCharge();
  }
  return acum;
}
