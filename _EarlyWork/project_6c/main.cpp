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
      void PrintBoard();
     

   private:
     // Private variables
     char board[SIZE][SIZE];
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
// Purpose:     Main program for the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              YOUR NAME - Completed implementation.
//---------------------------------------------------



//---------------------------------------------------
// Main program to play Tic4 game
//---------------------------------------------------
void rungame()
{
  Tic4 board;
  int row, column;
  char player;
   
  
  cout << "Welcome to 4x4 Tic Tac Toe :)" << endl;

    board.ClearBoard();
    board.PrintBoard();

  while (board.CheckWin('X') != true && board.CheckWin('O') != true)
  {
    cout << "Player: X"<< endl;
    cout << "Move"<< endl;
    cout << "row:"<< endl;
    cin >> row;
    cout << "column:"<< endl;
    cin >> column;
    
      board.SetBoard(row, column, 'X');
      board.PrintBoard();
      board.CheckWin(player); 
      if (board.CheckWin('X') == true)
      {
          cout <<" X Wins!"<<endl;
          exit(0);
      }
      
    cout << "Player: O"<< endl;
    cout << "Move"<< endl;
    cout << "row:"<< endl;
    cin >> row;
    cout << "column:"<< endl;
    cin >> column;
      board.SetBoard(row, column, 'O');
      board.PrintBoard();
      board.CheckWin(player); 
       if (board.CheckWin('O') == true)
      {
          cout <<" O Wins!"<<endl;
          exit(0);
      }
  }
   
}

int main()
{
  rungame();
   return 0;
}

#endif



















