
#include "Magic.h"


 
const int SIZE = 20;

class MagicDeck:public Magic
{
 public:
   // Constructors
   MagicDeck();
   MagicDeck(const MagicDeck & param);
   ~MagicDeck();
  
  void Read_Deck();
  void PrintDeck();
  float TotalValue();
  float MostValuable();
  int MostNumerous();
   

float Total; 
  
 private:
   
    int count;
    Magic cards[SIZE];
  
 	
 
};