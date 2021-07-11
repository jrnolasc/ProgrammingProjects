//---------------------------------------------------
// Purpose:     Header file for the Tic4 class
//
// Author:      John Gauch - Created class definition.
//              YOUR NAME - Completed implementation.
//---------------------------------------------------

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

#ifndef TIC4
#define TIC4

// Global constants 
const int SIZE = 4;

// Class definition
class Tic4
{
   public:
      // Constructor and destructor
      Tic4();
      ~Tic4();

      // Public methods
      void ClearBoard();
      bool SetBoard(const int row, const int col, const char player);
      bool GetBoard(const int row, const int col, char & player);
      bool CheckWin(const char player);
      bool SimpleAi(const char player);
      bool RandomAi(const char player);
      bool CleverAi(const char player);
      bool FancyAi(const char player);
      bool IsFull();
      void PrintBoard();
      
     

   private:
     // Private variables
     char board[SIZE][SIZE];
     int board_count;
};

//---------------------------------------------------
// Purpose:     Implementation of the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              YOUR NAME - Completed implementation.
//---------------------------------------------------



//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Tic4::Tic4()
{
   ClearBoard();
}

//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Tic4::~Tic4()
{
   // Intentionally empty
}

//---------------------------------------------------
// Clear the Tic4 board
//---------------------------------------------------
void Tic4::ClearBoard()
{
   // Initialize Tic4 board
   for (int c = 0; c < SIZE; c++)
   for (int r = 0; r < SIZE; r++)
      board[r][c] = ' ';
}

//---------------------------------------------------
// Set value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::SetBoard(const int row, const int col, const char player)
{
   // Error checking
   if ((row < 0) || (row >= SIZE) || 
       (col < 0) || (col >= SIZE) ||
       (board[row][col] != ' '))
      return false;

   // Set value of board
   board[row][col] = player;
   return true;
}

//---------------------------------------------------
// Get value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::GetBoard(const int row, const int col, char & player)
{
   // Error checking
   if ((row < 0) || (row >= SIZE) || 
       (col < 0) || (col >= SIZE) ||
       (board[row][col] != ' '))
      return false;

   // Get value of board
   player = board[row][col];
   return true;
}

//---------------------------------------------------
// Check to see if player has won the game
//---------------------------------------------------
bool Tic4::CheckWin(const char player)
{
   // Check all the rows
   for (int r = 0; r < SIZE; r++)
   {
      // Count player pieces
      int count = 0;
      for (int c = 0; c < SIZE; c++)
         if (board[r][c] == player)
            count++;
      if (count == SIZE)
      {
         return true;
      }
   }

   // Check all the cols
   for (int c = 0; c < SIZE; c++)
   {
      // Count player pieces
      int count = 0;
      for (int r = 0; r < SIZE; r++)
         if (board[r][c] == player)
            count++;
      if (count == SIZE)
         {
         return true;
         }
   }

   // Check first diagonal
   int count = 0;
   for (int r = 0; r < SIZE; r++)
   {
      int c = r;
      if (board[r][c] == player)
         count++;
   }
   if (count == SIZE) 
      {
         return true;
      }
    
   // Check second diagonal
   count = 0;
   for (int r = 0; r < SIZE; r++)
   {
      int c = SIZE-1-r;
      if (board[r][c] == player)
         count++;
   }
   if (count == SIZE) 
      {
         return true;
      }
   
   // The player did not win
   return false;
}

//---------------------------------------------------
// Print the Tic4 board
//---------------------------------------------------
void Tic4::PrintBoard()
{
   // Draw column numbers
   cout << "\n     ";
   for (int c = 0; c < SIZE; c++)
      cout << c << "   ";
   cout << "\n";

   // Print the Tic4 board
   for (int r = 0; r < SIZE; r++)
   {
      // Draw dashed line
      cout << "   +";
      for (int c = 0; c < SIZE; c++)
         cout << "---+";
      cout << "\n";

      // Draw board contents
      cout << " " << r << " | ";
      for (int c = 0; c < SIZE; c++)
         cout << board[r][c] << " | ";
      cout << "\n";
   }

   // Draw dashed line
   cout << "   +";
   for (int c = 0; c < SIZE; c++)
      cout << "---+";
   cout << "\n\n";

    
}
//---------------------------------------------------
// Check if board is full
//---------------------------------------------------
bool Tic4::IsFull()
{
 
   if (board_count == SIZE * SIZE)
   {
       return true;
   }
   else if (board_count != SIZE * SIZE)
   {
       return false;
   }
}

