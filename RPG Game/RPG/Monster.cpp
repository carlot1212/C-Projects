#include "Monster.h"

Monster::Monster(const Monster& monster) : Entity(monster)
{
   tauntedCounter = monster.tauntedCounter;
}

Monster& Monster::operator=(const Monster& monster)
{
   if(this != &monster)
   {
      Entity::operator=(monster);
      tauntedCounter = monster.tauntedCounter;
   }
   return *this;
}

bool Monster::taunted(Monster& monster)
{
   if(monster.tauntedCounter == 0)
   {
      return false;
   }
   else
   {
      monster.tauntedCounter--;
      return true;
   } 
} 