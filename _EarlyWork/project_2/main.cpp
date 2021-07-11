#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
   //determine the best variables
   
   int Meatlove = 0;
   int Vegetableslove = 0;
   int Pastalove = 0;
   int Potatoeslove = 0;
   int Chocolatelove = 0 ;
   int Fruitlove = 0;
   float budget = 0;
   const float TAX = 0.07;
   float Bill = 0.0;
   
   //Introduce the user to the restaurant and ask questions
   
    cout << "Welcome Welcome to JoJo's epic suprise Bistro!" << endl;
    cout << "You look new so lets get an idea of what you are into!" << endl;
    cout << "Before we get started ask yourself how much can I spend today" << endl << "Enter budget:" << endl;
    cin >> budget;
    
        
    cout << "Alright good now lets get started\n" << "Rate your love for Meat on a scale of 1 to 100" << endl;
    cin >> Meatlove;
        if (Meatlove > 100)
        {
            Meatlove = 100;
        }
        else if (Meatlove < 1)
        {
            Meatlove = 1;
        }
    cout << "Rate your love for Vegetables from 1 to 100" << endl;
    cin >> Vegetableslove;
          if (Vegetableslove > 100)
        {
            Vegetableslove = 100;
        }
        else if (Vegetableslove < 1)
        {
            Vegetableslove = 1;
        }
    cout << "Rate your love for Pasta from 1 to 100" << endl;
    cin >> Pastalove;
           if (Pastalove> 100)
        {
            Pastalove = 100;
        }
        else if (Pastalove < 1)
        {
            Pastalove = 1;
        }
    cout << "Rate your love for Potatoes from 1 to 100" << endl;
    cin >> Potatoeslove;
           if (Potatoeslove > 100)
        {
            Potatoeslove = 100;
        }
        else if (Potatoeslove < 1)
        {
            Potatoeslove = 1;
        }
    cout << "Rate your love for Chocolate from 1 to 100" << endl;
    cin >> Chocolatelove;
           if (Chocolatelove > 100)
        {
            Chocolatelove = 100;
        }
        else if (Chocolatelove < 1)
        {
            Chocolatelove = 1;
        }
    cout << "Wow I sound like a broken record almost like a program or something... but I am not a program I have feelings haha anyway..."<< endl;
    cout << "Rate your love for Fruit from 1 to 100" << endl;
    cin >> Fruitlove;
           if (Fruitlove > 100)
        {
            Fruitlove = 100;
        }
        else if (Fruitlove < 1)
        {
            Fruitlove = 1;
        }
    
    // Find cost of the Appetizer
    if (budget > 14)
     {
        if (Meatlove > Vegetableslove && Meatlove > 9)
        {
            cout << "Appetizer: Chicken Wings Woop! Woop!" << endl;
            Bill = Bill + 5;
            
        }
        else if (Meatlove < Vegetableslove && Vegetableslove > 9)
        {
            cout << "Appetizer: Salad ohhhh!" << endl;
            Bill = Bill + 5;
        }
        else if (Meatlove && Vegetableslove < 9)
        {
            cout << "Appetizer: Garlic Bread \n You are picky shade thrown" << endl;
            Bill = Bill + 5;
        }
    
     }  
    
   

    // Find cost of Main Dish 
    if (budget > 9)
    {
         if (Vegetableslove > Meatlove && Potatoeslove && Pastalove && Vegetableslove > 9)
         {
            cout << "Main Course: Pasta primavera yum" << endl;
            Bill = Bill + 10;
         }
         else if  (Meatlove && Potatoeslove > Meatlove && Pastalove && Meatlove && Potatoeslove > 9)
         {
            cout << "Main Course: Steak and Potato hehe!" << endl;
            Bill = Bill + 10;
         }
         else if (Meatlove && Pastalove > Meatlove && Potatoeslove && Meatlove && Pastalove > 9)
         {
            cout << "Main Course: Spaghetti and Sauce!" << endl;
            Bill = Bill + 10;
         }
         else if (Meatlove && Pastalove && Potatoeslove & Vegetableslove < 9)
         {
             cout << "Main Course: Cheese Omelet! Aw Man!" << endl;
             Bill = Bill + 10; 
         }
    }
    
    else if (budget <= 9)
    {
        cout << "Hey you cant eat here get out!!" << endl;
    }

    // Find cost of Dessert
    if (budget > 19)
    {
        if (Chocolatelove > Fruitlove && Chocolatelove > 9)
        {
            cout << "Dessert: Chocolate Cake " << endl;
            Bill = Bill + 5;
        }
        else if (Fruitlove > Chocolatelove && Fruitlove > 9)
        {
            cout << "Dessert: Apple Pie" << endl;
            Bill = Bill + 5;
        }
        else if (Chocolatelove && Fruitlove < 9)
        {
            cout << "Dessert: Vanilla Ice Cream" << endl;
            Bill = Bill + 5;
        }
        
    }
    cout << endl << "Balance: " << endl;
    cout << "Tax: $" << TAX << endl;
    cout << "Total: $" << (Bill * TAX) + Bill << endl << "Thank you for stopping by have a beautiful day owo" << endl;

    
}





