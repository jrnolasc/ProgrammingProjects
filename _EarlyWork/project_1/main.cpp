#include <iostream>
using namespace std;

int main()
{
   // Variables used to determine weight of load 
    int pieces = 0;
    int truckWeight = 0;
    int calculatedLoad = 0;
    float diameter = 0;
    float length = 0;
    const float PI = 3.14 ;
    const float density = .284;
       
      // Ask user for input on length, diameter, and pieces of rebars
      //Math used to determine weight of load
        cout << "Enter length of diameter"<< endl;
        cin >> diameter;
        cout << "Enter length of rebars"<< endl;
        cin >> length;
        cout << "Enter number of rebars"<< endl;
        cin >> pieces;
        cout << "total weight of load "<< diameter/2 * diameter/2 * PI * pieces * length * 12 * density<< endl;
        
        // Determine the number of rebars that truck can hold
        cout << "Enter max weight limit of the truck"<< endl;
        cin >> truckWeight;
        cout << "Enter calculated load"<< endl;
        cin >>  calculatedLoad;
        cout << "You can carry " << truckWeight / calculatedLoad << " number of rebars" << endl;
         
          return 0;
}

