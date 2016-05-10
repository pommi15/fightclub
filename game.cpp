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
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "warrior.h"
#include "ninja.h"
#include "doctor.h"
#include "lemming.h"

Game::Game() {}

void Game::start() {
  std::srand(std::time(nullptr));
  std::cout << std::endl;
  std::cout << "--------------------------" << std::endl;
  std::cout << "Welcome to the Fight Club!" << std::endl;
  std::cout << "--------------------------" << std::endl;
  std::cout << std::endl;
  while (this->main_menu()) {
  };
}

bool Game::main_menu() {
  int selection = 0;
  std::cout << "---  Menu" << std::endl << std::endl;
  do {
    std::cout << "[1]  Create Fighter" << std::endl;
    std::cout << "[2]  Murder Fighter" << std::endl;
    std::cout << "[3]  1v1 Fight" << std::endl;
    std::cout << "[4]  Last man standing" << std::endl;
    std::cout << "[5]  List fighters" << std::endl;
    std::cout << "[6]  Generate 10 fighters" << std::endl;
    std::cout << "[7]  The Rules" << std::endl;
    std::cout << "[8]  Quit" << std::endl << std::endl;
    std::cout << "-->  ";
    selection = this->get_input();
  } while (selection < 1 || selection > 8);
  std::cout << std::endl;
  switch (selection) {
    case 1:
      this->create_fighter();
      break;
    case 2:
      this->delete_fighter();
      break;
    case 3:
      this->single_fight();
      break;
    case 4:
      this->last_man();
      break;
    case 5:
      this->print_fighters();
      break;
    case 6:
      this->generate_fighters();
      break;
    case 7:
      this->print_rules();
      break;
    case 8:
    default:
      return false;
  }
  return true;
}

int Game::get_input() const {
  std::string selection = "";
  int converted = 0;
  while (!selection.size()) {
    std::cin >> selection;
    try {
      converted = std::stoi(selection);
    } catch (std::invalid_argument) {
      std::cout << "!--  Enter a number." << std::endl;
      selection = "";
    } catch (std::out_of_range) {
      std::cout << "!--  Too big!" << std::endl;
      selection = "";
    }
  }
  return converted;
}

void Game::print_rules() const {
  std::cout << "---  The Rules" << std::endl << std::endl;
  std::cout << "[1]  You do not talk about FIGHT CLUB." << std::endl;
  std::cout << "[2]  You DO NOT talk about FIGHT CLUB." << std::endl;
  std::cout << "[3]  If someone says \"stop\" or goes limp, taps out the fight "
               "is over."
            << std::endl;
  std::cout << "[4]  Only two guys to a fight." << std::endl;
  std::cout << "[5]  One fight at a time." << std::endl;
  std::cout << "[6]  No shirts, no shoes." << std::endl;
  std::cout << "[7]  Fights will go on as long as they have to." << std::endl;
  std::cout
      << "[8]  If this is your first night at FIGHT CLUB, you HAVE to fight."
      << std::endl;
  std::cout << "---" << std::endl;
}

void Game::print_fighters() const {
  std::cout << "---  " << this->fighters.size() << " Fighters" << std::endl;
  for (auto& fighter : this->fighters) {
    std::cout << "   " << fighter.first << std::endl;
    std::cout << "    [" << fighter.second->get_type() << "]" << std::endl;
    std::cout << "    [life:    " << fighter.second->get_life() << "]"
              << std::endl;
    std::cout << "    [offense: " << fighter.second->get_offense() << "]"
              << std::endl;
    std::cout << "    [defense: " << fighter.second->get_defense() << "]"
              << std::endl;
  }
  std::cout << "---" << std::endl;
}

void Game::single_fight() {
  std::string attacker = "";
  std::string defender = "";

  std::cout << "---  1v1 Fight" << std::endl << std::endl;
  if (this->fighters.size() < 2) {
    std::cout << "!--  Please add at least 2 fighters." << std::endl
              << std::endl;
    return;
  }
  this->print_fighters();
  std::cout << "---  Nickname of the attacking fighter:" << std::endl;
  std::cout << "-->  ";
  std::cin >> attacker;
  std::cout << std::endl;
  if (this->fighters.find(attacker) == this->fighters.end()) {
    std::cout << "!--  There is no fighter with the nickname " << attacker
              << "." << std::endl
              << std::endl;
    return;
  }
  std::cout << "---  Nickname of the defending fighter:" << std::endl;
  std::cout << "-->  ";
  std::cin >> defender;
  std::cout << std::endl;
  if (this->fighters.find(defender) == this->fighters.end()) {
    std::cout << "!--  There is no fighter with the nickname " << defender
              << "." << std::endl
              << std::endl;
    return;
  }
  if (defender == attacker) {
    std::cout << "!--  One cannot fight against oneself." << std::endl
              << std::endl;
    return;
  }

  this->fight_round(attacker, defender);
}

