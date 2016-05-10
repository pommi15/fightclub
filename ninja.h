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

/**
 * 1/6 not getting hit
 */
class Ninja : public Fighter{
public:
  Ninja(const std::string name);
  int defense(int hitpoints);
};

