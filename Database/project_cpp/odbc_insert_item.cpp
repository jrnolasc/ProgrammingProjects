/* Compile using:
g++ -Wall -I/usr/include/cppconn -o odbc odbc_insert_restaurant.cpp -L/usr/lib -lmysqlcppconn 
run: 
./odbc */
#include "odbc_db.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
string Username = "jrnolasc";            // Change to your own username
string mysqlPassword = "aiK5usei";  // Change to your mysql password
string SchemaName = "jrnolasc";          // Change to your username

   odbc_db myDB;
   myDB.Connect(Username, mysqlPassword, SchemaName);
   myDB.initDatabase();
 
   // For debugging purposes:  Show the database before insert
   string builder = "";
   string query1 = "SELECT * from ITEM;";
   builder.append("<br><br><br> ITEM table before:" + myDB.query(query1) +"<br>");
 
   // Parse input string to get restaurant Name and Type and  City
   string ID = "34";
   string name = "NAME";
   string price_per_lb = "PRICE_PER_LB";
   string roasting = "ROASTING";

   // Read command line arguments
   // First arg, arg[0] is the name of the program
   // Next args are the parameters
   name = argv[1];
   price_per_lb = argv[2];
   roasting = argv[3];
 
   // Insert the new restaurant
   string input = ID + ",'" + name + "','" + price_per_lb + "','" + roasting + "'";               
   myDB.insert("ITEM", input);    // insert new restaurant
 
   //For debugging purposes: Show the database after insert
   builder.append("<br><br><br> Table ITEM after:" + myDB.query(query1));
   cout << builder; 
       
   myDB.disConnect();//disconect Database

   return 0;
}


