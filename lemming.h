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
 * 1/50 self kill
 */
class Lemming : public Fighter{
public:
  Lemming(const std::string name);
  int defense(int hitpoints);
};

