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
#pragma once

#include <string>

#include "fighter.h"

class Warrior : public Fighter
{
public:
  /** constructor */
  Warrior(const std::string name);
  /**
   * Attack an opponent, 1/6 chance for double hit
   * @return hit points
   */
  int attack() const;

};
