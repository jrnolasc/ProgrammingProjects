
#include "UserNode.h"


UserNode :: UserNode()
{
   // cout << "const" << endl;
    FirstName = "";
    LastName = "";
    Handle = "";
    Number = "";
    MessageCount = 0;
    Next = NULL;
}

UserNode :: UserNode(string firstname, string lastname, string handle, string number, int messages)
{
    FirstName = firstname;
    LastName = lastname;
    Handle = handle;
    Number = number;
    MessageCount = messages;
    Next = NULL;
}
UserNode :: UserNode(const UserNode & param)
{
  //  cout << "copy" << endl;

    FirstName = param.FirstName;
    LastName = param.LastName;
    Handle = param.Handle;
    Number = param.Number;
    MessageCount = param.MessageCount;
    Next = param.Next;
}

UserNode :: ~UserNode()
{

}

void UserNode::setFirstName(const string firstname)
{
  //  cout << "set name" << endl;
    FirstName = firstname;
}
void UserNode::setLastName(string lastname)
{
   // cout<<"set last name" << endl;
    LastName = lastname;
}
void UserNode::setHandle(string handle)
{
   // cout << "set handle" << endl;
    Handle = handle;
}
void UserNode::setNumber(string number)
{
  //  cout << "Set Number" << endl;
    Number = number; 
}
void UserNode::setMessageCount(int messagecount)
{
   // cout << "Set messagecount" << endl;
    MessageCount = messagecount;
}
void UserNode::setNext(UserNode * next)
{
 // cout << "setNext" << endl;
    Next = next;
}

string UserNode::getFirstName()
{
   // cout << "get name" << endl;
    return FirstName;
}
string UserNode::getLastName()
{
  //  cout<<"get last name" << endl;
    return LastName;
}
string UserNode::getHandle()
{
   // cout << "get handle" << endl;
    return Handle;
}
string UserNode::getNumber()
{
   // cout << "get Number" << endl;
    return Number;
}
int UserNode::getMessageCount()
{
  //  cout << "get messagecount" << endl;
    return MessageCount;
}
UserNode *UserNode::getNext()
{
  // cout << "getNext" <<endl;
    return Next;
}

void UserNode::print()
{
    cout <<"First Name: "<<  FirstName << endl;
    cout <<"Last Name: "<<  LastName << endl;
    cout <<"Handle: "<< Handle << endl;
    cout <<"Number: " << Number << endl;
    cout <<"MessageCount: " << MessageCount << endl;
}