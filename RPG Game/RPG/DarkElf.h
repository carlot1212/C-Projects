#ifndef DARKELF_H
#define DARKELF_H

#include "Monster.h"
#include <iostream>

using namespace std;

class DarkElf : public Monster
{
public:
   DarkElf(string name = "Dark Elf", string type = "Monster", int currentHealth = 60, int currentSp = 30, 
           int attack = 15, int defense = 10, int speed = 85, int evasion = 30, int criticalChance = 80, int experience = 20, int tauntedCounter = 0) :
           Monster(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience, tauntedCounter) {}
   ~DarkElf(){}
   static int darkElfCounter;
};
#endif