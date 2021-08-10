#ifndef WARRIOR_H
#define WARRIOR_H

#include "Hero.h"
#include <iostream>

using namespace std;

class Warrior : public Hero
{
public:
   Warrior(string name = "Warrior", string type = "Hero", int maxHealth = 100, int currentHealth = 100, int maxSp = 30, int currentSp = 30, int attack = 40,
           int defense = 30, int speed = 60, int evasion = 20, int criticalChance = 20, int level = 1, int experience = 0) :
           Hero(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience) {}
   ~Warrior(){}
   void printHeroDescription() const; 
   void printFirstAbilityDescription() const;
   void printSecondAbilityDescription() const;
   void empoweredSwing(Monster&);
   void bladeFlurry(Monster&);
   static int warriorCounter;
};
#endif