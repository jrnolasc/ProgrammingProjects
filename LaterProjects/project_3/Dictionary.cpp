#include "Dictionary.h"

Dictionary :: Dictionary()
{
    cout << "construct" << endl;
    // Initialize word array
   count = 0;
   for (int i = 0; i < NUM_WORDS; i++)
   {
      word[i] = "";
   }
   for (int i = 0; i < NUM_RANK; i++)
   {
     rank[i] = 0;
   }
}

Dictionary :: ~Dictionary()
{
    cout << "destructor" << endl;
}
void Dictionary::readFile(string filename)
{
   // Open input file
   ifstream din;
   din.open(filename.c_str());
   if (din.fail())
      return;
   
   // Read integers into Data array
   count = 0;
   int num;
   string str;
   while (din>> num>>str && count < NUM_RANK)
   {
      rank[count++] = num;
   
   }
   


   din.close();
   readFiles(filename);
}

void Dictionary::readFiles(string filename)
{
     ifstream din;
   din.open(filename.c_str());
   if (din.fail())
      return;
   
   // Read integers into Data array
   count = 0;
   int num;
   string str;
   //din >> num >> str;
   while (din>> num>>str && count < NUM_WORDS)
   {
    
      word[count++] = str;
   }
   


   din.close();
}

int Dictionary :: getValue(int index)
{
       if (index < count)
        return rank[index];
    else 
        return 0;
}

string Dictionary :: getword(int index)
{
     if (index < count)
        return word[index];
   else
      return "";
}

int Dictionary :: lookupWord(string words)
{
   
    return WordSearch(words, 0, count-1);
}

int Dictionary :: WordSearch(string words, int low, int high)
{

   int mid = (low + high) / 2;
 
   // Check termination conditions
   if (low > high)
      return -1;
   else if (word[mid] == words)
      return mid;

   // Handle recursive cases
   else if (word[mid] > words)
      return WordSearch(words, low, mid - 1);
   else 
      return WordSearch(words, mid + 1, high);

        
}