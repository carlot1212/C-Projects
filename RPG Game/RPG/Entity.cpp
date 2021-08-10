#include "Entity.h"


Entity::Entity(const Entity& entity)
{
   name = entity.name;
   type = entity.type;
   currentHealth = entity.currentHealth;
   currentSp = entity.currentSp;
   attack = entity.attack;
   defense = entity.defense;
   speed = entity.speed;
   evasion = entity.evasion;
   criticalChance = entity.criticalChance;
}

Entity& Entity::operator=(const Entity& entity)
{
   if(this != &entity)
   {
      name = entity.name;
      type = entity.type;
      currentHealth = entity.currentHealth;
      currentSp = entity.currentSp;
      attack = entity.attack;
      defense = entity.defense;
      evasion = entity.evasion;
      criticalChance = entity.criticalChance;
   }
   return *this;
}

bool Entity::criticalHit()
{
   srand(time(NULL));
   int choice = rand() % 100 + 1;
   if(choice < this->criticalChance)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Entity::evade()
{
   srand(time(NULL));
   int choice = rand() % 100 + 1;
   if(choice < this->evasion)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Entity::dead()
{
   if(this->currentHealth <= 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Entity::speedSort(Entity* one, Entity* two)
{
   return one->speed > two->speed;
}

void Entity::attackMove(Entity& target)
{
   int damage;
   if(target.evade() == true)
   {
      if(this->type == "Monster")
      {
         cout << "Your " << target.name << " dodged the enemy " << this->name << "'s attack "<< endl;
      }
      else
      {
         cout << "The enemy " << target.name << " dodged your " << this->name << "'s attack "<< endl;
      }
   }
   else
   {
      if(this->criticalHit() == true)
      {
         damage = 2 * this->attack;
         cout << "Critical Strike!" << endl;
      }
      else
      {
         damage = this->attack;
      }
      damage = damage - target.defense/100;
      target.currentHealth -= damage;
      if(target.dead() == true)
      {
         if(this->type == "Hero")
         {
            cout << "Your " << this->name << " hit the enemy " << target.name << " for " << damage << " damage and " << target.name << " has been defeated"<< endl;
         }
         else
         {
            cout << "The enemy " << this->name << " hit your " << target.name << " for " << damage << " damage and " << target.name << " has been defeated" << endl;
         }
      }
      else
      {
         if(this->type == "Hero")
         {
            cout << "Your " << this->name << " hit the enemy " << target.name << " for " << damage << " damage and " << target.name << " has " << target.currentHealth << " health left" << endl;
         }
         else
         {
            cout << "The enemy " << this->name << " hit your " << target.name << " for " << damage << " damage and " << target.name << " has " << target.currentHealth << " health left" << endl;
         }
      }
   }
} 

int Entity::damageReduction(Entity& target, int damage)
{
   double damageReduction;
   int reducedDamage;
   damageReduction = damage * target.defense / 100;
   reducedDamage = damage - damageReduction;
   return reducedDamage;
}