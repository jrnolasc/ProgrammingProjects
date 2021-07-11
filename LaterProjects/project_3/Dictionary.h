
#include <fstream>
#include <iostream>
using namespace std;

//----------------------------------------------
 const int NUM_WORDS = 1000;
 const int NUM_RANK = 1000;


class Dictionary
{
public:
   // Constructors
   Dictionary();
   ~Dictionary();

  

   void readFile(string filename);
   void readFiles(string filename);
   int getValue(int index);
   string getword(int index);
   int lookupWord(string words);
    int WordSearch(string words, int low, int high);
  

private:
   int count;
   string word[NUM_WORDS];
   int rank[NUM_RANK];

  
};