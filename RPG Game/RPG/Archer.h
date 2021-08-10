#ifndef ARCHER_H
#define ARCHER_H

#include "Hero.h"
#include <iostream>
#include <vector>

using namespace std;

class Archer : public Hero
{
public:
   Archer(string name = "Archer", string type = "Hero", int maxHealth = 80, int currentHealth = 80, int maxSp = 30, int currentSp = 30,
          int attack = 30, int defense = 20, int speed = 80, int evasion = 30, int criticalChance = 40, int level = 1, int experience = 0) :
          Hero(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience) {}
   ~Archer(){}
   void printHeroDescription() const;
   void printFirstAbilityDescription() const;
   void printSecondAbilityDescription() const;
   void enchantedArrow(Monster&);
   void hailOfArrows(vector<Monster*>&);
   static int archerCounter;
};
#endif