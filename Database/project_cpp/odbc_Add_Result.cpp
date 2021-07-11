#include "odbc_db.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
string Username = "jrnolasc";            
string mysqlPassword = "aiK5usei";  
string SchemaName = "jrnolasc";          

   odbc_db myDB;
   myDB.Connect(Username, mysqlPassword, SchemaName);
   myDB.initDatabase();
 

   string builder = "";
   string query1 = "SELECT * from Result;";

   string GameId = "34";
   string TeamOneId = "NAME";
   string TeamTwoId = "popo";
   string ScoreOne = "ROASTING";
   string ScoreTwo = "popo";
   
   GameId = argv[1];
   TeamOneId= argv[2];
   TeamTwoId = argv[3];
   ScoreOne = argv[4];
   ScoreTwo = argv[5];
  
 
   
   string input = GameId + "," + TeamOneId + "," + TeamTwoId + "," + ScoreOne + ", " + ScoreTwo;               
   myDB.insert("Result", input);    
 
   builder.append("<br><br><br> Result" + myDB.quickquery(query1));
   cout << builder; 
        
   myDB.disConnect();//disconect Database

   return 0;
}


