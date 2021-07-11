#include "queue.h"

Queue :: Queue()
{
    count = 0;
    back = -1;
    front = 0;
    size = 100;
    data.resize(size);
}
Queue :: ~Queue()
{
    
}
bool Queue :: isFull()
{
    return (count >= size);
}
bool Queue :: isEmpty()
{
    return (count <= 0);
}
void Queue :: insert(int number)
{
    if(!isFull())
    {
        // cout << "back = " << back << endl;
       back = (back + 1) % size;
        data[back] = number;
      // cout << "Back " << data[back] << endl;
        count++;
        //cout << "Size: " << size << endl;
    }
    else 
        cout << "Wrapping data." << endl;
    
}
int Queue :: remove()
{
    if (!isEmpty())
    {
        int number = data[front];
         front = (front + 1)%size;
       // cout << "Front: " << data[front] << endl;
        count--;
        
        return number;
    }
    
    return -1;
}
int Queue :: getCount()
{
    return count;
}
void Queue :: print()
{
    int pos = front;
        for (int i =0; i<count; i++)
        {
            cout << data[pos] << ' ';
            pos = (pos + 1) % size;
        }
}