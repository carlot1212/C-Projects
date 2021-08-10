#ifndef CLERIC_H
#define CLERIC_H

#include "Hero.h"
#include <iostream>
#include <vector>

using namespace std;

class Cleric : public Hero
{
public:
   Cleric(string name = "Cleric", string type = "Hero", int maxHealth = 80, int currentHealth = 80, int maxSp = 40, int currentSp = 40,
          int attack = 20, int defense = 30, int speed = 50, int evasion = 20, int criticalChance = 20, int level = 1, int experience = 0) :
          Hero(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience) {}
   ~Cleric(){}
   void printHeroDescription() const; 
   void printFirstAbilityDescription() const;
   void printSecondAbilityDescription() const;
   void burstHeal(Hero&);
   void healingRain(vector<Hero*>&);
   static int clericCounter;
};
#endif