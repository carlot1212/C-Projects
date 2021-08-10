#include "game.h"
#include "fstream"
#include "iomanip"

int Archer::archerCounter = 0;
int Berserker::berserkerCounter = 0;
int Cleric::clericCounter = 0;
int Gunslinger::gunslingerCounter = 0;
int Mage::mageCounter = 0;
int Vanguard::vanguardCounter = 0;
int Warrior::warriorCounter = 0;
int DarkElf::darkElfCounter = 0;
int ForestSpirit::forestSpiritCounter = 0;
int Goblin::goblinCounter = 0;
int Ogre::ogreCounter = 0;
int Skeleton::skeletonCounter = 0;
vector<Hero*> party;
vector<Monster*> monsters;

void Game::menu(string sentence)
{
   srand(time(NULL));
   party.clear();
   string choiceBuffer;
   int choice;
   cout << sentence << endl;
   menuOptions();
   cin >> choiceBuffer;
   choice = atoi(choiceBuffer.c_str());
   while(choice < 1 || choice > 3)
   {
      cout << "Invalid choice" << endl;
      menuOptions();
      cin >> choiceBuffer;
      choice = atoi(choiceBuffer.c_str());
   }
   if(choice == 1)
   {
      newGame();
   }
   else if(choice == 2)
   {
      if(loadGame() == "Sand Village")
      {
         sandVillage();
      }
   }
   else
   {
      cout << "Thank you for playing" << endl;
   } 
}

void Game::menuOptions()
{
   cout << "Press 1 to start a new game" << endl;
   cout << "Press 2 to load a saved game" << endl;
   cout << "Press 3 to quit" << endl;
}

void Game::newGame()
{
   characterChoice();
}

void Game::characterChoice()
{
   string choice;
   cout << "Choose four heroes to create your party" << endl;
   while(party.size() < 4)
   {
      if(party.size() != 0)
      {
         cout << "Your party currently consists of ";
         for(int i = 0; i < party.size(); i++)
         {
            cout << party.at(i)->name << " ";
         }
         cout << endl;
         cout << "You can select " << 4 - party.size() << " more heroes." << endl;
      }
      cout << "Please select one of the heros to add to your party by typing the hero name" << endl;
      printHeros();
      cin >> choice;
      while(validation(choice) == false)
      {
         cout << "Invalid choice" << endl;
         cout << "Please select one of the heros to add to your party by typing the hero name" << endl;
         printHeros();
         cin >> choice;
         validation(choice);
      }
      heroLoop(choice);
   }
   village();
}

void Game::heroLoop(string choice)
{
   for(int i = 0; i < numberOfHeros; i++)
   {
      if(choice == *(heroList + i))
      {
         int counter;
         string option;
         if(i == 0)
         {
            Archer* archer = new Archer;
            counter = Archer::archerCounter;
            if(heroSelection(archer, i, counter) == true)
            {
               Archer::archerCounter += 1;   
            }
            else
            {
               delete archer;   
            }
         }
         else if(i == 1)
         {
            Berserker* berserker = new Berserker;
            counter = Berserker::berserkerCounter;
            if(heroSelection(berserker, i, counter) == true)
            {
               Berserker::berserkerCounter += 1; 
            }
            else
            {
               delete berserker;   
            }
         }
         else if(i == 2)
         {
            Cleric* cleric = new Cleric;
            counter = Cleric::clericCounter;
            if(heroSelection(cleric, i, counter) == true)
            {
               Cleric::clericCounter += 1;   
            }
            else
            {
               delete cleric;   
            }
         }
         else if(i == 3)
         {
            Gunslinger* gunslinger = new Gunslinger;
            counter = Gunslinger::gunslingerCounter;
            if(heroSelection(gunslinger, i, counter) == true)
            {
               Gunslinger::gunslingerCounter += 1;
            }
            else
            {
               delete gunslinger;   
            }
         }
         else if(i == 4)
         {
            Mage* mage = new Mage;
            counter = Mage::mageCounter;
            if(heroSelection(mage, i, counter) == true)
            {
               Mage::mageCounter += 1;   
            }
            else
            {
               delete mage;   
            }
         }
         else if(i == 5)
         {
            Vanguard* vanguard = new Vanguard;
            counter = Vanguard::vanguardCounter;
            if(heroSelection(vanguard, i, counter) == true)
            {
               Vanguard::vanguardCounter += 1;  
            }
            else
            {
               delete vanguard;   
            }
         }
         else if(i == 6)
         {
            Warrior* warrior = new Warrior;
            counter = Warrior::warriorCounter;
            if(heroSelection(warrior, i, counter) == false)
            {
               Warrior::warriorCounter += 1;
            }
            else
            {
               delete warrior;   
            }
         }
      }
   }
}

