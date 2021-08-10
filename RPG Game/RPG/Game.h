#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Archer.h"
#include "Berserker.h"
#include "Cleric.h"
#include "DarkElf.h"
#include "Dragon.h"
#include "ForestSpirit.h"
#include "Goblin.h"
#include "Gunslinger.h"
#include "Mage.h"
#include "Monster.h"
#include "Ogre.h"
#include "Skeleton.h"
#include "Vanguard.h"
#include "Warrior.h"

class Game
{
public:
   void menu(string);
   void menuOptions();
   void newGame();
   string loadGame();
   void characterChoice();
   void heroLoop(string);
   void printHeros();
   bool validation(string);
   bool heroSelection(Hero *, int, int);
   void village();
   void helpMan();
   void forest();
   void sandVillage();
   void battle(int);
   void bossBattle();
   void save(vector<Hero*>&, string);
   void moveChoice(Hero*, vector <Monster*>&);
   void monsterChoice(Monster*, vector <Hero*>&);
   int targetSelect();
   int partyTargetSelect();
   int battleOver(vector <Hero*>&, vector <Monster*>&);
   void levelUp(vector<Hero*>&, vector<Monster*>&);
   void heal(vector<Hero*>&);
   void test();
};
#endif