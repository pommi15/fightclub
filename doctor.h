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