void Game::printHeros()
{
   for(int i = 0; i < numberOfHeros - 1; i++)
   {
      cout << *(heroList + i) << ", ";
   }
   cout << "and " << *(heroList + numberOfHeros - 1) << endl;
}

bool Game::validation(string choice)
{
   bool valid = false;
   for(int i = 0; i < numberOfHeros; i++)
   {
      if(choice == *(heroList + i))
      {
         valid = true;
         break;
      }
   }
   return valid;
}

bool Game::heroSelection(Hero* hero, int i,int counter)
{
   string option;
   hero->printHeroDescription();
   hero->printStats();
   hero->printFirstAbilityDescription();
   hero->printSecondAbilityDescription();
   cout << "Would you like to choose the " << *(heroList + i) << " class(Yes/No)" << endl;
   cin >> option;
   while(option != "Yes" && option != "No" && option != "yes" && option != "no")
   {
      cout << "Invalid choice" << endl;
      cout << "Would you like to choose the " << *(heroList + i) << " class(Yes/No)" << endl;
      cin >> option;
   }
   if(option == "Yes")
   {
      if(counter == 1)
      {
         cout << "You can only pick one of each hero" << endl;
         return false;
      }
      else
      {
         party.push_back(hero);
         return true;
      }
   }
   else
   {
      return false;
   }
}

void Game::village()
{
   string choice;
   cout << "Your party starts its adventure in a small village" << endl;
   cout << "A man approaches you and says that the king " << endl;
   cout << "has died and the kingdom is being ruled by his 5 year" << endl;
   cout << "old son who is being controlled by the corrupt advisor." << endl;
   cout << "He asks if you would help him fight against the kingdom?" << endl;
   cout << "Do you choose to assist the man? (Yes/No)" << endl;
   cin >> choice;
   while(choice != "Yes" && choice!= "No")
   {
      cout << "Invalid choice" << endl;
      cout << "Do you choose to assist the man? (Yes/No)" << endl;
      cin >> choice;
   } 
   if(choice == "Yes")
   {
      helpMan();
   }
   else
   {
      cout << "The man tries to convince you to assist him again" << endl;
      cout << "Do you choose to assist the man? (Yes/No)" << endl;
      cin >> choice;
      while(choice != "Yes" && choice!= "No")
      {
         cout << "Invalid choice" << endl;
         cout << "Do you choose to assist the man? (Yes/No)" << endl;
         cin >> choice;
      }
      if(choice == "Yes")
      {
         helpMan();
      } 
      else
      {
         cout << "While you are arguing with the man your party is surrounded" << endl;
         cout << "by the kingdom's army and the man and your party are killed" << endl;
         menu("Your party has died");
      }
   } 
}

void Game::helpMan()
{
   cout << "The man thanks you and tells you to head to the" << endl;
   cout << "forest to meet with his allies in the next town." << endl;
   cout << "As you head to the forest the man is attacked by the" << endl;
   cout << "king's army and the man is killed. Your party is outnumbered" << endl;
   cout << "you flee to the forest in order to meet with his allies" << endl;
   forest();
}

