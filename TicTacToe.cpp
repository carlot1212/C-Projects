#include <iostream>
#include <time.h>

using namespace std;

#include <cstdlib>

void mainMenu();
void mainMenuChoices();
void secondMenu(int, int, int, int);
void secondMenuChoices();
void board();
void rules();
void selectionHelp();
void singlePlayerGame(int, int, int);
void twoPlayerGame(int, int, int);
void choice(int);
void computerChoice(int);
int simulation();
bool gameIsDone();
bool horizontalTest(char);
bool verticalTest(char);
bool topLeftDiagnol(char);
bool bottomLeftDiagnol(char);
void block();
void gameReset();
const int ROWSIZE = 3;
const int COLUMNSIZE = 3;
int usedSpaces = 0;
char boardValues [ROWSIZE][COLUMNSIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '},{' ', ' ', ' '}}; // board with no choices

int main()
{
   mainMenu();
}

void rules() // prints rules before a game
{
   cout << "Tic-Tac-Toe is a game where two players " << endl;
   cout << "take turns filling in spaces on a three by " << endl;
   cout << "three grid while trying to get three in a row " << endl;
   cout << "vertically, horizontally, or diagonally.\n" << endl;
   selectionHelp();
}

void board() // prints board
{
   cout << " " << boardValues[0][0] << " | " << boardValues[0][1] << " | " << boardValues[0][2] << " " << endl;
   cout << "---|---|---" << endl;
   cout << " " << boardValues[1][0] << " | " << boardValues[1][1] << " | " << boardValues [1][2]  << " " << endl;
   cout << "---|---|---" << endl;
   cout << " " << boardValues[2][0] << " | " << boardValues[2][1] << " | " << boardValues[2][2] << "  " << endl;
}

void mainMenu() // main menu
{
   string mainMenuBuffer;
   int choice = 0;
   mainMenuChoices();
   cin >> mainMenuBuffer;
   choice = atoi(mainMenuBuffer.c_str());
   while(choice < 1 || choice > 3) // input validation
   {
      cout << "Invalid choice" << endl;
      mainMenuChoices();
      cin >> mainMenuBuffer;
      choice = atoi(mainMenuBuffer.c_str());
   }   
   if(choice == 1) // starts a single player game
   {
      singlePlayerGame(0, 0, 0);
   }
   else if(choice == 2) // starts two player game
   {
      twoPlayerGame(0, 0, 0);
   }
   else
   {
      cout << "Thank you for playing" << endl; // exits game
   }
}

void mainMenuChoices() // prints options for main menu
{
   cout << "Press 1 for single player" << endl;
   cout << "Press 2 for 2 players" << endl;
   cout << "Press 3 to quit" << endl;
}

void singlePlayerGame(int playerWins, int computerWins, int ties)
{
   string difficultyBuffer;
   int difficulty;
   gameReset();
   rules();
   cout << "Press 1 for easy" << endl; // asks for difficulty setting
   cout << "Press 2 for hard" << endl;
   cin >> difficultyBuffer;
   difficulty = atoi(difficultyBuffer.c_str()); 
   while(difficulty < 1 && difficulty > 2) // input validation
   {
      cout << "Press 1 for easy" << endl;
      cout << "Press 2 for hard" << endl;
      cin >> difficultyBuffer;
      difficulty = atoi(difficultyBuffer.c_str()); 
   }
   while(gameIsDone() == false)
   {
      choice(1); // player chooses a space 
      board();
      if(gameIsDone() == true) // if player wins ends game
      {
         break;
      } 
      else
      {
         computerChoice(difficulty); // computer chooses a space
         board();
         if(gameIsDone() == true) // if computer wins ends game
         {
            break;
         }
      }
   }
   if(simulation() == 1) // player wins
   {
      cout << "You win" << endl;
      playerWins += 1;
   }
   else if(simulation() == 2)
   {
      cout << "The computer wins" << endl; // computer wins
      computerWins += 1;
   }
   else
   {
      cout << "The result is a tie" << endl; // no player wins
      ties += 1;
   }
   cout << "You have " << playerWins << " wins and the computer has " << computerWins << " wins and there have been " << ties << " ties" << endl;
   secondMenu(1, playerWins, computerWins, ties);
}

void twoPlayerGame(int playerOneWins, int playerTwoWins, int ties)
{
   gameReset();
   rules();
   while(gameIsDone() == false)
   {
      cout << "Player 1, "; // player one chooses
      choice(1);
      board();
      if(gameIsDone() == true) // if player one wins game ends
      {
         break;
      }
      else
      {
         cout << "Player 2, "; // player two chooses
         choice(2);
         board();
         if(gameIsDone() == true) // if player two wins game ends
         {
            break;
         }
      }
   }
   if(simulation() == 1)
   {
      cout << "Player 1 wins" << endl; // player one wins
      playerOneWins += 1;
   }
   else if(simulation() == 2)
   {
      cout << "Player 2 wins" << endl; // player two wins
      playerTwoWins += 1;
   }
   else
   {
      cout << "The result is a tie" << endl; // no player wins
      ties += 1;
   }
    cout << "Player 1 has " << playerOneWins << " wins and player 2 has " << playerTwoWins << " wins and there have been " << ties << " ties" << endl;
   secondMenu(2, playerOneWins, playerTwoWins, ties);
}

void selectionHelp() // prints help for picking a space
{
   cout << "To choose a space, type the number coordinates where" << endl;
   cout << "the first number is how many down and the second number. " << endl;
   cout << "is how many to the right with a space inbetween." << endl;
   cout <<  "The following is the coordinates for each space." << endl;
   cout << "1 1|1 2|1 3" << endl;
   cout << "---|---|---" << endl;
   cout << "2 1|2 2|2 3" << endl;
   cout << "---|---|---" << endl;
   cout << "3 1|3 2|3 3" << endl;
}

void choice(int player) // asks player to pick a space
{
   int row;
   int column;
   cout << "Select which space you would like to fill: ";
   cin >> row >> column;
   while(row < 1 || row > 3 || column < 1 || column > 3 || boardValues[row][column] != ' ') // input validation
   {
      if(row < 1 || row > 3 || column < 1 || column > 3) // test for an invalid coordinate
      {
         cout << "Invalid Choice" << endl;
         cout << "Select which space you would like to fill: " << endl;
         cout << "Press 4 4 for help with space selection" << endl;
         cin >> row >> column;
      }
      if(boardValues[row - 1][column - 1] != ' ')
      {
         cout << "Invalid Choice" << endl;
         cout << "This space has already been chosen." << endl;
         cout << "Choose a different space. "<< endl;
         cout << "Press 4 4 for help with space selection" << endl;
         cin >> row >> column;
      }
      if(row == 4)
      {
         selectionHelp();
         cout << "Select which space you would like to fill: " << endl; // prints help for picking a space
         cin >> row >> column;
      }
      else
      {
         break;
      }
   }
   boardValues[row - 1][column - 1] = player == 1 ? 'X' : 'O';
   usedSpaces += 1;
}

int simulation()
{
   
   int result = -1;
   for(int i = 0; i < 3; i++)
   {
      if(boardValues[i][0] != ' ' && boardValues[i][0] == boardValues[i][1] && boardValues[i][1] == boardValues[i][2]) // checks for horizontal win
      {
         result = boardValues[i][0] == 'X' ? 1 : 2; // checks which player won
      }
   }
   for (int j = 0; j < 3; j++)
   {
      if(boardValues[0][j] != ' ' && boardValues[0][j] == boardValues[1][j] && boardValues[1][j] == boardValues[2][j]) // checks for vertical win
      {
         result = boardValues[0][j] == 'X' ? 1 : 2; // checks which player won
      }
   }
   if(boardValues[0][0] != ' ' && boardValues[0][0] == boardValues[1][1] && boardValues[1][1] == boardValues[2][2]) // checks for top right to bottom left diagnol win
   {
      result = boardValues[0][0] == 'X' ? 1 : 2; // checks which player won
   }
   else if(boardValues[2][0] != ' ' && boardValues[2][0] == boardValues[1][1] && boardValues[1][1] == boardValues [0][2]) // checks for bottom right to top left diagnol win
   {
      result = boardValues[2][0] == 'X' ? 1 : 2; // checks which player won
   }
   else if(usedSpaces == 9)
   {
      result = 0; // no player wins and the result is a tie
   }
   else if(result < 0 && result > 2)
   {
      result = -1; // no win condition detected
   }
   return result;
}

void secondMenu(int players, int playerOneWins, int playerTwoWins, int ties)
{
   int choice;
   secondMenuChoices();
   cin >> choice;
   while(choice < 0 || choice > 3) // input validation
   {
      cout << "Invalid Choice" << endl;
      secondMenuChoices();
      cin >> choice;
      if(choice == 1) // starts a new game based on the number players
      {
         if(players == 1)
         {
             singlePlayerGame(playerOneWins, playerTwoWins, ties);
         }
         else
         {
            twoPlayerGame(playerOneWins, playerTwoWins, ties);
         }
      }
      else if(choice == 2) // goes back to the main menu
      {
         mainMenu();
      }
      else // exits the game
      {
         cout << "Thank you for playing" << endl;
      }
   }
}

void secondMenuChoices() // prints after game menu
{
   cout << "Press 1 to play again" << endl;
   cout << "Press 2 to go to the main menu" << endl;
   cout << "Press 3 to quit" << endl; 
}

bool gameIsDone() // tests if a player has won the game
{
   if(simulation() >=0 && simulation() <=2)
   {
      return true;
   }
   else
   {
      return false;
   }
}

void computerChoice(int difficulty)
{
   int computerRow;
   int computerColumn;
   if(difficulty == 1) // picks random spaces every time
   {

      srand(time(NULL));
      computerRow = rand() % 3;
      srand(time(NULL));
      computerColumn = rand() % 3;
      while(boardValues[computerRow][computerColumn] != ' ')
      { 
         srand(time(NULL));
         computerRow = rand() % 3;
         srand(time(NULL));
         computerColumn = rand() % 3;
      }
      boardValues[computerRow][computerColumn] = 'O';  
      cout << "The computer chose space " << computerRow + 1 << " " << computerColumn + 1 << endl;
   }
   else
   {
      if(boardValues[1][1] == ' ') // picks middle space first if player doesn't choose it
      {
         boardValues[1][1] = 'O';
         cout << "The computer chose space 2 2" << endl;  
      }
      else if(boardValues[1][1] == 'X' && usedSpaces < 3) // picks random corner if the middle space is chosen
      {
         computerRow = 1;
         computerColumn = 1;
         while(computerRow == 1 || computerColumn == 1)
         {
            srand(time(NULL));
            computerRow = rand() % 3;
            srand(time(NULL));
            computerColumn = rand() % 3;
         }
         boardValues[computerRow][computerColumn] = 'O';
         cout << "The computer chose space "  << computerRow + 1 << " " << computerColumn + 1 << endl;
      }
      else if(horizontalTest('O') == false) // performs all tests until one succeeds
      {
         if(verticalTest('O') == false)
         {
            if(topLeftDiagnol('O') == false)
            {
               if(bottomLeftDiagnol('O') == false)
               {
                  if(horizontalTest('X') == false)
                  {
                     if(verticalTest('X') == false)
                     {
                        if(topLeftDiagnol('X') == false)
                        {
                           if(bottomLeftDiagnol('X') == false)
                           {
                              block();
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   usedSpaces += 1;
}

bool horizontalTest(char symbol) // used to block or complete a horizontal three in a row
{
   bool turnIsDone = false;
   bool horizontalCheck = false;
   bool horizontalNotDone = false;
   int columnOne;
   int columnTwo;
   int columnThree;
   while(horizontalCheck == false)
   {
      for(int i = 0; i < ROWSIZE; i++)
      {
         columnOne = -1;
         columnTwo = -1;
         for(int j = 0; j < COLUMNSIZE; j++)
         { 
            if(boardValues[i][j] == symbol && columnOne != -1) // second column of filled space in row
            {
               columnTwo = j; 
            }
            else if(boardValues[i][j] == symbol) // first column of filled space in row
            {
               columnOne = j;
            }
            if(columnOne != -1 && columnTwo != -1)
            {
               for (int k = 0; k < 3; k++)
               {
                  if(k != columnOne && k != columnTwo) // sets empty space in row
                  {
                     columnThree = k;
                  } 
               }
               if(boardValues[i][columnThree] == 'O') // checks if three in a row is already blocked
               {
                    horizontalNotDone = true;
                    break;
               }
               else if(boardValues[i][columnThree] == ' ') // blocks or completes three in a row
               {
                  boardValues[i][columnThree] = 'O';
                  cout << "The computer chose " << i + 1 << " " << columnThree + 1 << endl;
                  horizontalCheck = true;
                  turnIsDone = true;
                  break;
               }                      
            
            }       
            if(horizontalNotDone == true) // resets columns if three in a row is already blocked
            {
               columnOne = -1;
               columnTwo = -1;
            } 
            if(columnOne != -1 && columnTwo != -1) // exits first loop if a space was chosen
            {
               break;
            }
         }
         if(i == 2)
         {
            horizontalCheck = true; // exits second loop if a space was chosen
            break;
         }
      }
   }
   return turnIsDone; // returns whether a move was made
}

bool verticalTest(char symbol) // used to block or complete a vertical three in a row
{
   bool turnIsDone = false;
   bool verticalCheck = false;
   bool verticalNotDone = false;
   int rowOne;
   int rowTwo;
   int rowThree;
   while(verticalCheck == false)
   {
      for(int l = 0; l < COLUMNSIZE; l++)
      {
         rowOne = -1;
         rowTwo = -1;
         for(int m = 0; m < ROWSIZE; m++)
         {
            if(boardValues[m][l] == symbol && rowOne != -1) // second row of filled space in column
            {
               rowTwo = m;
            }
            else if(boardValues[m][l] == symbol) // first row of filled space in column
            {
               rowOne = m;
            }
            if(rowOne != -1 && rowTwo != -1) // tests if two rows have been filled in column
            {
               for(int n = 0; n < 3; n++)
               {
                  if(n != rowOne && n != rowTwo) // sets empty space in column 
                  {
                     rowThree = n;
                  }
               }
               if(boardValues[rowThree][l] == 'O') // checks if three in a row is already blocked
               {
                  verticalNotDone = true;
                  break;
               }
               else if(boardValues[rowThree][l] == ' ') // blocks or completes three in a row
               {
                  boardValues[rowThree][l] = 'O';
                  cout << "The computer chose " << rowThree + 1 << " " << l + 1 << endl;
                  verticalCheck = true;
                  turnIsDone = true;
                  break;
               }
            }
            if(verticalNotDone == true) // resets rows if three in a row is already blocked
            {
               rowOne = -1;
               rowTwo = -1;
            } 
            if(rowOne != -1 && rowTwo != -1) // exits first for loop if a space was chosen
            {
               verticalCheck = true;
               break;
            }
         }
         if(l == 2) // exits second for loop if a space was chosen
         {
            verticalCheck = true;
            break;
         }
      }
   }
   return turnIsDone; // returns whether a move was made 
}

void block() // blocks player if there is no impending three in a row
{
   bool block = false;
   while(block == false) // finds first X starting from top row going left to right
   {
      for(int i = 0; i < ROWSIZE; i++) 
      {
         for(int j = 0; j < COLUMNSIZE; j++) 
         {
            if(boardValues[i][j] == 'X' && boardValues[i][j + 1] == ' ') // checks if space to the right of the first X is open
            {
               boardValues[i][j + 1] = 'O'; // chooses space to the right if it is open
               cout << "The computer chose " << i + 1 << " " << j + 2 << endl;
               block = true;
               break;
            }
            else if(boardValues[i][j] == 'X' && boardValues[i][j - 1] == ' ') // checks if space to the left of the first X is open
            {
               boardValues[i][j-1] = 'O'; // chooses space to the left if it is open
               cout << "The computer chose " << i + 1 << " " << j << endl;
               block = true;
               break;
            }
            else if(boardValues[i][j] == 'X' && boardValues[i + 1][j] == ' ') // checks if space above the first X is open 
            {
               boardValues[i + 1][j] = 'O'; // chooses space above if it is open
               cout << "The computer chose " << i + 2 << " " << j + 1 << endl;
               block = true;
               break;
            }
            else if(boardValues[i][j] == 'X' && boardValues[i + 1][j] == ' ') // checks if space below the first X is open
            {
               boardValues[i - 1][j] = 'O'; // chooses space below if it is open
               cout << "The computer chose " << i << " " << j + 1 << endl;
               block = true;
               break;
            } 
         }
         if(block == true)
         {
            break;
         }
      } 
   }
}

bool topLeftDiagnol(char symbol) // used to block or complete a diagnol three in a row from the top left to the bottom right
{
   bool turnIsDone = false;
   if(boardValues[0][0] == symbol && boardValues[0][0] == boardValues[1][1]) // checks if the top left and middle space are filled by the same player
   {
      if(boardValues[2][2] == ' ')
      {
         boardValues[2][2] = 'O'; // chooses the bottom right space if they are both filled
         cout << "The computer chose 3 3" << endl;
         turnIsDone = true;
      }
   }
   if(boardValues[1][1] == symbol && boardValues[1][1] == boardValues[2][2]) // checks if the bottom left and middle space are filled by the same player
   {
      if(boardValues[0][0] == ' ')
      {
         boardValues[0][0] = 'O'; // chooses top left space if they are both filled
         cout << "The computer chose 1 1" << endl;
         turnIsDone = true;
      }
   }
   return turnIsDone; // returns whether a move was made
}

bool bottomLeftDiagnol(char symbol) // used to block or complete a diagnol three in a row from the bottom left to the top right
{
   bool turnIsDone = false;
   if(boardValues[2][0] == symbol && boardValues[2][0] == boardValues[1][1]) // checks if bottom left and middle space are filled by the same player
   {
      if(boardValues[0][2] == ' ')
      {
         boardValues[0][2] = 'O'; // chooses top left space if both are filled
         cout << "The computer chose 1 3" << endl;
         turnIsDone = true;
      }
   }
   if(boardValues[1][1] == symbol && boardValues[1][1] == boardValues[0][2]) // checks if middle and top left space are filled by the same player
   {
      if(boardValues[2][0] == ' ')
      {
         boardValues[2][0] = 'O'; // chooses bottom left space if both are filled
         cout << "The computer chose 3 1" << endl;
         turnIsDone = true;
      }
   }
   return turnIsDone; // returns whether a move was made
}

void gameReset() // makes blank board and resets space counter
{
   usedSpaces = 0; 
   for(int i = 0; i < ROWSIZE; i++)
   {
      for(int j = 0; j < COLUMNSIZE; j++)
      {
         boardValues[i][j] = ' ';
      }
   }
}