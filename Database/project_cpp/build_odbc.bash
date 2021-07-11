#!/bin/bash
set -e -v

g++ -Wall -o hello.exe hello.cpp
g++ -c odbc_Add_Team.cpp
g++ -c odbc_Add_Game.cpp
g++ -c odbc_ViewAll_Teams.cpp
g++ -c odbc_View_Team_Results.cpp
g++ -c odbc_View_Date_Results.cpp
g++ -c odbc_Add_Result.cpp
g++ -c odbc_View_Team_Wins.cpp
g++ -c odbc_db.cpp
g++ -Wall -I/usr/include/cppconn -o odbc_Add_Team.exe odbc_Add_Team.o odbc_db.o -L/usr/lib -lmysqlcppconn
g++ -Wall -I/usr/include/cppconn -o odbc_Add_Game.exe odbc_Add_Game.o odbc_db.o -L/usr/lib -lmysqlcppconn
g++ -Wall -I/usr/include/cppconn -o odbc_ViewAll_Teams.exe odbc_ViewAll_Teams.o odbc_db.o -L/usr/lib -lmysqlcppconn
g++ -Wall -I/usr/include/cppconn -o odbc_View_Team_Results.exe odbc_View_Team_Results.o odbc_db.o -L/usr/lib -lmysqlcppconn
g++ -Wall -I/usr/include/cppconn -o odbc_View_Date_Results.exe odbc_View_Date_Results.o odbc_db.o -L/usr/lib -lmysqlcppconn
g++ -Wall -I/usr/include/cppconn -o odbc_Add_Result.exe odbc_Add_Result.o odbc_db.o -L/usr/lib -lmysqlcppconn
g++ -Wall -I/usr/include/cppconn -o odbc_View_Team_Wins.exe odbc_View_Team_Wins.o odbc_db.o -L/usr/lib -lmysqlcppconn
