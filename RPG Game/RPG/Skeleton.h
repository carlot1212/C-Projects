#ifndef SKELETON_H
#define SKELETON_H

#include "Monster.h"
#include <iostream>

using namespace std;

class Skeleton : public Monster
{
public:
   Skeleton(string name = "Skeleton", string type = "Monster", int currentHealth = 100, int currentSp = 20, 
            int attack = 15, int defense = 10, int speed = 60, int evasion = 20, int criticalChance = 30, int experience = 10, int tauntedCounter = 0) :
            Monster(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience, tauntedCounter) {}
   ~Skeleton(){}
   static int skeletonCounter;
};
#endif
