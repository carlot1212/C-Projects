#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Entity
{
public:
   Entity(string name, string type, int currentHealth, int currentSp,
          int attack, int defense, int speed, int evasion, int criticalChance, int experience) :
          name(name), type(type), currentHealth(currentHealth), currentSp(currentSp), 
          attack(attack), defense(defense), speed(speed), evasion(evasion), criticalChance(criticalChance), experience(experience){}
   Entity(const Entity&);
   Entity& operator=(const Entity&);
   ~Entity(){}
   string name;
   string type;
   int currentHealth;
   int currentSp;
   int attack;
   int defense;
   int speed;
   int evasion;
   int criticalChance;
   int experience;
   void attackMove(Entity&);
   int damageReduction(Entity&, int);
   bool criticalHit();
   bool evade();
   bool dead();
   static bool speedSort(Entity*, Entity*);
};
#endif