
#include <stdio.h>

#include "UserList.h"

void Dialog()
{
    
    cout << "A: Add a user" << endl;
    cout << "E: To exit Grouup MEE"<< endl;
    cout << "U: To Update User"<< endl;
    cout << "F: To Find Most Messages"<< endl;
    cout << "P: To Print " << endl;
}
void menu()
{
    char input;
    string firstname;
    string lastname;
    string handle;
    string number;
    int messages;
    UserList User;
    
    cout << "Welcome to Grouup MEE" << endl;
    Dialog();
    cin >> input;

 while ((input != 'e') && (input != 'E'))
 {
   
        if ((input == 'a') || (input == 'A'))
        {
            //cout << "adding " << endl;
            cout << endl << "Enter First Name: " << endl;
            cin >> firstname;
            cout << "Enter Last Name: " << endl;
            cin >> lastname;
            cout << "Enter Handle: " << endl;
            cin >> handle;
            cout << "Enter Phone Number: "<< endl;
            cin >> number;
            User.Add (firstname, lastname, handle, number, 0);  
            cout << endl << "What would you like to do"<< endl;
            Dialog();
            cin >> input;
        }
        else if ((input == 'U') || (input == 'u'))
        {
            cout << "Enter the UserHandle: ";
            cin >> handle;
            User.Update(handle);
            cout << endl << "What would you like to do"<< endl;
            Dialog();
            cin >> input;
        }
        else if ((input == 'p') || (input == 'P'))
        {
            User.printall();
            cout << endl << "What would you like to do"<< endl;
            Dialog();
            cin >> input;
        }
        else if ((input == 'F') || (input == 'f'))
        {
            User.Find();
            cout << endl << "What would you like to do"<< endl;
            Dialog();
            cin >> input;
        }
        else {
            cout << endl << "Please enter a real input" << endl;
            cin >> input;
        }    
 }   

    cout << "closing Grouup MEE" << endl;
}


int main()
{
    menu();
    return 0;
}
