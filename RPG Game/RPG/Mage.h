#ifndef MAGE_H
#define MAGE_H

#include "Hero.h"
#include <iostream>
#include <time.h>
#include <vector>

class Mage : public Hero
{
public:
   Mage(string name = "Mage", string type = "Hero", int maxHealth = 80, int currentHealth = 80, int maxSp = 60, int currentSp = 60, 
        int attack = 20, int defense = 20, int speed = 50, int evasion = 10, int criticalChance = 10, int level = 1, int experience = 0) :
        Hero(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience) {}
   ~Mage(){}
   void printHeroDescription() const; 
   void printFirstAbilityDescription() const;
   void printSecondAbilityDescription() const;
   void fireball(Monster&);
   void thunderstorm(vector<Monster*>&);
   static int mageCounter;
};
#endif