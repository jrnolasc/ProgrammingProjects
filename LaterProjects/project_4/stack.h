//-----------------------------------------------------------
//  Purpose:    Definition of the vector based Stack class. 
//  Author:     John Gauch
//-----------------------------------------------------------
#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    Stack();
    ~Stack();
    
    void push(int number);
    int pop();
    int top();
    
    bool isFull();
    bool isEmpty();
    int getCount();
    void print();
    
private:
    int count;
    vector <int> data;
};
#endif