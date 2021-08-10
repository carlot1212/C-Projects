#include "Vanguard.h"

void Vanguard::printHeroDescription() const
{
   cout << "The vanguard is a defensive melee hero that uses" << endl;
   cout << "high health and strong defense to protect its allies" << endl;
}

void Vanguard::printFirstAbilityDescription() const
{
   cout << "Ability 1: Raging Spirit (3 SP)" << endl;
   cout << "Increase the vanguard's defense by 30 + 5 per level for 3 turns" << endl;
}

void Vanguard::printSecondAbilityDescription() const
{
   cout << "Ability 2: Roaring Taunt (3 SP)" << endl;
   cout << "The vanguard draws all enemy attacks towards him for 2 turns" << endl;
}

void Vanguard::ragingSpirit()
{
   int defense = 5 * this->level + 30;
   this->defense += defense;
   this->currentSp -= 3;
   cout << "Your " << this->name << " increased its defense by " << defense;
}

void Vanguard::roaringTaunt(vector <Monster*>& monsters)
{
   for(int i = 0; i < monsters.size(); i++)
   {
      Monster* monster = monsters.at(i);
      monster->tauntedCounter = 2;
   }
}