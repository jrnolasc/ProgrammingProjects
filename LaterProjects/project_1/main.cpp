/******************************************************************************
Julio Nolasco 

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
#include "MagicDeck.h"

int main()
{
    MagicDeck Card;

    Card.Read_Deck();
    Card.PrintDeck();
    
    return 0;
}
