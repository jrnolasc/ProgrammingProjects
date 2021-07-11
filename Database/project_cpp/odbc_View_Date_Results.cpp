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
   string Dates = "";
   Dates = argv[1];
  
	string query2 = "select Games.Date, T1.University_Name as Team_One, \
	T2.University_Name AS Team_Two, Games.Location, R1.ScoreOne AS Team_One_Score, \
	R1.ScoreTwo AS Team_Two_Score, IF (R1.ScoreOne > R1.ScoreTwo, T1.University_Name, \
	T2.University_Name) AS Winning_Team FROM Result R1 JOIN Teams T1 on T1.TeamId = \
	R1.TeamOneId JOIN Teams T2 on  T2.TeamId = R1.TeamTwoId JOIN Games on Games.GameId = \
	R1.GameId WHERE Games.Date = '" + Dates + "';";
 	myDB.query(query2);
 	
 	
  	builder.append("<br><br><br> Results by the date '" + Dates + "':" + myDB.quickquery(query2) + "<br>");
  	cout << builder;

        
   myDB.disConnect();//disconect Database

   return 0;
}


