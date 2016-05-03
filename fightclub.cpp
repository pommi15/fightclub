/*************************
 *         0000          *
 *      fightclub        *
 *         Game          *
 *          by           *
 *    Thomas RAUHOFER    *
 *        if15b029       *
 *          and          *
 *     Tobias WATZEK     *
 *        if15b038       *
 *************************/

#include <string>
#include <iostream>
#include <map>
#include <memory>

#include "fighter.h"

int main() {
  auto my_fighter = std::make_shared<Fighter>("test");

  return 0;
}
