#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
using namespace std;

// asks user for country and print the right suppliers and coffee
void SupplierByCountry(string Country)
{
    cout << "SupplierByCountry" <<endl;
    cout << "Country: "<<Country << endl;
    
    string enter = "yes seer = " + Country;
    cout << enter;
}

// add user by entering supplier name number and country 
void AddSupplier(string SupplierName, string PhoneNumber, string Country)
{
     cout << "AddSupplier" <<endl;
     cout << "Supplier Name: " << SupplierName << "Phone Number: " << PhoneNumber << "Country: " << Country << endl; 
}

//ask the user for the name and print items they sold
void EmployeePermoramnce(string EmployeeName)
{
    cout << "EmployeePermoramnce" <<endl;
    cout << "Employee Name: " << endl;
    
}

//ask for item name 
void UpdateItem(string ItemName)
{
    cout << "UpdateItem" <<endl;
    cout << "Item Name: " << ItemName << endl;
}

//enter Transaction Id 
void CancelSales(string TransactionId)
{
    cout << "CancelSales" <<endl;
    cout << "Transaction Id: " << TransactionId << endl;
}



void Dialog()
{

    cout << "1) Supplier By Country" << endl;
    cout << "2) Add Supplier" << endl;
    cout << "3) Employee Permoramnce" << endl;
    cout << "4) Update Item" << endl;
    cout << "5) Cancel Sales" << endl;
    cout << "6) Quit" << endl;
}

int main()
{
  string input;
  string CountryName;
  string SupplierName;
  string PhoneNumber;
  string EmployeeName;
  string Item;
  string TransactionId;
  
  Dialog();
  cin >> input;
  
  while (input != "6")
  {
      if (input == "1")
      {
        cout << "Enter Country Name" << endl;
        cin >> CountryName;
        SupplierByCountry(CountryName);
        
        cout << endl;
        Dialog();
        cin >> input;
      }
      else if (input =="2")
      {
          string Confirm;
          
          while (Confirm != "y" && Confirm != "Y")
          {
            cout << "Enter Supplier Name: "<< endl;
            cin >> SupplierName;
            cout << "Enter Supplier Phone Number: "<< endl;
            cin >> PhoneNumber;
            cout << "Enter Item Supplier Provides: " << endl;
            cin >> Item;
            
            cout << " To Confirm: "<< endl;
            cout << "Supplier Name: " << SupplierName <<endl;
            cout << "Supplier Phone Number: " << PhoneNumber << endl;
            cout << "Supplier Item: " << Item << endl;
            cout << "Does this look correct y/n..."<< endl;
            cin >> Confirm;
          }
          
          
          AddSupplier(SupplierName, PhoneNumber, Item);
          
          cout << endl;
          Dialog();
          cin >> input;
      }
      else if (input == "3")
      {
          cout << "Enter Employee Name: " << endl;
          cin >> EmployeeName;
          
          EmployeePermoramnce(EmployeeName);
          
          cout << endl;
          Dialog();
          cin >> input;
      }
      else if (input == "4")
      {
          cout << "Enter Item Name: " << endl;
          cin >> Item;
          
          UpdateItem(Item);
          
          cout << endl;
          Dialog();
          cin >> input;
      }
      else if (input == "5")
      {
          cout << "Enter Transaction Id: " << endl;
          cin >> TransactionId;
          
          CancelSales(TransactionId);
          
          cout << endl;
          Dialog();
          cin >> input;
          
      }
      else {
          cout << endl << "Please Enter A Valid Value: " << endl;
          cin >> input;
      }
      
  }
  cout << "Now Quitting..."<< endl;
  

    return 0;
    
}
g++ -Wall -I /usr/include/cppconn Test.cpp -L /usr/lib -l mysqlcppconn -o odbc_example.exe

