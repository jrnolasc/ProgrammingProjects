#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;



class UserNode
{
 public:
   // Constructors
    UserNode();
    UserNode(string firstname, string lastname, string handle, string number, int messages);
    UserNode(const UserNode & param);
   ~UserNode();
  
     void print();
   // Get methods
    string getFirstName();
    string getLastName();
    string getHandle();
    string getNumber();
    int getMessageCount();
    UserNode *getNext();
    
   // Set methods
    void setFirstName(const string firstname);
    void setLastName(string lastname);
    void setHandle(string handlename);
    void setNumber(string number);
    void setMessageCount(int messagecount);
    void setNext(UserNode *next);
    UserNode *Next;
 private:
    string FirstName;
    string LastName;
    string Handle;
    string Number;
    int MessageCount;
  
 
 
};