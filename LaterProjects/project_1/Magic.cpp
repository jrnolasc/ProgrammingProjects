
#include "Magic.h"


Magic :: Magic()
{
  //cout << "Constructer\n";  

     CardName  = "";
 	 CardText = "";
 	 Type = "";
 	 Rarity = "";
 	 Condition = "";
 	 PurchasePrice = 0.0;
     CurrentValue = 0.0;
 	 ManaCost = 0.0;
     Quantity = 0;
 	 CardNumber = 0;
}

Magic :: Magic(const Magic & param)
{
    cout << "copy Constructer\n";

     CardName  = param.CardName;
 	 CardText = param.CardText;
 	 Type = param.Type;
 	 Rarity = param.Rarity;
 	 Condition = param.Condition;
 	 PurchasePrice = param.PurchasePrice;
     CurrentValue = param.CurrentValue;
 	 ManaCost = param.ManaCost;
     Quantity = param.Quantity;
 	 CardNumber = param.CardNumber;
    
}
Magic :: ~Magic()
{
    //cout << "Deonstructer\n";  
}

string Magic :: getCardname()
{
    //cout << "getCardname\n";
    return CardName;
}

void Magic :: setCardname(const string name)
{
    // cout << "setCardname\n";
     
     CardName = name;
}

string Magic :: getType()
{
  //  cout << "getType\n";
  return Type;
}

void Magic :: setType(const string type)
{
   // cout << "setType\n";

    Type = type;
}

string Magic :: getRarity()
{
   // cout << "getRarity\n";
   return Rarity;
}

void Magic :: setRarity(const string rarity)
{
    //cout << "setRarity\n";

    Rarity = rarity;
}

string Magic :: getCondition()
{
    //cout << "getCondition\n";
    return Condition;
}

void Magic :: setCondition(const string condition)
{
    //cout << "setCondition\n";

    Condition = condition;
}

float Magic :: getManacost()
{
    //cout << "getManacost\n";
    return ManaCost;
}

void Magic :: setManacost(const float cost)
{
   // cout << "setManacost\n";

    ManaCost = cost;
}

float Magic :: getPurchaseprice()
{
    //cout << "getPurchaseprice\n";
    return PurchasePrice;
    
}

void Magic :: setPurchaseprice(const float price)
{
    //cout << "setPurchaseprice\n";

    PurchasePrice = price;
}

float Magic :: getCurrentValue()
{
   // cout << "getCurrentValue\n";
    return CurrentValue;
    
}
  
void Magic :: setCurrentValue(const float value)
{
    //cout << "setCurrentValue\n";

    CurrentValue = value;
   
}

string Magic :: getCardtext()
{
   // cout << "getCardtext\n";
    return CardText;
    
}

void Magic :: setCardtext(const string text)
{
   // cout << "setCardtext\n";

    CardText = text;
}

int Magic :: getCardnumber()
{
   // cout << "getCardnumber\n";
    return CardNumber;
    
}
  
void Magic :: setCardnumber(const int number)
{
       // cout << "setCardnumber\n";

    CardNumber = number;
}

int Magic :: getQuantity()
{
   // cout << "getQuantity\n";
   return Quantity;
}

void Magic :: setQuantity(const int quantity)
{
   // cout << "setQuantity\n";

    Quantity = quantity;
}

void Magic :: print()
{
    cout << "Card Name: "<< CardName << endl;
    cout << "Mana Cost: " << ManaCost << endl;
    cout << "Type: " << Type << endl;
    cout << "Card Text: " << CardText << endl;
    cout << "Rarity: " << Rarity << endl;
    cout << "Card Number: "<< CardNumber << endl;
    cout << "Condition: " << Condition << endl;
    cout << "Purchase Price: $" << PurchasePrice << endl;
    cout << "Current Value: $" << CurrentValue << endl;
    cout << "Quantity: " << Quantity << endl;
    cout << "" << endl;
}
