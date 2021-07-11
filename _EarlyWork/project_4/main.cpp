//------------------------------------------------------------
// Purpose: To implement an interactive horoscope generator.  
//          The user will enter their birthdate and answer a few
//          questions, and the program will print some advice.
//
// Author:  John Gauch - Created skeleton program.
// Author:  Julio Nolasco - Finished implementation of program.
//------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//------------------------------------------------------------
// Purpose: To prompt the user to enter their birthdate.
// Input:   None.
// Output:  The user's birth year, month, day.
//------------------------------------------------------------
void GetBirthDate(int & year, string & month, int & day)
{
   // Prompt user for birth year
   year = 0;
   while ((year < 1900) || (year > 2019))
   {
      cout << "Enter the year you were born [1900..2019]:\n ";
      cin >> year;
   }

   // Prompt user for birth month
   month = "";
   while (month != "Jan" && month != "Feb" && month != "Mar" && 
          month != "Apr" && month != "May" && month != "Jun" && 
          month != "Jul" && month != "Aug" && month != "Sep" && 
          month != "Oct" && month != "Nov" && month != "Dec")
   {
      cout << "Enter the month you were born [Jan..Dec]:\n ";
      cin >> month;
   }

   // Prompt user for birth day
   day = 0;
   while ((day < 1) || (day > 31))
   {
      cout << "Enter the day you were born [1..31]:\n ";
      cin >> day;
   }
}

//------------------------------------------------------------
// Purpose: To calculate the user's karma.
// Input:   None.
// Output:  The user's karma score.
//------------------------------------------------------------
int GetKarma()
{
   int answer = 0;
   cout << "How many people have you said hello to today?\n ";
   cin >> answer;
   
   // Silly karma calculation
   if (answer <= 0)
      return 0;
   else if (answer == 42)
      return 100;
   else 
      return (answer / 2) + (random() % 5);
      
}

//------------------------------------------------------------
// Purpose: Calculate the user's astrological sign.
// Input:   The user's birth month, day.
// Output:  The user's astrological sign.
//------------------------------------------------------------
string GetSign(const string month, const int day)
{
   if ((month == "Mar" && day >= 21) || (month == "Apr" && day <= 20))
      return "Aries";
   if ((month == "Apr" && day >= 21) || (month == "May" && day <= 21))
      return "Taurus";
   if ((month == "May" && day >= 22) || (month == "Jun" && day <= 21))
      return "Gemini";
   if ((month == "Jun" && day >= 22) || (month == "Jul" && day <= 22))
      return "Cancer";
   if ((month == "Jul" && day >= 23) || (month == "Aug" && day <= 22))
      return "Leo";
   if ((month == "Aug" && day >= 23) || (month == "Sep" && day <= 23))
      return "Virgo";
   if ((month == "Sep" && day >= 24) || (month == "Oct" && day <= 23))
      return "Libra";
   if ((month == "Oct" && day >= 24) || (month == "Nov" && day <= 22))
      return "Scorpio";
   if ((month == "Nov" && day >= 23) || (month == "Dec" && day <= 21))
      return "Sagittarius";
   if ((month == "Dec" && day >= 22) || (month == "Jan" && day <= 20))
      return "Capricorn";
   if ((month == "Jan" && day >= 21) || (month == "Feb" && day <= 19))
      return "Aquarius";
   if ((month == "Feb" && day >= 20) || (month == "Mar" && day <= 20))
      return "Pisces";
   return "";
}

//------------------------------------------------------------
// Purpose: Romance prediction
// Input:   The user's karma score.
// Output:  Prediction message.
//------------------------------------------------------------
string Romance(const int karma)
{
   int choice = (karma * 17) % 5;
   string message = "";
   switch(choice)
   {
   case 0:
      message = "Maybe your date would like to see a romantic comedy?";
      break;
   case 1:
      message = "I think it is singles night at the local pub.";
      break;
   case 2:
      message = "You should sit by the fire and read a good romance novel.";
      break;
   case 3:
      message = "Searching online for the perfect date seldom works.";
      break;
   case 4:
      message = "Love is not in the air tonight, time to play video games.";
      break;
   default:
      message = "Romance prediction is impossible.";
      break;
   }
   return message;
}

