#include "stack.h"

Stack::Stack()
{
    count = 0;
}

Stack :: ~Stack()
{
    
}
bool Stack :: isFull()
{
    //cout << "IsFull" << endl;
    return(false);
}
bool Stack :: isEmpty()
{
   // cout << "Is Empty" << endl;
    
    return (count == 0);
}
void Stack :: push(int number)
{
   // cout << "Push" << endl;
    data.push_back(number);
    count ++;
}
int Stack :: pop()
{
    int num = 0;
   // cout << "Pop" << endl;
  
     if (!isEmpty())
     {
       num = data.back();
        data.pop_back();
        count --;    
        return num;
     }
   
        
} 
int Stack :: top()
{
   // cout << "Top" << endl;
   int top = 0;
   
   top = data.back();
    cout << "Top: " <<  data.back() << endl;
    
    return top;
}

int Stack :: getCount()
{
   // cout << "Get Count" << endl;
    return count;
}
void Stack :: print()
{
  //  cout << "print" << endl;
   
   for (int i = 0; i<count; ++i)
   {
       cout << data[i] << ' ';
   }
   
}