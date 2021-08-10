#ifndef VANGUARD_H
#define VANGUARD_H

#include "Hero.h"

class Vanguard : public Hero
{
public:
   Vanguard(string name = "Vanguard", string type = "Hero", int maxHealth = 150, int currentHealth = 150, int maxSp = 30, 
            int currentSp = 30, int attack = 20, int defense = 30, int speed = 30, int evasion = 0, int criticalChance = 10, int level = 1, int experience = 0) :
            Hero(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience) {}
   ~Vanguard(){}
   void printHeroDescription() const; 
   void printFirstAbilityDescription() const;
   void printSecondAbilityDescription() const;
   void ragingSpirit();
   void roaringTaunt(vector<Monster*>&);
   static int vanguardCounter;
};
#endif