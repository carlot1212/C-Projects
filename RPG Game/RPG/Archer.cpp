#include "Archer.h"

void Archer::printHeroDescription() const
{
   cout << "The archer is a quick all around ranged attacker that" << endl;
   cout << "excels in both attacking groups of enemies and single targets" << endl;
}

void Archer::printFirstAbilityDescription() const
{
   cout << "Ability 1: Enchanted Arrow (3 SP)" << endl;
   cout << "Deal 150% of the archer's attack to one enemy (ignores armor)" << endl;
}

void Archer::printSecondAbilityDescription() const
{
   cout << "Ability 2: Hail of Arrows (5 SP)" << endl;
   cout << "Deal 50% of the archer's attack to all enemies" << endl;
}

void Archer::enchantedArrow(Monster& monster)
{
   int damage = this->attack * 1.5;
   monster.currentHealth -= damage;
   this->currentSp -= 3;
   attackMessage(monster, damage);
}

void Archer::hailOfArrows(vector<Monster*>& monsters)
{
   int damage;
   for(int i = 0; i < monsters.size(); i++)
   {
      Monster* monster = monsters.at(i);
      damage = this->attack * 0.5;
      damage = damageReduction(*monster, damage);
      monster->currentHealth -= damage;
      if(monsters.at(i)->dead() == false)
      {
         attackMessage(*monster, damage);
      }
   }
   this->currentSp -= 5;
}