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
#include "lemming.h"

Lemming::Lemming(const std::string name) : Fighter(name){
  this->type = "Lemming";

}

int Lemming::defense(int hitpoints){
  if((std::rand() % 50 + 1) == 50){
    /** set lifepoints to 0 */
    this->life_points = 0;
  } else {
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
