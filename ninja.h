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

