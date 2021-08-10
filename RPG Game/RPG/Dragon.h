#ifndef DRAGON_H
#define DRAGON_H

#include "Boss.h"
#include <iostream>

using namespace std;

class Dragon : public Boss
{
public:
   Dragon(string name = "Dragon", string type = "Monster", int currentHealth = 300, int currentSp = 30, 
           int attack = 25, int defense = 20, int speed = 30, int evasion = 10, int criticalChance = 10, int experience = 50, int tauntedCounter = 0) :
           Boss(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience, tauntedCounter) {}
   ~Dragon(){}
   void dragonsClaw(Hero&);
   void dragonsBreath(vector<Hero*>&);
};
#endif