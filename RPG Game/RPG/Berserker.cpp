#include "Berserker.h"

void Berserker::printHeroDescription() const
{
   cout << "The berserker is a strong melee hero with high" << endl;
   cout << "health and strong single target attacks that" << endl;
   cout << "put the berserker at risk of damaging himself" << endl;
}

void Berserker::printFirstAbilityDescription() const
{
   cout << "Ability 1: Recoiling Strike (5% of current health)" << endl;
   cout << "Deal 130% of the berserker's attack at" << endl;
   cout << "the cost of 5% of its current health" << endl;
}

void Berserker::printSecondAbilityDescription() const
{
   cout << "Ability 2: Spinning Smash (no cost)" << endl;
   cout << "The berseker either deals 150% of its attack (ignores armor)" << endl;
   cout << "or hits itself and loses 10% of its current health" << endl;
}

void Berserker::recoilingStrike(Monster& monster)
{
   int damage;
   int healthLoss;
   damage = this->attack * 1.3;
   damage = damageReduction(monster, damage);
   monster.currentHealth -= damage;
   healthLoss = 0.05 * this->currentHealth;
   this->currentHealth -= healthLoss;
   this->attackMessage(monster, damage);
   cout << "Your " << this->name << " lost " << healthLoss << " of its health and has " << this->currentHealth << " health left" << endl;
}

void Berserker::spinningSmash(Monster& monster)
{
   int chance;
   int damage = this->attack * 1.5;
   int healthLoss = this->currentHealth * 0.1;
   srand(time(NULL));
   chance = rand() % 2;
   if(chance == 0) 
   {
      monster.currentHealth -= damage;
      this->attackMessage(monster, damage);
   }
   else
   {
      this->currentHealth -= healthLoss;
      cout << "Your " << this->name << " hit itself and lost " << healthLoss << " health.  It now has " << this->currentHealth << " health left" << endl;
   }   
}