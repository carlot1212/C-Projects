#ifndef GUNSLINGER_H
#define GUNSLINGER_H

#include "Hero.h"
#include <iostream>


class Gunslinger : public Hero
{
public:
   Gunslinger(string name = "Gunslinger", string type = "Hero", int maxHealth = 90, int currentHealth = 90, int maxSp = 30, int currentSp = 30, 
              int attack = 40, int defense = 20, int speed = 50, int evasion = 10, int criticalChance = 20, int level = 1, int experience = 0, bool reloading = false) :
              Hero(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience) {}
   ~Gunslinger(){}
   void printHeroDescription() const; 
   void printFirstAbilityDescription() const;
   void printSecondAbilityDescription() const;
   void doubleShot(Monster&);
   void heavyShot(Monster&);
   void reload();
   bool reloading;
   static int gunslingerCounter;
};
#endif