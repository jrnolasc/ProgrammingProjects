#include "UserNode.h"
class UserList
{
 public:
   // Constructors
    UserList();
    UserList(const UserList & param);
   ~UserList();
  
   void Add(string firstname, string lastname, string handle, string number, int messages);
   void Update(string handle);
   void Find();
   void printall();
    
  

 private:
 
  UserNode *Head;
  int Users;
  int TotalMessages;
 
};