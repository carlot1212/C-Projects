#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#include <cstdlib>

void mainMenu();
void mainMenuChoices();
void rules();
void secondMenu(int, int, int);
void secondMenuChoices();
void singlePlayerGame(int, int);
void twoPlayerGame(int, int);
int choice();
int simulation(int, int);
string text [3] = {"Rock", "Paper", "Scissors"}; // used to convert number choices to string

int main()
{
   mainMenu();
}

void mainMenu() // main menu
{
   string choiceBuffer;
   int choice;
   cout << "Rock, Paper, Scissors" << endl;
   mainMenuChoices();
   cin >> choiceBuffer;
   choice = atoi(choiceBuffer.c_str());
   while(choice < 1 || choice > 3) // input validation
   {
      cout << "Invalid Choice" << endl;
      mainMenuChoices();
      cin >> choiceBuffer;
      choice = atoi(choiceBuffer.c_str());
    }
  if(choice == 1) // calls single player game
  {
    rules();
    singlePlayerGame(0,0);
  }
  else if(choice == 2) // calls two player game
  {
    rules();
    twoPlayerGame(0,0);
  } 
  else // exits program
  {
    cout << "Thank you for playing";
  }
}

void rules() // prints rules when a game is played
{
  cout << "Rock, Paper, Scissors is a two player game where both " << endl;
  cout << "players select rock, paper, or scissors and the winner " << endl;
  cout << "is decided on these scenarios where rock beats scissors, " << endl;
  cout << "scissors beats paper, and paper beats rock." << endl;
}

void singlePlayerGame(int playerWins, int computerWins) //game between human player and computer
{
   int playerChoice;
   int computerChoice;
   int result;
   srand(time(NULL)); // resets seed every game
   computerChoice = rand() % 3 + 1; // generates random number between 1 and 3
   playerChoice = choice(); // asks player to choose
   result = simulation(playerChoice, computerChoice); // tests who would win
   cout << "You chose " << text[playerChoice-1] << " and the computer chose " << text[computerChoice-1] << endl; // prints the player choice and the computer choice
   if(result == 1) // prints who wins
   {
      cout << "You win" << endl;
      playerWins += 1;
   }
   else if(result == 2)
   {
     cout << "The computer wins" << endl;
     computerWins += 1;
   }
   else
   {
      cout << "The result is a tie" << endl;
   }
    cout << "You have " << playerWins << " win(s) and the computer has " << computerWins << " win(s)" << endl; // prints total wins
    secondMenu(1, playerWins, computerWins); // calls menu when a game is finished
}

void twoPlayerGame(int playerOneWins, int playerTwoWins) // game between two human players
{
   int playerOneChoice;
   int playerTwoChoice;
   int result;
   cout << "Player 1, "; // asks player one to choose
   playerOneChoice = choice(); 
   cout << "Player 2, "; // asks player two choose
   playerTwoChoice = choice();
   result = simulation(playerOneChoice, playerTwoChoice); // tests who would win
   cout << "Player 1 chose " << text[playerOneChoice-1] << " and Player 2 chose " << text[playerTwoChoice-1] << endl; // prints both player's choices
   if(result == 1) // prints who wins
   {
      cout << "Player 1 wins" << endl;
      playerOneWins += 1;
   }
   else if(result == 2)
   {
      cout << "Player 2 wins" << endl;
      playerTwoWins += 1;
   }
   else
   {
      cout << "The result is a tie" << endl;
   }
   cout << "Player 1 has " << playerOneWins << " win(s) and player 2 has " << playerTwoWins << " win(s)" << endl; // prints total wins
   secondMenu(2,playerOneWins,playerTwoWins); // calls menu when a game is finished
}

int choice() // player chooses rock, paper, or scissors
{
   string playerChoiceBuffer;
   int playerChoice;
   cout << "Press 1 for Rock, Press 2 for Paper, or Press 3 for Scissors: ";
   cin >> playerChoiceBuffer;
   playerChoice = atoi(playerChoiceBuffer.c_str());
   while(playerChoice < 1 || playerChoice > 3) // input validation
   {
      cout << "Invalid Choice" << endl;
      cout << "Press 1 for Rock, Press 2 for Paper, or Press 3 for Scissors" << endl;
      cin >> playerChoiceBuffer;
      playerChoice = atoi(playerChoiceBuffer.c_str());
   }
   return playerChoice;
}

int simulation(int one, int two) // decides who won based on the player's choice
{
   if(one == 1 && two == 3) // player one chose rock and player two chose scissors so player one wins
   {
      return 1;
   }
   else if(one == 2 && two == 1) // player one chose paper and player two chose rock so player one wins
   {
      return 1;
   }
   else if(one == 3 && two == 2) // player one chose scissors and player two chose paper so player one wins
   {
      return 1;
   }
   else if(one == 3 && two == 1) // player one chose scissors and player two chose rock so player two wins
   {
      return 2;
   }
   else if(one == 1 && two == 2) // player one chose rock and player two chose paper so player two wins
   {
      return 2;
   }
   else if(one == 2 && two == 3) // player one chose paper and player two chose scissors so player two wins
   {
      return 2;
   }
   else // players chose the same choice resulting in a tie
   {
      return 0;
   }
}

void secondMenu(int players, int one, int two) // menu action handling after game ends
{
   string choiceBuffer;
   int choice;
   secondMenuChoices();
   cin >> choiceBuffer;
   choice = atoi(choiceBuffer.c_str());
   while(choice < 1 || choice > 3) // input validation
   {
      cout << "Invalid Choice" << endl;
      secondMenuChoices();
      cin >> choice;
   }
   if (choice == 1) // calls game function to play again based on what was previoiusly played
   {
      if(players ==1)
      {
         singlePlayerGame(one, two);
      }
      else
      {
         twoPlayerGame(one, two);
      }
   }
   else if(choice == 2) // calls main menu function to return to the main menu
   {
      mainMenu();
   }
   else // exits the program
   {
      cout << "Thank you for playing";
   }
}

void mainMenuChoices() // prints main menu options
{
   cout << "Press 1 for single player" << endl;
   cout << "Press 2 for two players" << endl;
   cout << "Press 3 to quit" << endl; 
}

void secondMenuChoices() // prints options after a game is played
{
   cout << "Press 1 to play again" << endl;
   cout << "Press 2 to go to the main menu" << endl;
   cout << "Press 3 to quit" << endl;
}
