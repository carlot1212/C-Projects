#include "Mage.h"

void Mage::printHeroDescription() const
{
   cout << "The mage is a ranged character that uses spells" << endl;
   cout << "that can target single targets or groups of enemies" << endl;
}

void Mage::printFirstAbilityDescription() const
{
   cout << "Ability 1: Fireball (5 SP)" << endl;
   cout << "Deal 60 + 5 per mage level to a" << endl;
   cout << "single target(ignores armor)" << endl;
}

void Mage::printSecondAbilityDescription() const
{
   cout << "Ability 2: Thunderstorm (7 SP)" << endl;
   cout << "Deal 30 + 5 per mage level to" << endl;
   cout << "3 random enemies(ignores armor)" << endl;
}

void Mage::fireball(Monster& monster)
{
   int damage = 5 * this->level + 60;
   monster.currentHealth -= damage;
   this->currentSp -= 5;
   this->attackMessage(monster, damage);
}

void Mage::thunderstorm(vector<Monster*>& monsters)
{
   int damage = 5 * this->level + 30;
   for(int i = 0; i < 3; i++)
   {
      int choice;
      srand(time(NULL));
      choice = rand() % 4;
      Monster* monster = monsters.at(choice);
      monster->currentHealth -= damage;
      this->attackMessage(*monster, damage);
   }
   this->currentSp -= 7;
}