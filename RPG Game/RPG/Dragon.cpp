#include "Dragon.h"

void Dragon::dragonsClaw(Hero& hero)
{
   int damage;
   cout << "The dragon strikes using its powreful claws" << endl;
   damage = this->attack * 1.35;
   hero.currentHealth -= damage;
   attackMessage(hero, damage);
}

void Dragon::dragonsBreath(vector<Hero*>& party)
{
   int damage;
   damage = this->attack * 0.4;
   cout << "The dragon engulfs your team with its blazing flames" << endl;
   for(int i = 0; i < party.size(); i++)
   {
      party.at(i)->currentHealth -= damage;
      attackMessage(*party.at(i), damage);
   }
}