#include "Warrior.h"

void Warrior::printHeroDescription() const
{
   cout << "The warrior is an all around melee hero" << endl;
   cout << "It can deal single target damage and survive many attacks" << endl;
}

void Warrior::printFirstAbilityDescription() const
{
   cout << "Ability 1: Empowered Swing (3 SP)" << endl;
   cout << "Deal 140% of the warrior's attack to one target" << endl;
}

void Warrior::printSecondAbilityDescription() const
{
   cout << "Ability 2: Blade Flurry (4 SP)" << endl;
   cout << "Deal 40% of the warrior's attack to one target 3 times" << endl;
}

void Warrior::empoweredSwing(Monster& monster)
{
   int damage = this->attack * 1.4;
   monster.currentHealth -= damage;
   this->currentSp -= 3;
   attackMessage(monster, damage);
}

void Warrior::bladeFlurry(Monster& monster)
{
   int damage = this->attack * 0.4;
   int totalDamage = 0;
   int criticalHitCounter = 0;
   for(int i = 0; i < 3; i++)
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
   this->currentSp -= 4;
   cout << "Your " << this->name << " critically hit " << criticalHitCounter << " times and hit the enemy " << monster.name << " for " << totalDamage << " damage and "  << monster.name << " has " << monster.currentHealth << " health left" << endl;
}