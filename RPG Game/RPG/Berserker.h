#ifndef BERSERKER_H
#define BERSERKER_H

#include "Hero.h"
#include <iostream>
#include <time.h>

using namespace std;

class Berserker : public Hero
{
public:
   Berserker(string name = "Berserker", string type = "Hero", int maxHealth = 120, int currentHealth = 120, int maxSp = 0, int currentSp = 0,
             int attack = 40, int defense = 30, int speed = 40, int evasion = 10, int criticalChance = 10, int level = 1, int experience = 0) :
             Hero(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience) {}
   ~Berserker(){}
   void printHeroDescription() const; 
   void printFirstAbilityDescription() const;
   void printSecondAbilityDescription() const;
   void recoilingStrike(Monster&);
   void spinningSmash(Monster&);
   static int berserkerCounter;
};
#endif