void Game::forest()
{
   string choice;
   cout << "You start walking through the forest and a few" << endl;
   cout << "moments later a group of monsters attacks your party." << endl;
   battle(5);
   cout << "After your first encounter you spot a man who tells you " << endl;
   cout << "that there is a shortcut through the mountains." << endl;
   cout << "While it is quicker the man says it will be more dangerous." << endl;
   cout << "Do you choose to go through the mountains? (Yes/No)" << endl;  
   cin >> choice;
   while(choice != "Yes" && choice!= "No")
   {
      cout << "Invalid choice" << endl;
      cout << "Do you choose to go through the mountains? (Yes/No)" << endl; 
      cin >> choice;
   }
   if(choice == "Yes")
   {
      battle(7);
   } 
   cout << "As you continue through the forest a small group of monsters atttacks your party." << endl;
   battle(3);
   cout << "After the battle a man approaches you and tells you he is a merchant." << endl;
   cout << "He asks you if you would bring a package to the sand village." << endl;
   cout << "Do you choose to deliver his package? (Yes/No)" << endl;  
   cin >> choice;
   while(choice != "Yes" && choice!= "No")
   {
      cout << "Invalid choice" << endl;
      cout << "Do you choose to go through the mountains? (Yes/No)" << endl; 
      cin >> choice;
   }
   if(choice == "Yes")
   {
      cout << "As you leave the merchant the package starts to combust" << endl;
      cout << "You throw it away as far as you can but the blast still injures your party" << endl;
      cout << "The bomb causes all members in your party to take 15 damage" << endl;
      for(int i = 0; i < party.size(); i++)
      {
         party.at(i)->currentHealth -= 15;
      }
   } 
   cout << "You venture to the outskirts of the village and spot the sand village" << endl;
   cout << "As you are about to enter the village you are interrupted by a group of monsters" << endl;
   battle(4);
   sandVillage();
}

void Game::test()
{
   Archer* archer = new Archer;
   Berserker* berserker = new Berserker;
   Cleric* cleric = new Cleric;
   Gunslinger* gunslinger = new Gunslinger;
   party.push_back(berserker);
   party.push_back(archer);
   party.push_back(cleric);
   party.push_back(gunslinger);
   battle(5);
}

void Game::sandVillage()
{
   string choice;
   cout << "You have successfully arrived at the sand village and your party has been fully healed" << endl;
   heal(party);
   cout << "Would you like to save? (Yes/No)" << endl; 
   cin >> choice;
   while(choice != "Yes" && choice!= "No")
   {
      cout << "Invalid choice" << endl;
      cout << "You have successfully arrived at the sand village. Would you like to save? (Yes/No)" << endl; 
      cin >> choice;
   }
   if(choice == "Yes")
   {
      save(party, "Sand Village");
   } 
}

