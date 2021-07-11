#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;



class Magic
{
 public:
   // Constructors
    Magic();
    Magic(const Magic & param);
   ~Magic();
  
     void print();
   // Get methods
   string getCardname();
   string getType();
   string getRarity();
   string getCondition();
   string getCardtext();
   float getManacost();
   float getPurchaseprice();
   float getCurrentValue();
   int getQuantity();
   int getCardnumber();
   // Set methods
  
   void setCardname(const string name);
   void setManacost(const float cost);
   void setType(const string type);
   void setCardtext(const string text);
   void setCardnumber(const int number);
   void setRarity(const string rarity);
   void setCondition(const string condition);
   void setPurchaseprice(const float price);
   void setCurrentValue(const float value);
   void setQuantity(const int quantity);

       	
       float CurrentValue;
 private:
 
    string CardName;
    string CardText;
 	string Type;
 	string Rarity;
 	string Condition;
 	float PurchasePrice;
 
    
 	float ManaCost;
    int Quantity;
 	int CardNumber;
 	

    
 
};