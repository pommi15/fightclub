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
#include "doctor.h"

Doctor::Doctor(const std::string name) : Fighter(name), cycle(1) {
  this->type = "Doctor";

}

int Doctor::defense(int hitpoints){
  /** reduce lifepoints by hitpoints */
  this->life_points -= hitpoints * 2;
  /** check if alife */
  if (this->life_points <= 0){
    /** death occoured */
    if(this->cycle == 13){
      return -1;
    } else {
      ++this->cycle;
      this->life_points = 100;
    }

  }
  /** return counterattack */
  return std::rand() % this->defense_points;
}
