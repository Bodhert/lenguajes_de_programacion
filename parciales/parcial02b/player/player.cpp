#include "player.h"

Player::Player(unsigned short nLifes,
               unsigned short nBullets,
               unsigned short armorLevel,
               unsigned short shotFactor) :
  nLifes(nLifes),
  nBullets(nBullets),
  armorLevel(armorLevel),
  shotFactor(shotFactor)
{}

void Player::setLifes(unsigned short nLifes){
  if(isAlive()) this->nLifes += nLifes;  
}

void Player::setArmorLevel(unsigned short level){
  if(isAlive()) this->armorLevel += level;
}

void Player::chargeCartridge(unsigned short nBullets){
  if(isAlive()) this->nBullets += nBullets;
}

void Player::receiveShot(){
  if(isAlive()){
    if(armorLevel <= shotFactor){
      armorLevel = 0;
      nLifes--;
    }else{
      armorLevel -= shotFactor;
    }
  }
}

void Player::fireMachineGun(){
  if(isAlive()) nBullets -= 1;
}

bool Player::isAlive() const {
  return (nLifes > 0);
}

unsigned short Player::getLifes() const{
  return  nLifes;
}

unsigned short Player:: getArmorLevel() const{
  return armorLevel;
}

unsigned short Player:: getNbrBullets() const{
  return nBullets;
}

