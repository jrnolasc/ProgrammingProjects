//-----------------------------------------------------------
//  Purpose:    Definition of the vector based Queue class. 
//  Author:     John Gauch
//-----------------------------------------------------------
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <vector>
using namespace std;

class Queue
{
public:
    Queue();
    ~Queue();
    
    void insert(int number);
    int remove();
    
    bool isFull();
    bool isEmpty();
    int getCount();
    void print();
    
private:
    int size;
    int count;
    int front;
    int back;
    vector <int> data;
};
#endif