#pragma once

#include <string>

class Fighter
{
public:
  /** constructor */
  Fighter(const std::string name);
  /**
   * Attack an opponent
   * @return hit points
   */
  virtual int attack() const;
  /**
   * Receive an attack
   * @return counterattack points or -1 on death
   */
  virtual int defense(const int hitpoints);
  /**
   * type getter
   * @return type of the fighter
   */
  std::string get_type() const;
  /**
   * life getter
   * @return life points
   */
  int get_life() const;
  /**
   * offense getter
   * @return offense points
   */
  int get_offense() const;
  /**
   * defense getter
   * @return defense points
   */
  int get_defense() const;
  /**
   * name getter
   * @return name
   */
  std::string get_name() const;
protected:
  /** name of the fighter */
  std::string name;
  /** type of the fighter */
  std::string type;
  /** fighter life points */
  int life_points;
  /** fighter offense points */
  int offense_points;
  /** fighter defense points */
  int defense_points;
};
