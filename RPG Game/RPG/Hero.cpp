#include "Hero.h"
#include <iostream>

using namespace std;

Hero::Hero(const Hero& hero) : Entity(hero)
{
   maxHealth = hero.maxHealth;
   maxSp = hero.maxSp;
   level = hero.level;
   experience = hero.experience;
}

Hero& Hero::operator=(const Hero& hero)
{
   if(this != &hero)
   {
      Entity::operator=(hero);
      maxHealth = hero.maxHealth;
      maxSp = hero.maxSp;
      level = hero.level;
      experience = hero.experience;
   }
   return *this;
}

void Hero::levelUp()
{
   int experienceRequired = 30 + 5 * this->level;
   if(this->experience > experienceRequired)
   {
      this->level += 1;
      this->experience -= experienceRequired;
      cout << "Your " << this->name << " has leveled up to level " << this->level << endl;
      this->increaseStats();
      this->levelUp();
   }
  
}

void Hero::printStats()
{
   cout << "Health: " << this->maxHealth << endl;
   cout << "SP: " << this->maxSp << endl;
   cout << "Attack: " << this->attack << endl;
   cout << "Defense: " << this->defense << endl;
   cout << "Speed: " << this->speed << endl;
   cout << "Evasion: " << this->evasion << endl;
   cout << "Critical Chance: " << this->criticalChance << endl;
}

void Hero::printCurrentStats()
{
   cout << "Your " << this->name << " has " << this->currentHealth << " / " << this->maxHealth << " Health and " << this->currentSp << " / " << this->maxSp << " Special Points" << endl;
}

void Hero::attackMessage(Monster& monster, int damage)
{
   if(monster.dead() == true)
   {
      cout << "Your " << this->name << " hit the enemy " << monster.name << " for " << damage << " damage and " << monster.name << " has been defeated"<< endl;
   }
   else
   {      
      cout << "Your " << this->name << " hit the enemy " << monster.name << " for " << damage << " damage and " << monster.name << " has " << monster.currentHealth << " health left" << endl;
   }  
}

void Hero::increaseStats()
{
   int boost;
   boost = statBoost();
   cout << "Health: " << this->maxHealth << " + " << boost << endl;
   this->maxHealth += boost;
   boost = statBoost();
   if(this->name == "Berserker")
   {
      boost = 0;
   }
   else
   {
   boost = statBoost();
   }
   cout << "SP: " << this->maxSp << " + " << boost << endl;
   this->maxSp += boost;
   boost = statBoost();
   cout << "Attack: " << this->attack << " + " << boost << endl;
   this->attack += boost;
   boost = statBoost();
   cout << "Defense: " << this->defense << " + " << boost << endl;
   this->defense += boost;
   boost = statBoost();
   cout << "Speed: " << this->speed << " + " << boost << endl;
   this->speed += boost;
   boost = statBoost();
   cout << "Evasion: " << this->evasion << " + " << boost << endl;
   this->evasion += boost;
   boost = statBoost();
   cout << "Critical Chance: " << this->criticalChance << " + " << boost << endl;
   this->criticalChance += boost;
}

int Hero::statBoost()
{
   int boost = rand() % 3 + 1;
   return boost;
}

void Hero::heal()
{
   this->currentHealth = this->maxHealth;
   this->currentSp = this->maxSp;
}