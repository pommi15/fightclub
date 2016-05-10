/*************************
 *         xoxo          *
 *      fightclub        *
 *         Game          *
 *          by           *
 *    Thomas RAUHOFER    *
 *        if15b029       *
 *          and          *
 *     Tobias WATZEK     *
 *        if15b038       *
 *************************/
#include "warrior.h"

Warrior::Warrior(const std::string name) : Fighter(name){
  this->type = "Warrior";
}

int Warrior::attack() const{
  int hitpoints = std::rand() % this->offense_points;
  return ((std::rand() % 6 + 1) == 6 ? hitpoints * 2 : hitpoints);
}
