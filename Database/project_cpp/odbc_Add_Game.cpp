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
   string query1 = "SELECT * from Games;";

   string GameId = "34";
   string Rank1 = "NAME";
   string Rank2 = "popo";
   string Location = "ROASTING";
   string Date = "popo";
   

 
  
   Rank1= argv[1];
   Rank2= argv[2];
   Location= argv[3];
   Date= argv[4];
  
 
  
   string input = Rank1 + ",'" + Rank2+ "','" + Location + "', STR_TO_DATE('" + Date + "','%Y-%m-%d')";               
   myDB.insert3("Games", input);   
 
   
   builder.append("<br><br><br> Games:" + myDB.quickquery(query1));
   cout << builder; 
       
   myDB.disConnect();//disconect Database

   return 0;
}


