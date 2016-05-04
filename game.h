#pragma once

#include <map>
#include <string>
#include <memory>
#include "fighter.h"

class Game {
 public:
  Game();
  void start();

 private:
  std::map<std::string, std::shared_ptr<Fighter>> fighters;
  bool main_menu();
  int get_input() const;
  void print_rules() const;
  void print_fighters() const;
  void fight_round(std::string attacker, std::string defender);
  void create_fighter();
  void single_fight();
  void last_man();
};