void Game::create_fighter() {
  std::shared_ptr<Fighter> new_fighter;
  int selection = 0;
  std::string nickname = "";
  std::cout << "---  Create Fighter" << std::endl << std::endl;
  std::cout << "---  Choose the type of the fighter:" << std::endl;
  do {
    std::cout << "[1]  Warrior" << std::endl;
    std::cout << " |   1/6 chance of double hitpoints" << std::endl;
    std::cout << "[2]  Ninja" << std::endl;
    std::cout << " |   1/6 chance of escaping attack" << std::endl;
    std::cout << "[3]  Doctor" << std::endl;
    std::cout << " |   13 regenerations, attacks on him are doubled"
              << std::endl;
    std::cout << "[4]  Lemming" << std::endl;
    std::cout << " |   1/50 chance to die in defense" << std::endl;
    std::cout << "[5]  Abort" << std::endl << std::endl;
    std::cout << "-->  ";
    selection = this->get_input();
  } while (selection < 1 || selection > 5);
  std::cout << std::endl;
  if (selection == 5) {
    return;
  }

  std::cout << "---  Nickname of the fighter:" << std::endl;
  std::cout << "-->  ";
  std::cin >> nickname;
  std::cout << std::endl;
  switch (selection) {
    case 1:
      new_fighter.reset(new Warrior(nickname));
      break;
    case 2:
      new_fighter.reset(new Ninja(nickname));
      break;
    case 3:
      new_fighter.reset(new Doctor(nickname));
      break;
    case 4:
      new_fighter.reset(new Lemming(nickname));
      break;
    case 5:
    default:
      return;
  }
  this->fighters[nickname] = new_fighter;
  std::cout << "---  " << new_fighter->get_name() << " of the type "
            << new_fighter->get_type() << " awaits your orders." << std::endl
            << std::endl;
}

void Game::delete_fighter() {
  std::string nickname = "";
  std::cout << "---  Murder Fighter" << std::endl << std::endl;
  if (!this->fighters.empty()) {
    this->print_fighters();
    std::cout << "---  Nickname of the fighter:" << std::endl;
    std::cout << "-->  ";
    std::cin >> nickname;
    std::cout << std::endl;
    if (this->fighters.find(nickname) == this->fighters.end()) {
      std::cout << "!--  There is no fighter with the nickname " << nickname
                << "." << std::endl
                << std::endl;
      return;
    } else {
      std::cout << "---  You murdered " << nickname << " of the type "
                << this->fighters[nickname]->get_type()
                << ". How can you live with yourself?" << std::endl
                << std::endl;
      this->fighters.erase(nickname);
    }
  } else {
    std::cout << "!--  Please add at least one fighter if you want to murder one."
              << std::endl
              << std::endl;
  }
}

void Game::fight_round(std::string attacker, std::string defender) {
  int counter_points = 0;
  int offense_points = this->fighters[attacker]->attack();
  int defense_points = this->fighters[defender]->defense(offense_points);
  if (defense_points > 0) {
    counter_points = this->fighters[attacker]->defense(defense_points);
  }
  std::cout << "---" << std::endl;
  std::cout << "   " << attacker << " attacks " << defender << " with "
            << offense_points << " hitpoints." << std::endl;
  if (defense_points == -1) {
    std::cout << "   " << defender << " died from the attack." << std::endl;
    this->fighters.erase(defender);
  } else {
    std::cout << "   " << defender << " has "
              << this->fighters[defender]->get_life() << " life left."
              << std::endl;
    if (defense_points == 0) {
      std::cout << "   " << defender << " tried a counterattack but failed."
                << std::endl;
    } else {
      std::cout << "   " << defender << " counterattacks with "
                << defense_points << " hitpoints." << std::endl;
      if (counter_points == -1) {
        std::cout << "   " << attacker << " died from the counterattack."
                  << std::endl;
        this->fighters.erase(attacker);
      } else {
        std::cout << "   " << attacker << " has "
                  << this->fighters[attacker]->get_life() << " life left."
                  << std::endl;
      }
    }
  }
  std::cout << "---" << std::endl;
}

void Game::last_man() {
  auto attacker = this->fighters.begin();
  auto defender = this->fighters.begin();
  if (this->fighters.size() > 1) {
    while (this->fighters.size() > 1) {
      do {
        attacker = this->fighters.begin();
        defender = this->fighters.begin();
        std::advance(attacker, std::rand() % this->fighters.size());
        std::advance(defender, std::rand() % this->fighters.size());
      } while (attacker == defender);
      this->fight_round(attacker->first, defender->first);
      std::cout << std::endl;
    }
    std::cout << this->fighters.begin()->first << " of the type "
              << this->fighters.begin()->second->get_type()
              << " is still standing." << std::endl;
  } else {
    std::cout << "!--  Please add at least 2 fighters." << std::endl
              << std::endl;
  }
}

void Game::generate_fighters() {
  std::cout << "---  Generated 10 fighters" << std::endl << std::endl;
  for (int i = 0; i < 10; ++i) {
    std::shared_ptr<Fighter> new_fighter;
    std::string nickname = this->unique_rand_name();
    int type = std::rand() % 4;
    switch (type) {
      case 0:
        new_fighter.reset(new Warrior(nickname));
        break;
      case 1:
        new_fighter.reset(new Ninja(nickname));
        break;
      case 2:
        new_fighter.reset(new Doctor(nickname));
        break;
      case 3:
        new_fighter.reset(new Lemming(nickname));
        break;
    }
    this->fighters[nickname] = new_fighter;
  }
}

std::string Game::unique_rand_name() const {
  std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int length = 16;
  int count = 0;
  int max_iter = 100;
  std::string result;
  result.resize(length);
  do {
    for (int i = 0; i < length; i++) {
      result[i] = charset[rand() % charset.length()];
    }
  } while (this->fighters.find(result) != this->fighters.end() &&
           count < max_iter);

  return result;
}
