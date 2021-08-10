#include "Cleric.h"

void Cleric::printHeroDescription() const
{
   cout << "The cleric is a ranged healer that can" << endl;
   cout << "perform single target and group healing" << endl;
}

void Cleric::printFirstAbilityDescription() const
{
   cout << "Ability 1: Burst Heal (10 SP)" << endl;
   cout << "Heal 20 + 5 per cleric level +" << endl;
   cout << "20% of the target's missing health" << endl;
}

void Cleric::printSecondAbilityDescription() const
{
   cout << "Ability 2: Healing Rain (5 SP)" << endl;
   cout << "Heal all allies for 10 + 2 per cleric level" << endl;
}

void Cleric::burstHeal(Hero& hero) 
{ 
   int heal = 5 * this->level + 20;
   int missingHealth = (hero.maxHealth - hero.currentHealth);
   heal += missingHealth * 0.2;
   if(hero.currentHealth + heal > hero.maxHealth)
   {
      hero.currentHealth = hero.maxHealth;
   }
   else
   {
      hero.currentHealth += heal;
   }
   this->currentSp -=10;
   if(hero.name == "Cleric")
   {
      cout << "Your " << this->name << " healed itself for " << heal << " health and now has " << hero.currentHealth << " health" << endl;
   }
   else
   {
      cout << "Your " << this->name << " healed your " << hero.name << " for " << heal << " health and your " << hero.name << " now has " << hero.currentHealth << " health" << endl;
   }
}

void Cleric::healingRain(vector<Hero*>& party)
{
   int heal = 2 * this->level + 10;
   for(int i = 0; i < party.size(); i++)
   {
      Hero* hero = party.at(i);
      if(hero->dead() == false)
      {
         if(hero->currentHealth + heal > hero->maxHealth)
         {
            hero->currentHealth = hero->maxHealth;
         }
         else
         {
            hero->currentHealth += heal;
         }
         cout << "Your " << this->name << " healed your " << hero->name << " for " << heal << " health and your " << hero->name << " now has " << hero->currentHealth << " health" << endl;
      }   
}
   this->currentSp -= 5;
}