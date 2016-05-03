
#include "warrior.h"

Warrior::Warrior(const std::string name) : Fighter(name){
  this->type = "Warrior";
}

int Warrior::attack() const{
  int hitpoints = std::rand() % this->offense_points;
  return ((std::rand() % 6 + 1) == 6 ? hitpoints * 2 : hitpoints);
}
