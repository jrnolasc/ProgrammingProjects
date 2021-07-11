
#include "MagicDeck.h"


MagicDeck :: MagicDeck()
{
    count = 0;
}

MagicDeck :: MagicDeck(const MagicDeck & param)
{
    count = param.count;
}

MagicDeck :: ~MagicDeck()
{
    count = 0;
}

void MagicDeck::Read_Deck()
{
    // Open input file 
    ifstream din;
    din.open("Deck.txt");
    if (din.fail())
        cout << "Could Not open file\n";
    
    // Read count of books
    string str;
    getline(din, str);
    count = atoi(str.c_str());
    
    // Loop reading book records
    for (int i = 0; i < count && !din.eof(); i++)
    {
         
        getline(din, str);
        cards[i].setCardname(str);
       
        getline(din, str);
        cards[i].setManacost(atoi(str.c_str()));
       
        getline(din, str);
        cards[i].setType(str);
        
        getline(din, str);
        cards[i].setCardtext(str);
        
        getline(din, str);
        cards[i].setRarity(str);
        
        getline(din, str);
        cards[i].setCardnumber(atoi(str.c_str()));
        
        getline(din, str);
        cards[i].setCondition(str);
        
        getline(din, str);
        cards[i].setPurchaseprice(atoi(str.c_str()));
        
        getline(din, str);
        cards[i].setCurrentValue(atoi(str.c_str()));
      
        getline(din, str);
        cards[i].setQuantity(atoi(str.c_str()));
  
        getline(din, str);
        cards[i].print();
         
    }

    // Close input file
    din.close();
    
}

void MagicDeck::PrintDeck()
{
    float total = TotalValue();
    float HighValue = MostValuable();
    int quantity = MostNumerous();
    
    cout << "Total: $" << total << endl;
    cout << "Most Valuable: $" << HighValue << endl; 
    cout <<"Most Numerous: " << quantity << endl;
}

float MagicDeck::TotalValue()
{
   float total = 0.0;
   float Number = 0.0;
  
   float value = 0.0;
   for (int i = 0; i < count; i++)
   {
      value = cards[i].getCurrentValue();
      Number = cards[i].getQuantity();
     
       total += value * Number;
  }
   
   // cout << "Total: $" << total << endl;
   return total;
}

float MagicDeck::MostValuable()
{
     int HighValue = 0;
     string cardname = "";
     
     for (int i = 0; i < count; i++)
     {
        
         if (HighValue < cards[i].getCurrentValue())
         {
             HighValue = cards[i].getCurrentValue();
             cardname  = cards[i].getCardname();
         }
         
     }
     //cout << "Most Valuable: $" << HighValue << " :" << cardname << endl; 
     return HighValue;
}

int MagicDeck :: MostNumerous()
{
     int Number = 0;
     string cardnames = "";
     
     for (int i = 0; i < count; i++)
     {
        
         if (Number < cards[i].getQuantity())
         {
             Number = cards[i].getQuantity();
             cardnames  = cards[i].getCardname();
         }
         
     }
     //cout <<"Most Numerous: " << Number << " :" << cardnames <<endl;
     return Number;
}

