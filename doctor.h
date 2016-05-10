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
 * regenerates 13 times
 * attacks on him are doubled
 */
class Doctor : public Fighter{
public:
  Doctor(const std::string name);
  int defense(int hitpoints);
private:
  int cycle;
};

