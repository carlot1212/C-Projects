#ifndef HERO_H
#define HERO_H

#include "Entity.h"
#include "Monster.h"
#include <iostream>
#include <vector>

using namespace std;

const int numberOfHeros = 7;
const char heroList [numberOfHeros][11] = {"Archer", "Berserker", "Cleric", "Gunslinger", "Mage", "Vanguard", "Warrior"};

class Hero : public Entity
{
public:
   Hero(string name, string type, int maxHealth, int currentHealth, int maxSp, int currentSp, 
        int attack, int defense, int speed, int evasion, int criticalChance, int level, int experience) :
        Entity(name, type, currentHealth, currentSp, attack, defense, speed, evasion, criticalChance, experience), 
        maxHealth(maxHealth), maxSp(maxSp), level(level){}
   Hero(const Hero&);
   Hero& operator=(const Hero&);
   virtual ~Hero(){}
   void levelUp();
   void printStats();
   void printCurrentStats();
   void attackMessage(Monster&, int);
   void increaseStats();
   void heal();
   int statBoost();
   virtual void printHeroDescription() const = 0;
   virtual void printFirstAbilityDescription() const = 0;
   virtual void printSecondAbilityDescription() const = 0;
   int maxHealth;
   int maxSp;
   int level;
};
#endif