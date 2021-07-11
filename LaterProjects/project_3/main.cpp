
#include <stdio.h>
#include "Dictionary.h"

int count = 0;
const int SIZE = 1000;
string sample[SIZE];
 Dictionary test;

void readfile(string file)
{
    ifstream din;
  din.open(file.c_str());
  if (din.fail())
      return;
      
  count = 0;
  string str;
  while (din >> str && count < SIZE)
  {
        for (int i=0; i< str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }
        sample[count++] = str;
      
    
  }

  din.close();
}

void comparewords()
{
     float total = 0.0;
    int index = 0;
    float divider = 0.0;
    int arraysearch = 0;

    string words;
    //cout << "count: " << count << endl;
  	
  	for (index = 0; index < count; index++)
     {
  	    words = sample[index];
        arraysearch = test.lookupWord(words);
         cout << "word: " << words << endl;
            
                  if (arraysearch == -1)
                  {
                      total = total + 1001;
                  }
                else 
                {
                    total = total + test.getValue(arraysearch);
                }
  	    
     }
  
 
 total = total/count;
    cout << "Reading Level: " << total << endl;
    cout << endl;
    
}

void Dialog()
{
        cout << "What Would You Like To Do Next? " << endl;
        cout << "Search For Certain Word Levels: S " << endl;
        cout << "Search For Book Reading Levels: B" << endl;
        cout << "Exit: E" << endl;
}

void UserInterface()
{
    string WordValue;
    string file;
    int index;
    string samplefile;
    char Input = ' ';
    
        cout << "Plase enter the word.txt file: " << endl;
        cin >> file;
        cout << endl;
    
        while (file != "word.txt")
        {
            cout << "Plase enter the word.txt file: " << endl;
            cin >> file;
            cout << endl;
        }
        test.readFile(file);
        
        Dialog();
    
        cin >> Input;
        cout << endl;
   
    while(Input != 'E' && Input != 'e')
    {
    
        if ((Input == 'B') || (Input == 'b'))
        {
            cout << "Current Books In Library: " << endl;
            cout << "1.)David Copperfield: sample.txt"<< endl;
            cout << "2.)The Time Machine: sample2.txt" << endl;
            cout << "3.)Robinson Crusoe: sample3.txt" << endl;
            cout << "4.)Alice In Wonderland: sample4.txt" << endl;
            cout << "5.)The Cat In The Hat: sample5.txt" << endl;
            cout << endl;
    
            cout << "Enter The Proper Sample File Name: " << endl;
            cout << endl;
            cin >> samplefile;
            while (samplefile != "sample.txt" && samplefile != "sample2.txt" && samplefile != "sample3.txt" && samplefile != "sample4.txt"  && samplefile != "sample5.txt" )
            {
                cout << "Please Enter One Of Our Current Books: " << endl;
                cin >> samplefile;
                cout << endl;
            }
            cout << endl;
               
            //test.readSampleFile(samplefile);
           // test.comparewords();
           
           readfile(samplefile);
           comparewords();
            Dialog();
            cin >> Input;
            cout << endl;
        }
        else if ((Input == 'S') || (Input == 's'))
        {
            cout << "Enter Word"<< endl;
            cin >> WordValue; 
            cout << endl;

            test.lookupWord(WordValue);
            index = test.lookupWord(WordValue);
            cout << "MY WORD: " << test.getword(index) << endl;
            cout << "MY VALUE: " << test.getValue(index) <<endl;
            cout << endl;
            
            Dialog();
            cin >> Input;
            cout << endl;
        }
        else
        {
            cout << "Select a Vaild Option: " << endl;
            cin >> Input;
            cout << endl;
        }
            
    }
}


int main()
{
    UserInterface();
 
    return 0;
}

