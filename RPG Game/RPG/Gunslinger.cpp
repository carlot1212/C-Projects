#include "Gunslinger.h"

void Gunslinger::printHeroDescription() const
{
   cout << "The gunslinger is a hard hitting ranged" << endl;
   cout << "attacker that has strong single target damage" << endl;
}

void Gunslinger::printFirstAbilityDescription() const
{
   cout << "Ability 1: Double Shot (3 SP)" << endl;
   cout << "Deal 60% of the Gunslinger's attack with" << endl;
   cout << "increased critical chance on both shots" << endl;
}

void Gunslinger::printSecondAbilityDescription() const
{
   cout << "Ability 2: Heavy Shot (5 SP)" << endl;
   cout << "The gunslinger charges his weapon for one turn" << endl;
   cout << "then deals 250% of its attack to a target (ignores armor)" << endl;
}

void Gunslinger::doubleShot(Monster& monster)
{
   int damage = this->attack * 0.6;
   int totalDamage = 0;
   int criticalHitCounter = 0;
   this->criticalChance += 30;
   for(int i = 0; i < 2; i++)
   {
      if(this->criticalHit() == true)
      {
         totalDamage += damage * 2;
         criticalHitCounter++;
      }
      else
      {
         totalDamage += damage;
      }
   }
   monster.currentHealth -= totalDamage;
   this->currentSp -= 3;
   this->criticalChance -= 30;
   cout << "Your " << this->name << " critically hit " << criticalHitCounter << " times and hit the enemy " << monster.name << " for " << totalDamage << " damage and "  << monster.name << " has " << monster.currentHealth << " health left" << endl;
}

void Gunslinger::heavyShot(Monster& monster)
{
   int damage = this->attack * 2.5;
   monster.currentHealth -= damage;
   this->currentSp -= 5;
   this->reloading = true;
   this->attackMessage(monster, damage);
}

void Gunslinger::reload()
{
   this->reloading = false;
}