#ifndef BOSS_H
#define BOSS_H

#include "Entity.h"
#include "Hero.h"

using namespace std;

class Boss : public Monster
{
public:
   Boss(string name, string type, int currentHealth, int currentSp, 
        int attack, int defense, int speed, int evasion, int criticalChance, int experience, int tauntedCOunter) :
        Monster(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience, tauntedCounter){}
   Boss(const Boss&);
   Boss& operator=(const Boss&);
   virtual ~Boss(){}
   void attackMessage(Hero&, int);
};
#endif