#ifndef OGRE_H
#define OGRE_H

#include "Monster.h"
#include <iostream>

using namespace std;

class Ogre : public Monster
{
public:
   Ogre(string name = "Ogre", string type = "Monster", int currentHealth = 140, int currentSp = 20, int attack = 20,
        int defense = 10, int speed = 40, int evasion = 10, int criticalChance = 20, int experience = 15, int tauntedCounter = 0) :
        Monster(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience, tauntedCounter) {}
   ~Ogre(){}
   static int ogreCounter;
};
#endif