void Game::battle(int numberOfMonsters)
{
   srand(time(NULL));
   vector<Entity*> queue;
   for(int i = 0; i < party.size(); i ++)
   {
      queue.push_back(party.at(i));
   }
   while(monsters.size() < numberOfMonsters)
   {
      int choice = rand() % 5;
      if(choice == 0)
      {
         if(DarkElf::darkElfCounter == 0)
         {
            DarkElf* darkElf = new DarkElf;
            queue.push_back(darkElf);
            monsters.push_back(darkElf);
            DarkElf::darkElfCounter += 1;
         }        
      }
      if(choice == 1)
      {
         if(ForestSpirit::forestSpiritCounter == 0)
         {
            ForestSpirit* forestSpirit = new ForestSpirit;
            queue.push_back(forestSpirit);
            monsters.push_back(forestSpirit);
            ForestSpirit::forestSpiritCounter += 1;
         }        
         else if(ForestSpirit::forestSpiritCounter == 1)
         {
            ForestSpirit* forestSpirit1 = new ForestSpirit;
            queue.push_back(forestSpirit1);
            monsters.push_back(forestSpirit1);
            ForestSpirit::forestSpiritCounter += 1;
         }
      }
      if(choice == 2)
      {
         if(Goblin::goblinCounter == 0)
         {
            Goblin* goblin = new Goblin;
            queue.push_back(goblin);
            monsters.push_back(goblin);
            Goblin::goblinCounter += 1;
         }        
         else if(Goblin::goblinCounter == 1)
         {
            Goblin* goblin1 = new Goblin;
            queue.push_back(goblin1);
            monsters.push_back(goblin1);
            Goblin::goblinCounter += 1;
         }
      }
      if(choice == 3)
      {
         if(Ogre::ogreCounter == 0)
         {
            Ogre* ogre = new Ogre;
            queue.push_back(ogre);
            monsters.push_back(ogre);
            Ogre::ogreCounter += 1;
         }        
         else if(Ogre::ogreCounter == 1)
         {
            Ogre* ogre1 = new Ogre;
            queue.push_back(ogre1);
            monsters.push_back(ogre1);
            Ogre::ogreCounter += 1;
         }
      }
      if(choice == 4)
      {
         if(Skeleton::skeletonCounter == 0)
         {
            Skeleton* skeleton = new Skeleton;
            queue.push_back(skeleton);
            monsters.push_back(skeleton);
            Skeleton::skeletonCounter += 1;
         }        
         else if(Skeleton::skeletonCounter == 1)
         {
            Skeleton* skeleton1 = new Skeleton;
            queue.push_back(skeleton1);
            monsters.push_back(skeleton1);
            Skeleton::skeletonCounter += 1;
         }
      }
   }
   cout << "You are fighting ";
   if(DarkElf::darkElfCounter > 0)
   {
      cout << DarkElf::darkElfCounter << " Dark Elf ";
   }
   if(ForestSpirit::forestSpiritCounter > 0)
   {
      cout << ForestSpirit::forestSpiritCounter << " Forest Spirit(s) ";
   }
   if(Goblin::goblinCounter > 0)
   {
      cout << Goblin::goblinCounter << " Goblin(s) ";
   }
   if(Ogre::ogreCounter > 0)
   {
      cout << Ogre::ogreCounter << " Ogre(s) ";
   }
   if(Skeleton::skeletonCounter > 0)
   {
      cout << Skeleton::skeletonCounter << " Skeleton(s) ";
   }
   cout << endl;
   sort(queue.begin(), queue.end(), Entity::speedSort);
   while(battleOver(party, monsters) == 0)
   {
      for(int i = 0; i < 9; i++)
      {
         if(queue.at(i)->type == "Hero")
         {
            for(int j = 0; j < party.size(); j++)
            {
               if(queue.at(i)->name == party.at(j)->name && queue.at(i)->dead() == false)
               {
                  moveChoice(party.at(j), monsters);
                  break;
               }
            }
         } 
         else if(queue.at(i)->type == "Monster" && queue.at(i)->dead() == false)
         {
            for(int k = 0; k < monsters.size(); k++)
            {
               if(queue.at(i)->name == monsters.at(k)->name)
               {
                  monsterChoice(monsters.at(k), party);
                  break;
               }
            }
         }     
         if(battleOver(party, monsters) == 1)
         {
            cout << "You're party has defeated the group of monsters" << endl;
            levelUp(party, monsters);
            break;
         }
         else if(battleOver(party, monsters) == 2)
         {
            cout << "You're party has been defeated" << endl;
            break;
         }
      }
   }
}

void Game::bossBattle()
{
   
}

