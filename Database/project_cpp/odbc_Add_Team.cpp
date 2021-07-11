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
   string query1 = "SELECT * from Teams;";
   
   string TeamId = "34";
   string University_Name = "NAME";
   string Nickname = "popo";
   string Rank = "ROASTING";

   
  // TeamId = argv[1];
   University_Name = argv[1];
   Nickname= argv[2];
   Rank= argv[3];
 
   // Insert the new Team
   string input = "'" + University_Name + "'" + ",'" + Nickname + "','" + Rank + "'";               
   myDB.insert2("Teams", input);    
 
  
   builder.append("<br><br><br>Teams:" + myDB.query(query1));
   cout << builder; 
       
   myDB.disConnect();//disconect Database

   return 0;
}


