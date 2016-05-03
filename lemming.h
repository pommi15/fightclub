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