void Game::moveChoice(Hero* hero, vector<Monster*>& monsters)
{
   string moveBuffer;
   int move;
   int target;
   hero->printCurrentStats();
   hero->printFirstAbilityDescription();
   hero->printSecondAbilityDescription();
   cout << "Press 1 to use ability 1" << endl;
   cout << "Press 2 to use ability 2" << endl;
   cout << "Press 3 to normal attack" << endl;
   cin >> moveBuffer;
   move = atoi(moveBuffer.c_str());
   while(move < 1 || move > 3)
   {
      cout << "Invalid choice" << endl;
      cout << "Press 1 to use ability 1" << endl;
      cout << "Press 2 to use ability 2" << endl;
      cout << "Press 3 to normal attack" << endl;
      cin >> moveBuffer;
      move = atoi(moveBuffer.c_str());
   }
   if(hero->name == "Archer")
   {
      Archer* archer = reinterpret_cast<Archer*>(hero);
      if(move == 1)
      {
         target = targetSelect();
         archer->enchantedArrow(*monsters.at(target));
      }
      else if(move == 2)
      {
         archer->hailOfArrows(monsters);
      }
      else
      {
         target = targetSelect();
         archer->attackMove(*monsters.at(target));
      }
   }
   else if(hero->name == "Berserker")
   {
      Berserker* berserker = reinterpret_cast<Berserker*>(hero);
      if(move == 1)
      {
         target = targetSelect();
         berserker->recoilingStrike(*monsters.at(target));
      }
      else if(move == 2)
      {
         target = targetSelect();
         berserker->spinningSmash(*monsters.at(target));
      }
      else
      {
         target = targetSelect();
         berserker->attackMove(*monsters.at(target));
      }
   }
   else if(hero->name == "Cleric")
   {
      Cleric* cleric = reinterpret_cast<Cleric*>(hero);
      if(move == 1)
      {
         target = partyTargetSelect();
         cleric->burstHeal(*party.at(target));
      }
      else if(move == 2)
      {
         cleric->healingRain(party);
      }
      else
      {
         target = targetSelect();
         cleric->attackMove(*monsters.at(target));
      }
   }
   else if(hero->name == "Gunslinger")
   {
      Gunslinger* gunslinger = reinterpret_cast<Gunslinger*>(hero);
      if(gunslinger->reloading == true)
      {
         cout << "The gunslinger is reloading from its heavy shot" << endl;
         gunslinger->reload();
      }
      else if(move == 1)
      {
         target = targetSelect();
         gunslinger->doubleShot(*monsters.at(target));
      }
      else if(move == 2)
      {
         target = targetSelect();
         gunslinger->heavyShot(*monsters.at(target));
      }
      else
      {
         target = targetSelect();
         gunslinger->attackMove(*monsters.at(target));
      }
   }
   else if(hero->name == "Mage")
   {
      Mage* mage = reinterpret_cast<Mage*>(hero);
      if(move == 1)
      {
         target = targetSelect();
         mage->fireball(*monsters.at(target));
      }
      else if(move == 2)
      {
         mage->thunderstorm(monsters);
      }
      else
      {
         target = targetSelect();
         mage->attackMove(*monsters.at(target));
      }
   }
   else if(hero->name == "Vanguard")
   {
      Vanguard* vanguard = reinterpret_cast<Vanguard*>(hero);
      if(move == 1)
      {
         target = targetSelect();
         vanguard->ragingSpirit();
      }
      else if(move == 2)
      {
         vanguard->roaringTaunt(monsters);
      }
      else
      {
         target = targetSelect();
         vanguard->attackMove(*monsters.at(target));
      }
   }
   else if(hero->name == "Warrior")
   {
      Warrior* warrior = reinterpret_cast<Warrior*>(hero);
      if(move == 1)
      {
         target = targetSelect();
         warrior->empoweredSwing(*monsters.at(target));
      }
      else if(move == 2)
      {
         target = targetSelect();
         warrior->bladeFlurry(*monsters.at(target));
      }
      else
      {
         target = targetSelect();
         warrior->attackMove(*monsters.at(target));
      }
   }
}

