
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
   string TeamName = "";

  
   TeamName = argv[1];

	
	string query2 = "select IF (T1.University_Name = '" + TeamName + "', \
	T1.University_Name, T2.University_Name) AS Team_Name, IF(T1.University_Name = \
	'" + TeamName + "',  T1.Nickname, T2.Nickname) AS Team_Nickname, IF \
	(T1.University_Name = '" + TeamName + "', T2.University_Name, T1.University_Name) AS \
	Opponent, Games.Date, IF (T1.University_Name = '" + TeamName + "', R1.ScoreOne, \
	R1.ScoreTwo) Team_Score, IF (T1.University_Name = '" + TeamName + "', R1.ScoreTwo, \
	R1.ScoreOne) Opponent_Score, IF (R1.ScoreOne > R1.ScoreTwo, T1.University_Name, \
	T2.University_Name) AS Winning_Team FROM Result R1 JOIN Teams T1 on T1.TeamId = \
	R1.TeamOneId JOIN Teams T2 on  T2.TeamId = R1.TeamTwoId JOIN Games on Games.GameId = \
	R1.GameId WHERE T1.University_Name = '" + TeamName + "' OR T2.University_Name = \
	'" + TeamName + "';";
	

   builder.append("<br><br><br> Results by Team '" + TeamName + "':" + myDB.quickquery(query2) + "<br>");
   cout << builder; 
   

       
   myDB.disConnect();//disconect Database

   return 0;
}


