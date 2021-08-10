#ifndef FORESTSPIRIT_H
#define FORESTSPIRIT_H

#include "Monster.h"
#include <iostream>

using namespace std;

class ForestSpirit : public Monster
{
public:
   ForestSpirit(string name = "Forest Spirit", string type = "Monster", int currentHealth = 60, int currentSp = 30,
                int attack = 5, int defense = 5, int speed = 95, int evasion = 5, int criticalChance = 5, int experience = 5, int tauntedCounter = 0) :
                Monster(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience, tauntedCounter) {}
   ~ForestSpirit(){}
   static int forestSpiritCounter;
};
#endif