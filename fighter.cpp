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
#include <cstdlib>

#include <iostream>
#include "fighter.h"

#define MAX_POINTS 50
#define MIN_POINTS 25

Fighter::Fighter(const std::string name)
    : name(name), type("base"), life_points(100) {
  this->offense_points =
      MIN_POINTS + (std::rand() % (MAX_POINTS - MIN_POINTS + 1));
  this->defense_points =
      MIN_POINTS + (std::rand() % (MAX_POINTS - MIN_POINTS + 1));
}

int Fighter::attack() const {
  return std::rand() % this->offense_points;
}

int Fighter::defense(int hitpoints) {
  /** reduce lifepoints by hitpoints */
  this->life_points -= hitpoints;
  /** check if alife */
  if (this->life_points <= 0) {
    /** death occoured */
    return -1;
  } else {
    /** return counterattack */
    return std::rand() % this->defense_points;
  }
}

std::string Fighter::get_type() const {
  return this->type;
}

std::string Fighter::get_name() const {
  return this->name;
}

int Fighter::get_life() const {
  return this->life_points;
}
int Fighter::get_offense() const {
  return this->offense_points;
}
int Fighter::get_defense() const {
  return this->defense_points;
}
