#include "ninja.h"

Ninja::Ninja(const std::string name) : Fighter(name){
  this->type = "Ninja";

}

int Ninja::defense(int hitpoints){
  if((std::rand() % 6 + 1) != 6){
    /** reduce lifepoints by hitpoints */
    this->life_points -= hitpoints;
  }
  /** check if alife */
  if (this->life_points <= 0){
    /** death occoured */
    return -1;
  }
  /** return counterattack */
  return std::rand() % this->defense_points;
}