void Game::monsterChoice(Monster* monster, vector<Hero*>& party)
{
   string moveBuffer;
   int move;
   int target;
   move = 3;//rand() % 3;
   if(monster->taunted(*monster) == true)
   {
      cout << monster->tauntedCounter;
      cout << "Taunted" << endl;
      for(int i = 0; i < party.size(); i++)
      {
         if(party.at(i)->name == "Vanguard")
         {
            target = i;
         }
      }
   }
   else
   {
      target = rand() % party.size();
      while(party.at(target)->dead() == true)
      {
         target = rand() % party.size();
      } 
   }

   if(monster->name == "Dark Elf")
   {
      DarkElf* darkElf = reinterpret_cast<DarkElf*>(monster);
      if(move == 1)
      {
         cout << "Ability 1" << endl;
      }
      else if(move == 2)
      {
         cout << "Ability 2" << endl;
      }
      else
      {
         darkElf->attackMove(*party.at(target));
      }
   }
   else if(monster->name == "Forest Spirit")
   {
      ForestSpirit* forestSpirit = reinterpret_cast<ForestSpirit*>(monster);
      if(move == 1)
      {
         cout << "Ability 1" << endl;
      }
      else if(move == 2)
      {
         cout << "Ability 2" << endl;
      }
      else
      {
         forestSpirit->attackMove(*party.at(target));
      }
   }
   else if(monster->name == "Goblin")
   {
      Goblin* goblin = reinterpret_cast<Goblin*>(monster);
      if(move == 1)
      {
         cout << "Ability 1" << endl;
      }
      else if(move == 2)
      {
         cout << "Ability 2" << endl;
      }
      else
      {
         goblin->attackMove(*party.at(target));
      }
   }
   else if(monster->name == "Ogre")
   {
      Ogre* ogre = reinterpret_cast<Ogre*>(monster);
      if(move == 1)
      {
         cout << "Ability 1" << endl;
      }
      else if(move == 2)
      {
         cout << "Ability 2" << endl;
      }
      else
      {
         ogre->attackMove(*party.at(target));
      }
   }
   else if(monster->name == "Skeleton")
   {
      Skeleton* skeleton = reinterpret_cast<Skeleton*>(monster);
      if(move == 1)
      {
         cout << "Ability 1" << endl;
      }
      else if(move == 2)
      {
         cout << "Ability 2" << endl;
      }
      else
      {
         skeleton->attackMove(*party.at(target));
      }
   }
}

int Game::targetSelect()
{
   string targetBuffer;
   int target;
   for(int i = 0; i < monsters.size(); i++)
   {
      if(monsters.at(i)->dead() == false)
      {
         cout << "Press " << i + 1 << " to attack " << monsters.at(i)->name << " Remaining Health: " << monsters.at(i)->currentHealth << endl;
      }
   }
   cin >> targetBuffer;
   target = atoi(targetBuffer.c_str());
   while(target < 0 || target > monsters.size() || monsters.at(target - 1)->dead() == true)
   {
      cout << "Invalid choice" << endl;
      for(int i = 0; i < monsters.size(); i++)
      {
         if(monsters.at(i)->dead() == false)
         {
            cout << "Press " << i + 1 << " to attack " << monsters.at(i)->name << " Remaining Health: " << monsters.at(i)->currentHealth << endl;
         }
      }
      cin >> targetBuffer;
      target = atoi(targetBuffer.c_str());
   }
   return target - 1;
}

int Game::partyTargetSelect()
{
   string targetBuffer;
   int target;
   for(int i = 0; i < party.size(); i++)

   {
      if(party.at(i)->dead() == false)
      {
         cout << "Press " << i + 1 << " to heal " << party.at(i)->name << " Remaining Health: " << party.at(i)->currentHealth << endl;
      }
   }
   cin >> targetBuffer;
   target = atoi(targetBuffer.c_str());
   while(target < 0 || target > party.size() || party.at(target - 1)->dead() == true)
   {
      cout << "Invalid choice" << endl;
      for(int i = 0; i < monsters.size(); i++)
      {
         if(monsters.at(i)->dead() == false)
         {
            cout << "Press " << i + 1 << " to attack " << monsters.at(i)->name << " Remaining Health: " << monsters.at(i)->currentHealth << endl;
         }
      }
      cin >> targetBuffer;
      target = atoi(targetBuffer.c_str());
   }
   return target - 1;
}

int Game::battleOver(vector<Hero*>& party, vector<Monster*>& monsters)
{
   bool monstersDead = true;
   bool partyDead = true;
   for(int i = 0; i < party.size(); i++)
   {
      if(party.at(i)->dead() == false)
      {
         partyDead = false;
      }
   }
   for(int j = 0; j < monsters.size(); j++)
   {
      if(monsters.at(j)->dead() == false)
      {
         monstersDead = false;
      }
   }
   if(monstersDead == true)
   {
      return 1;
   }
   else if(partyDead == true)
   {
      return 2;
   }
   else
   {
      return 0;
   }
}

