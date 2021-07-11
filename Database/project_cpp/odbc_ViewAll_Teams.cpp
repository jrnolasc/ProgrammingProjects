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
   string query1 = "SELECT * from Teams order by Rank ASC;";
   builder.append("<br><br><br> All Teams:" + myDB.quickquery(query1) +"<br>");
   cout << builder; 
       
   myDB.disConnect();

   return 0;
}


