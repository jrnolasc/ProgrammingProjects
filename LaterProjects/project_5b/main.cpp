#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
vector<string> data;
vector<string> array[26];
vector<int> wordcount;

int count = 0;
ofstream dout;
string openname;
string filename;

void Reset()
{
    int e = 0;
    int empty = 0;
    string word = " ";
    while (e < 25)
    {
    
     for (int i = 0; i < array[e].size(); i++)
        {
            array[e][i] = word;

        //  cout << array[e][i] << endl;
        }
        e ++;
    }
    
    for (int i = 0; i < count+1; i++)
    {
        data[i] = word;
        wordcount[i] = empty;
    }
    
    count = 0;
    openname = " ";
    filename = " ";
}
string FixWord(string word)
{
     // Loop over characters to fix word
    string result = "";
    for (int i=0; i<(int)word.length(); i++)
    {
        // Save special character
        if (word[i] == '\'')
            result += word[i];
        
        // Save lower case letters
        else if ((word[i] >= 'a') && (word[i] <= 'z'))
            result += word[i];
        
        // Save upper case letters as lower case letters
        else if ((word[i] >= 'A') && (word[i] <= 'Z'))
            result += word[i] - 'A' + 'a';
    }
    return result;
}

void merge_sort(vector <string> & array, int low, int high)
{
   // Check terminating condition
   int range = high - low + 1;
   
  
   if (range > 1) 
   {
       
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      merge_sort(array, low, mid);
      merge_sort(array, mid + 1, high);

      // Create temporary array for merged data
      string *copy = new string[range];

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;
       
      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
	 if (array[index1] < array[index2])
	 {
	    copy[index++] = array[index1++];
	 }

	 else
	    {
	    copy[index++] = array[index2++];
	    }
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid)
      {
	     copy[index++] = array[index1++];
      }
	 

      // Copy any remaining entries from the second half
      while (index2 <= high)
      {
	     copy[index++] = array[index2++];
      }

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
      {
	    array[low + index] = copy[index];
      }
      delete []copy;
   }
}

void read_file(string file)
{
    
    ifstream din;
  din.open(file.c_str());
  if (din.fail())
      return;
  string str;
  string word;
  while (din >> str)
  {
       str = FixWord(str);
        data.push_back(str);
        count++;
        
        word = str;

            int index = word[0] - 'a';
            array[index].push_back(word);
  }
data.resize(count+1);
wordcount.resize(count+1);
  din.close();
}

void print(string openname)
{
    int copy = 0;
    int e = 0;
    string word;
    while (e < 25)
    {
    
     for (int i = 0; i < array[e].size(); i++)
        {
            word =  array[e][i];

            data[copy++] = word;

        //  cout << array[e][i] << endl;
        }
        e ++;
    }

    dout.open(openname.c_str());
     for(int j = 0; j< count; ++j)
    {
       for (int k = 0; k < count; ++k)
       {
           if (data[j] == data[k])
           {
               wordcount[j] = wordcount[j] +1;
           }
       }
        if (data[j] == data[j+1])
        {
          //  cout << "Repeating word: Skip" << endl;
        }
        else
        {
        dout << data[j] << ' ' << wordcount[j] << ' ';
        dout << endl;
        }
    }

    dout.close();
    data.clear();
    wordcount.clear();
  for (int i = 0; i < array[i].size(); i++)
    array[i].clear();
    
    
}

int main()
{

    cout << "Enter a book:" << endl;
    cout << "TimeMachine.txt" << endl;
    cout << "AnneGables.txt" << endl;
    cout << "JungleBook.txt" << endl;
    
    
    cin >> filename;
    read_file(filename);
    
    if (filename == "TimeMachine.txt")
    {
        openname = ("TimeMachine.count");
    }
    else if (filename ==  "AnneGables.txt")
    {
         openname = ("AnneGables.count");
    }
    else
    {
        openname = ("JungleBook.count");
    }
    

    for (int i = 0; i < 26; i++)
    {
        merge_sort(array[i], 0, array[i].size()-1);
        
    }

    print(openname);
    

    return 0;
}