//------------------------------------------------------------
// Purpose: Money prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
void Money(const int year, string & message)
{
   int choice = (2019 - year) / 10;
   switch(choice)
   {
   case 0:
      message = "Ask your parents for their spare change.";
      break;
   case 1:
      message = "This is a good time to your parents for a bigger allowance.";
      break;
   case 2:
      message = "You can save more money by buying less beer.";
      break;
   case 3:
      message = "Try to save a little extra for a down payment on a house.";
      break;
   case 4:
      message = "Yikes, your children's tuition bills are due soon.";
      break;
   default:
      message = "Money prediction is impossible.";
      break;
   }
}

//------------------------------------------------------------
// Purpose: Job prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
string Job(const int day, const int karma)
{
   string message = "";
   if ((day < 15) && (karma > 5))
      message = "Your boss looks generous today, time to ask for a raise.";
   else if ((day > 15) && (karma < 5))
      message = "Prepare for bad news, your company profits are down.";
   else if ((day == 15) && (karma == 5))
      message = "Bad news, your company is declaring bankruptcy.";
   else if (karma > day)
      message = "Great news, your company just went public!";
   else if (karma <= day)
      message = "It looks like a chance for some overtime.";
   else
      message = "Money prediction is impossible.";
   return message;
}

//------------------------------------------------------------
// Purpose: Family prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
string FamilyPrediction(const int day)
{
    int Prediction = 0;
    Prediction = (31 - day);
    string message;
    if (Prediction >= 29)
    {
        message = "Your Family will be happy forever!";
    }
    else if (Prediction > 20)
    {
        message = "You should have your parents move in";
    }
    else if (Prediction > 10)
    {
        message = "There is a family gathering in your future";
    }
    else if (Prediction > 5)
    {
        message = "Take your folks to the movies";
    }
    else if (Prediction >= 0)
    {
        message = "You have no family just kidding you are all gonna be fine";
    }
       
     return message;
    }

//------------------------------------------------------------
// Purpose: Health prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
 string HealthPrediction(const int karma, const string zodiac)
 {
    
    string message;
     
     if (karma > 20)
     {
         message = "Looks like you will live to be 115";
     }
     else if (karma > 15)
     {
         message = "You should get your flu shot";
     }
     else if (karma > 10)
     {
         message = "Take those vitamins";
     }
     else if ( karma > 5)
     {
         message = "You should try yoga";
     }
     else if (karma >= 0)
     {
         message = "Looks like death is comin after ya bye";
     }
     
     return message;
    
 }

//------------------------------------------------------------
// Purpose: Silly prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
string SillyPrediction(const string zodiac)
{
    string message;
    if (zodiac == "Aquarius" || zodiac == "Aries")
    {
        message = "Hey looks like you are getting a new car";
    }
    else if (zodiac == "Scorpio" || zodiac == "Sagittarius")
    {
        message = "You should try yoga";
    }
    else if (zodiac == "Virgo" || zodiac == "Cancer")
    {
        message = "Keep up the good work";
    }
    else if (zodiac == "Leo" || zodiac == "Pisces")
    {
        message = "Wow you are so kind";
    }
    else
    message = "Not bad at all";
    
    return message;
    
}


//------------------------------------------------------------
// Purpose: Print user's horoscope.
// Input:   The user's birth year, month, day, karma.
// Output:  None.
//------------------------------------------------------------
void PrintHoroscope(const int year, const string month, 
   const int day, const int karma)
{
  string message;
  string zodiac;
  
  
   // Print user's sign
   zodiac = GetSign(month,day);
   cout << zodiac << endl;

   // Print romance prediction
  message = Romance(karma);
   cout << message << endl;

   // Print money prediction
  
   Money(year, message);
    cout << message << endl;
    
   // Print job prediction
  
   message = Job(day, karma);
   cout << message << endl;

   // Print family prediction
    message = FamilyPrediction(day);
    cout << message << endl;
  

   // Print health prediction
   message = HealthPrediction(karma,zodiac);
   cout << message << endl;


   // Print silly prediction
   message = SillyPrediction(zodiac);
   cout << message << endl;
}

//------------------------------------------------------------
// Purpose: The main program.
// Input:   None.
// Output:  None.
//------------------------------------------------------------
int main()
{
   // Initialize random number generator
srandom(time(NULL));
int seed; 
int year, day;
string month;
int karma = 0;
    
GetBirthDate(year, month, day);
karma = GetKarma();
PrintHoroscope(year, month, day, karma);

}