//return bool 
bool Tic4::SimpleAi(const char player)
{
    cout << "SimpleAi"<<endl;
      if (board[0][0] == ' ')
            board[0][0] = player;
        else if (board[0][1] == ' ')
            board[0][1] = player;
        else if (board[0][2] == ' ')
            board[0][2] = player;
        else if (board[0][3] == ' ')
            board[0][3] = player;
        else if (board[1][0] == ' ')
            board[1][0] = player;
        else if (board[1][1] == ' ')
            board[1][1] = player;
        else if (board[1][2] == ' ')
            board[1][2] = player;
        else if (board[1][3] == ' ')
            board[1][3] = player;
        else if (board[2][0] == ' ')
            board[2][0] = player;
        else if (board[2][1] == ' ')
            board[2][1] = player;
        else if (board[2][2] == ' ')
            board[2][2] = player;
        else if (board[2][3] == ' ')
            board[2][3] = player;
        else if (board[3][0] == ' ')
            board[3][0] = player;
        else if (board[3][1] == ' ')
            board[3][1] = player;
        else if (board[3][2] == ' ')
            board[3][2] = player;
        else if (board[3][3] == ' ')
            board[3][3] = player;
}
//return bool 
bool Tic4::RandomAi(const char player)
{
      cout << "RandomAi"<<endl;

     int count = 0;
   while (count < 1)
   {
      int r = random() % SIZE;
      int c = random() % SIZE;
      if (board[r][c] == ' ')
      {
         board[r][c] = player;
         count++;
      }
   }
}
//return bool 
bool Tic4:: CleverAi(const char player)
{
     //Fix
     cout << "CleverAi"<<endl;
        if (board[0][0] == ' ')
            board[0][0] = player;
        else if (board[1][1] == ' ')
            board[1][1] = player;
        else if (board[2][2] == ' ')
            board[2][2] = player;
        else if (board[3][3] == ' ')
            board[3][3] = player;
        else if (board[0][3] == ' ')
            board[0][3] = player;
        else if (board[1][2] == ' ')
            board[1][2] = player;
        else if (board[2][1] == ' ')
            board[2][1] = player;
        else if (board[3][0] == ' ')
            board[3][0] = player;
            // if no diagonal is found
        else if (board[0][1] == ' ')
            board[0][1] = player;
        else if (board[0][2] == ' ')
            board[0][2] = player;
        else if (board[1][0] == ' ')
            board[1][0] = player;
        else if (board[1][3] == ' ')
            board[1][3] = player;
        else if (board[2][0] == ' ')
            board[2][0] = player;
        else if (board[2][3] == ' ')
            board[2][3] = player;
        else if (board[3][1] == ' ')
            board[3][1] = player;
         else if (board[3][2] == ' ')
            board[3][2] = player;
        
}
//return bool 
bool Tic4:: FancyAi(const char player)
{
    cout << "FancyAi"<<endl;
    int picknum = random() % 3;
    
    if (picknum != 2 && picknum !=3)
    {
        SimpleAi(player);
    }
    else if (picknum == 2)
    {
        RandomAi(player);
    }
    else if (picknum == 3)
    {
        CleverAi(player);
    }

    
}

//---------------------------------------------------
// Purpose:     Main program for the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              YOUR NAME - Completed implementation.
//---------------------------------------------------



//---------------------------------------------------
// Main program to play Tic4 game
//---------------------------------------------------
void runTic4game()
{
      // Declare variables
     // Declare variables
   Tic4 game;
   int row, col;

   // Play game
   cout << "\nWelcome to 4x4 tic-tac-toe\n";
   game.PrintBoard();
   while (!game.IsFull())
   {
      // Get X move
      cout << "Enter X move: ";
      cin >> row >> col;
      while (game.SetBoard(row, col,'X') == false)
      {
         cout << "Enter X move: ";
         cin >> row >> col;
      }
      game.PrintBoard();

      // Check if X wins
      if (game.CheckWin('X'))
      {
         cout << "X wins!\n\n";
         exit(0);
      }

      // Get O move
      cout << "Enter O move: ";
      cin >> row >> col;
      while (game.SetBoard(row, col,'O') == false)
      {
         cout << "Enter O move: ";
         cin >> row >> col;
      }
      game.PrintBoard();

      // Check if O wins
      if (game.CheckWin('O'))
      {
         cout << "O wins!\n\n";
         exit(0);
      }
   }
   cout << "Sorry, nobody wins.\n\n";
   exit(0);
}

int main()
{
  srandom(time(NULL));
runTic4game();
   return 0;
}

#endif
























