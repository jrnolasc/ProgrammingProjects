#include "UserList.h"



UserList :: UserList()
{
   // cout << "const" << endl;
    Head = NULL;
    Users = 0;
    TotalMessages = 0;
}

UserList :: UserList(const UserList & param)
{
    //cout << "copy" << endl;
    
    UserNode *copy = new UserNode();
    Head = copy;
    
    UserNode *ptr = param.Head;
    while (ptr != NULL)
    {
        copy ->setNext(new UserNode());
        copy = copy ->getNext();
        copy ->setFirstName(ptr ->getFirstName());
        copy ->setLastName(ptr ->getLastName());
        copy ->setHandle(ptr ->getHandle());
        copy ->setNumber(ptr ->getNumber());
        copy ->setMessageCount(ptr ->getMessageCount());
        copy ->setNext(NULL);
        ptr = ptr ->getNext();
    }
  
    copy = Head;
    Head = copy ->getNext();
    delete copy;
}

UserList :: ~UserList()
{
    //cout << "decon" << endl;
      
       while (Head != NULL)
   {
      UserNode *ptr = Head;
      Head = Head->Next;
      delete ptr;
   }
}
void UserList::Add(string firstname, string lastname, string handle, string number, int messages)
{
 //cout << "adding" << endl;
  UserNode *ptr = Head;
  Users++;
        cout << endl << "Total Users: " << Users  << endl;
  while ((ptr !=NULL) && (ptr ->getNext() !=NULL))
    ptr = ptr->getNext();
    
    if(ptr !=NULL)
    {
        ptr ->setNext(new UserNode(firstname, lastname, handle, number, messages));
    }
    else 
        Head = new UserNode(firstname, lastname, handle, number, messages);
}
void UserList::Update(string handle)
{
   UserNode *ptr = Head;
   TotalMessages ++;
   
    while ((ptr !=NULL) && (ptr -> getHandle() != handle))
    {
        ptr = ptr ->getNext();
    }
 
     if (ptr != NULL)
     {
      ptr->setMessageCount(1 + ptr->getMessageCount());
      ptr ->print();
     }
     else {
         cout << endl << "No User Found" << endl;
         TotalMessages --;
     }

    cout << endl << "Total Messages: " << TotalMessages << endl;
}
void UserList::Find()
{
    UserNode *max = Head;
   UserNode *ptr = Head;
   
   while (ptr != NULL)
   {
      if (ptr->getMessageCount() > max->getMessageCount())
	 max = ptr;
      ptr = ptr->getNext();
   }

   // Print node with max score
   if (max != NULL)
      max->print();
      
}
void UserList::printall()
{
      UserNode *ptr = Head;
   while (ptr != NULL)
   {
      ptr->print();
      ptr = ptr->getNext();
   }
}


