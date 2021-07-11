#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
  // declare variables
   ofstream dout;
   int colomn = 0;
   int row = 0;
   string country;
   // introduce program
   
  cout << "Welcome to flags galore\n" << "Here are our available flags:" << endl;
  cout << "Hungary\n" << "Italy\n" << "France\n" << "Ireland\n" << "Germany\n" << "Please select one:" << endl;
  cin >> country;

    // check for the right input
   while (country != "Germany" && country != "Italy" && country != "Ireland" && country != "Hungary" && country != "France")
   {
       cout << "Please enter a correct country" << endl;
       cin >> country;
   }
  
   // ask for the size and cout ppm data
   cout << "Enter the number of rows you want between 100 and 1000" << endl;
   cin >> row;
   
   while (row <= 99 || row > 1000)
    {
        cout << "Try again"<<endl;
        cin >> row;
    }
   
   while (row%3 == 1)
   {
       row = row - 1;
   
       cout << row <<endl;
   }
   
   cout << "Enter the number of colomns you want between 100 and 1000"<< endl;
   cin >> colomn;
   
  
   // check colomn input
  while (colomn <= 99 ||colomn > 1000)
    {
        cout << "Try again"<<endl;
        cin >> colomn;
    }
 
   while (colomn%3 == 1)
   {
       colomn = colomn - 1;
   
       cout << colomn << endl;
   }
   
  // print german flag
   if (country == "Germany")
   {
    dout.open("Germany.ppm");
    cout << ("Creating file\n");    
    dout << "P3" << endl << row << " " << colomn << endl << "255"<< endl;
       
        for (int toprow = 1; toprow <= row / 3; toprow++)
        {
            for (int black = 1; black <= colomn; black++)
            {
                dout << "0 0 0  ";
            }
   
            dout << endl;
        }
        for (int midrow = 1; midrow <= row / 3; midrow++)
        {
            for (int red = 1; red <= colomn; red++)
            {
                dout << "221 0 0  ";
            }
   
            dout << endl;
        }
        for (int bottomrow = 1; bottomrow <= row / 3; bottomrow++)
        {
            for (int yellow = 1; yellow <= colomn; yellow++)
            {
                dout << "255 206 0  ";
            }
   
            dout << endl;
        }
       
        
        
        dout.close();
   }
    // print Hungary flag
  if (country == "Hungary")
   {
    
    dout.open("Hungary.ppm");
    cout << ("Creating file\n");  
    dout << "P3" << endl << row << " " << colomn << endl << "255"<< endl;
        for (int toprow = 1; toprow <= row / 3; toprow++)
        {
            for (int red = 1; red <= colomn; red++)
            {
                dout << "206 32 41  ";
            }
   
            dout << endl;
        }
        for (int midrow = 1; midrow <= row / 3; midrow++)
        {
            for (int white = 1; white <= colomn; white++)
            {
                dout << "255 255 255  ";
            }
   
            dout << endl;
        }
        for (int bottomrow = 1; bottomrow <= row / 3; bottomrow++)
        {
            for (int Green = 1; Green <= colomn; Green++)
            {
                dout << "1 135 82  ";
            }
   
            dout << endl;
        }

        dout.close();
   }
   // print Italy flag
  if (country == "Italy")
  {
    
    dout.open("Italy.ppm");
    cout << ("Creating file\n");
    dout << "P3" << endl << row << " " << colomn << endl << "255"<< endl;
     
     for (int startrows = 1; startrows <= row; startrows++)
        {
      
            for (int firstcolomn = 1; firstcolomn <= colomn /3; firstcolomn++)
            {
                dout << "0 146 71  ";
            }
            for (int secondcolomn = 1; secondcolomn <= colomn /3 ; secondcolomn++)
            {
                dout << "225 255 255  ";
            }
            for (int thirdcolomn = 1; thirdcolomn <= colomn / 3; thirdcolomn++)
            {
                dout << "224 0 36  ";
            }
        dout << endl;
        }
        
        dout.close();  
  }
  
    // print Ireland flag
  if (country == "Ireland")
  {
    
    dout.open("Ireland.ppm");
    cout << ("Creating file\n");
    dout << "P3" << endl << row << " " << colomn << endl << "255"<< endl;
     
     for (int startrows = 1; startrows <= row; startrows++)
   {
      
        for (int firstcolomn = 1; firstcolomn <= colomn / 3; firstcolomn++)
        {
            dout << "22 155 98  ";
        }
        for (int secondcolomn = 1; secondcolomn <= colomn / 3; secondcolomn++)
        {
            dout << "255 255 255  ";
        }
        for (int thirdcolomn = 1; thirdcolomn <= colomn / 3; thirdcolomn++)
        {
            dout << "255 136 62  ";
        }
       dout << endl;
   }
        
        dout.close();   
  }
   
     // print France flag
   if (country == "France")
  {
    
    dout.open("France.ppm");
    cout << ("Creating file\n");
    dout << "P3" << endl << row << " " << colomn << endl << "255"<< endl;
     for (int startrows = 1; startrows <= row; startrows++)
   {
      
        for (int firstcolomn = 1; firstcolomn <= colomn / 3; firstcolomn++)
        {
            dout << "0 35 149  ";
        }
        for (int secondcolomn = 1; secondcolomn <= colomn / 3; secondcolomn++)
        {
            dout << "225 255 255  ";
        }
        for (int secondcolomn = 1; secondcolomn <= colomn / 3; secondcolomn++)
        {
            dout << "237 41 57  ";
        }
       dout << endl;
   }
        dout.close();  
  }
   
   return 0 ;
}