void Game::levelUp(vector<Hero*>& party, vector<Monster*>& monsters)
{
   int totalExperience = 0;
   for(int i = 0; i < monsters.size(); i++)
   {
      totalExperience += monsters.at(i)->experience;
   }
   for(int j = 0; j < party.size(); j++)
   {
      if(party.at(j)->dead() == false)
      {
         party.at(j)->experience += totalExperience;
         party.at(j)->levelUp();
      }
   }
}

void Game::save(vector<Hero*>& party, string level)
{
   fstream file;
   string saveName;
   string save;
   cout << "What would you like to call your save?" << endl;
   cin >> saveName;
   save = saveName + ".txt";
   file.open(save, ios::out | ios::binary);
   if(file.fail())
   {
      cout << "Save Failed" << endl;
   }
   else
   {
      file << level << endl;
      for(int i = 0; i < party.size(); i++)
      {
         Hero * hero = party.at(i);
         file << left << setw(12) << hero->name;
         file << left << setw(5) << hero->type;
         file << left << setw(4) << hero->maxHealth;
         file << left << setw(4) << hero->currentHealth;
         file << left << setw(3) << hero->maxSp;
         file << left << setw(3) << hero->currentSp;
         file << left << setw(3) << hero->attack;
         file << left << setw(3) << hero->defense;
         file << left << setw(3) << hero->speed;
         file << left << setw(3) << hero->evasion;
         file << left << setw(3) << hero->criticalChance;
         file << left << setw(3) << hero->level;
         file << left << setw(3) << hero->experience << endl;
      }
   }
   file.close();
}

string Game::loadGame()
{
   fstream file;
   string saveName;
   string save;
   string levelName;
   string name;
   string type;
   int maxHealth;
   int currentHealth;
   int maxSp;
   int currentSp;
   int attack;
   int defense;
   int speed;
   int evasion;
   int criticalChance;
   int level;
   int experience;
   cout << "What is the name of your save?" << endl;
   cin >> saveName;
   save = saveName + ".txt";
   file.open(save, ios::in | ios::binary);
   if(file.fail())
   {
      cout << "Save could not be found." << endl;
   }
   else
   {
      getline(file, levelName);
      while(party.size() < 4)
      {
         file >> name;
         file >> type;
         file >> maxHealth;
         file >> currentHealth;
         file >> maxSp;
         file >> currentSp;
         file >> attack;
         file >> defense;
         file >> speed;
         file >> evasion;
         file >> criticalChance;
         file >> level;
         file >> experience;
         for(int i = 0; i < numberOfHeros; i++)
         {
            if(name == *(heroList + i))
            {
               if(i == 0)
               {
                  Archer* archer = new Archer(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience); 
                  party.push_back(archer);
               }  
               else if(i == 1)
               {
                  Berserker* berserker = new Berserker(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience); 
                  party.push_back(berserker);
               }
               else if(i == 2)
               {
                  Cleric* cleric = new Cleric(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience); 
                  party.push_back(cleric);
               }
               else if(i == 3)
               {
                  Gunslinger* gunslinger = new Gunslinger(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience); 
                  party.push_back(gunslinger);
               }
               else if(i == 4)
               {
                  Mage* mage = new Mage(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience); 
                  party.push_back(mage);
               }
               else if(i == 5)
               {
                  Vanguard* vanguard = new Vanguard(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience); 
                  party.push_back(vanguard);
               }
               else if(i == 6)
               {
                  Warrior* warrior = new Warrior(name, type, maxHealth, currentHealth, maxSp, currentSp, attack, defense, speed, evasion, criticalChance, level, experience); 
                  party.push_back(warrior);
               }
            }
         }
      }
   }
   return levelName;
}

void Game::heal(vector<Hero*>& party)
{
   for(int i = 0; i < party.size(); i++)
   {
      party.at(i)->heal();
   }
}