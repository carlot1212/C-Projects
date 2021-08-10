#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"

class Monster : public Entity
{
public:
   Monster(string name, string type, int currentHealth, int currentSp, int attack, 
           int defense, int speed, int evasion, int criticalChance, int experience, int tauntedCounter) :
           Entity(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience), tauntedCounter(tauntedCounter){}
   ~Monster(){}
   Monster(const Monster&);
   Monster& operator=(const Monster&);
   int tauntedCounter;
   bool taunted(Monster&);
};
#endif