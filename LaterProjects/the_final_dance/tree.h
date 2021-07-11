//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
 public:
   string Value;
   int Count;
   float Percent;
   int Rank;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(string Value);
   bool Insert(string Value, int Count, float Percent, int Rank);
   bool Delete(string Value);
   void Print();

 private:
   // Helper functions
   void DestroyHelper(Node * Tree);
   bool SearchHelper(string Value, Node * Tree);
   bool InsertHelper(string Value, int Count, float Percent, int Rank, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(string Value, Node * &Tree);
   void PrintHelper(Node * Tree);

   // Tree pointer
   Node *Root;
};