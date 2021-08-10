#include "Boss.h"
Boss::Boss(const Boss& boss) : Monster(boss)
{

}

Boss& Boss::operator=(const Boss& boss)
{
   if(this != &boss)
   {
      Monster::operator=(boss);
   }
   return *this;
}

void Boss::attackMessage(Hero& hero, int damage)
{
   if(hero.dead() == true)
   {
      cout << "The enemy " << this->name << " hit your " << hero.name << " for " << damage << " damage and " << hero.name << " has been defeated"<< endl;
   }
   else
   {      
      cout << "The enemy  " << this->name << " hit yout " << hero.name << " for " << damage << " damage and " << hero.name << " has " << hero.currentHealth << " health left" << endl;
   }  
}