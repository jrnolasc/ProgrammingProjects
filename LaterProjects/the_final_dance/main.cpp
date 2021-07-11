//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>


//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node * Tree)
{
   // Delete node and it's children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
   // Call tree destroy function
   DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string Value, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
   {
        cout << "OOF that name is not on the list" << endl;
      return false;
   }
   else if (Tree->Value == Value)
   {
      cout << "Name: " << Tree->Value << " Count: "  << Tree-> Count << " Percent: " << Tree-> Percent << " Rank: " << Tree->Rank << endl;
      return true;
   }

   // Recursively search for data value
   else if (Tree->Value > Value)
      return (SearchHelper(Value, Tree->Left));
   else 
      return (SearchHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(string Value)
{
   // Call tree searching function
   return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string Value, int Count, float Percent, int Rank, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Value = Value;
      Tree->Count =Count;
      Tree->Percent = Percent;
      Tree->Rank = Rank;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->Value > Value)
      return (InsertHelper(Value, Count, Percent, Rank, Tree->Left));
   else 
      return (InsertHelper(Value, Count, Percent, Rank, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string Value, int Count, float Percent, int Rank)
{
   // Call tree insertion function
   return (InsertHelper(Value, Count, Percent, Rank, Root));
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node * &Tree)
{
   Node *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      Node *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
	 Parent = Temp;
	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	 Parent->Right = Temp->Right;
      else
	 Parent->Left = Temp->Right;
      Tree->Value = Temp->Value;
   }

   // Delete node
   delete Temp;
   return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(string Value, Node * &Tree)
{
   // Data value not found
   if (Tree == NULL)
   {
      cout << "Name Not Found: " << endl;
      return false;
   }

   // Data value found and deleted
   else if (Tree->Value == Value)
   {
     cout << "Deleting: " << Value << endl;
      return (DeleteNode(Tree));
   }

   // Recursively search for node to delete
   else if (Tree->Value > Value)
      return (DeleteHelper(Value, Tree->Left));
   else 
      return (DeleteHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(string Value)
{
   // Call tree deletion function
   return (DeleteHelper(Value, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
       cout << "Name: " << Tree->Value << " Count: "  << Tree-> Count << " Percent: " << Tree-> Percent << " Rank: " << Tree->Rank << endl;

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}


//-----------------------------------------------------------
// Main program tests the BinaryTree class.
//-----------------------------------------------------------
void Dialog()
{
 
    cout << "Make A Selection: " << endl;
    cout << "P - Print Names: " << endl;
    cout << "E - Enter A New Name: " << endl;
    cout << "D - Delete Name: " << endl;
    cout << "S - Search For A Name: " << endl;
    cout << "Q - Quit Search: " << endl;
}

int main()
{
   // Create tree
   BinaryTree Tree;
   string file; 
   string namesearch;
   
   cout << "Select a file: ";
   cin >> file;

    if (file != "male.txt" && file != "last.txt" && file != "female.txt")
    {
        cout << "Enter the right file name: "<< endl;
        cin >> file;
    }

    ifstream din;
  din.open(file.c_str());
      
  string str;
  int getcount;
  float getpercent;
  int getrank;
  
  string name;
  int count;
  float percent;
  int rank;
  while (din >> str >> getcount >> getpercent >> getrank)
  {
      name = str;
      count = getcount;
      percent = getpercent;
      rank = getrank;
      
      Tree.Insert(name, count, percent, rank);
  }

  din.close();

char input;
    
    Dialog();
    cin >> input;
   while (input != 'Q' && input != 'q')
   {
   
    if (input == 'S' || input == 's')
    {
        cout << "What you lookin for: " << endl;
        cin >> namesearch;
        Tree.Search(namesearch);
       Dialog();
        cin >> input;
    }
    else if (input == 'D' || input == 'd')
    {
       cout << "What name do you want to delete: " << endl;
        cin >> namesearch;
        Tree.Delete(namesearch);
        Dialog();
        cin >> input;
    }
    else if (input == 'P' || input == 'p')
    {
        Tree.Print();
       Dialog();
        cin >> input;
    }
    else if (input == 'E' || input == 'e')
    {
        cout << "Enter Name: " << endl;
        cin >> name;
        cout << "Enter Count: " << endl;
        cin >> count;
        cout << "Enter Percent: " << endl;
        cin >> percent;
        cout << "Enter Rank: " << endl;
        cin >> rank; 
        
        Tree.Insert(name, count, percent, rank);
        
        Dialog();
        cin >> input;
    }
    else
    {
        cout << "Please Make A Proper Selection: " << endl;
       Dialog();
        cin >> input;
    }
   
   }
   
   return 0;
}
