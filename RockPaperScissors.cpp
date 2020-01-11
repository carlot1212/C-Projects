// Rock Paper Scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void mainMenu();
void mainMenuChoices();
void rules();
void secondMenu(int, int, int);
void secondMenuChoices();
void singlePlayerGame(int, int);
void twoPlayerGame(int, int);
int choice();
int simulation(int, int);
string text [3] = {"Rock", "Paper", "Scissors"}; 

int main()
{
  mainMenu();
}

void mainMenu()
{
  int choice;
  cout << "Rock, Paper, Scissors" << endl;
  mainMenuChoices();
  cin >> choice;
  while(choice != 1 && choice !=2 && choice !=3)
  {
    cout << "Invalid Choice" << endl;
    mainMenuChoices();
    cin >> choice;
  }
  if (choice == 1)
  {
    rules();
    singlePlayerGame(0,0);
  }
  else if(choice == 2)
  {
    rules();
    twoPlayerGame(0,0);
  }
  else
  {
    cout << "Thank you for playing";
  }
}

void rules()
{
  cout << "Rock, Paper, Scissors is a two player game where both " << endl;
  cout << "players select rock, paper, or scissors and the winner " << endl;
  cout << "is decided on these scenarios where rock beats scissors, " << endl;
  cout << "scissors beats paper, and paper beats rock." << endl;
}

void singlePlayerGame(int playerWins, int computerWins)
{
  int playerChoice;
  int computerChoice;
  int result;
  srand(time(NULL));
  computerChoice = rand() % 3 + 1;
  playerChoice = choice();
  result = simulation(playerChoice, computerChoice);
  cout << "You chose " << text[playerChoice-1] << " and the computer chose " << text[computerChoice-1] << endl;
  if(result == 1)
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
  cout << "You have " << playerWins << " win(s) and the computer has " << computerWins << " win(s)" << endl;
  secondMenu(1, playerWins, computerWins);
}

void twoPlayerGame(int playerOneWins, int playerTwoWins)
{
  int playerOneChoice;
  int playerTwoChoice;
  int result;
  cout << "Player 1, ";
  playerOneChoice = choice();
  cout << "Player 2, ";
  playerTwoChoice = choice();
  result = simulation(playerOneChoice, playerTwoChoice);
  cout << "Player 1 chose " << text[playerOneChoice-1] << " and Player 2 chose " << text[playerTwoChoice-1] << endl;
  if(result == 1)
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
  cout << "Player 1 has " << playerOneWins << " win(s) and player 2 has " << playerTwoWins << " win(s)" << endl;
  secondMenu(2,playerOneWins,playerTwoWins);
}

int choice()
{
  int playerChoice = 0;
  cout << "Press 1 for Rock, Press 2 for Paper, or Press 3 for Scissors" << endl;
  cin >> playerChoice;
  while(playerChoice != 1 && playerChoice !=2 && playerChoice !=3)
  {
    cout << "Invalid Choice" << endl;
    cout << "Press 1 for Rock, Press 2 for Paper, or Press 3 for Scissors" << endl;
    cin >> playerChoice;
  }
  return playerChoice;
}

int simulation(int one, int two)
{
  if(one == 1 && two == 3)
  {
    return 1;
  }
  else if(one == 2 && two == 1)
  {
    return 1;
  }
  else if(one == 3 && two == 2)
  {
    return 1;
  }
  else if(one == 3 && two == 1)
  {
    return 2;
  }
  else if(one == 1 && two == 2)
  {
    return 2;
  }
  else if(one == 2 && two == 3)
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

void secondMenu(int players, int one, int two)
{
  int choice;
  secondMenuChoices();
  cin >> choice;
  while(choice != 1 && choice !=2 && choice !=3)
  {
    cout << "Invalid Choice" << endl;
    secondMenuChoices();
    cin >> choice;
  }
  if (choice == 1)
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
  else if(choice == 2)
  {
    mainMenu();
  }
  else
  {
    cout << "Thank you for playing";
  }
}

void mainMenuChoices()
{
  cout << "Press 1 for single player" << endl;
  cout << "Press 2 for two players" << endl;
  cout << "Press 3 to quit" << endl;
}

void secondMenuChoices()
{
  cout << "Press 1 to play again" << endl;
  cout << "Press 2 to go to the main menu" << endl;
  cout << "Press 3 to quit" << endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
