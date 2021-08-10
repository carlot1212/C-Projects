#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"
#include <iostream>

using namespace std;

class Goblin : public Monster
{
public:
   Goblin(string name = "Goblin", string type = "Monster", int currentHealth = 80, int currentSp = 30, 
          int attack = 20, int defense = 20, int speed = 80, int evasion = 30, int criticalChance = 30, int experience = 10, int tauntedCounter = 0) :
          Monster(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience, tauntedCounter) {}
   ~Goblin(){}
   static int goblinCounter;
};
#endif