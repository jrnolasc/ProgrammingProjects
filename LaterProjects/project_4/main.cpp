
#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <vector>
#include "stack.h"
#include "queue.h"
using namespace std;

int main()
{
srand (time(NULL));
  Stack stacks;
  Queue queues;
  int takeout = 0;
  int loop = 0;
  int range = 100;
  int num = 0;
  int add = 0;
  int sub =0;
 
  cout << "Enter Number of iterations: ";
  cin >> loop;
   
for (int i = 0; i < loop; i++)  
{
    num = random() % range;
 
  // cout << num << endl;
     if (random()% 100 < 51)
    {
        stacks.push(num);
        cout << "Push " << num;
        cout <<": ";
        stacks.print();
        cout << endl;
        add++;
    }
    else
    {
         int value =0;
         
         value = stacks.pop();
         cout << "Pop " << value;
         cout << ": ";
         stacks.print();
         cout << endl;
         sub ++;
    }
}
 

  cout << endl;
  cout << "push: " << add << endl;
  cout << "pop: " << sub << endl;
  cout << "vector size: " << stacks.getCount() << endl;
  cout << "Contents: ";
  stacks.print();
  cout << endl;
  cout << endl;


add = 0;
sub = 0;

// clock_t time1=clock();
for (int i = 0; i < loop; i++)  
{
    num = random() % range;
 
  // cout << num << endl;
     if (random()% 100 < 51)
    {
     
      queues.insert(num);
      cout << "Insert " <<  num << ": ";
        queues.print();
        cout << endl;
        add++;
    }
    else
    {
        
      takeout = queues.remove();
        cout << "Remove " << takeout << ": ";
      queues.print();
      cout << endl;
         sub ++;
    }
}
    cout << endl;
    cout << "Insert: " << add <<endl;
    cout << "Remove: " << sub << endl;
    cout << "Vector Size: " << queues.getCount() << endl;
    cout << "Contents: ";
    queues.print();
  
//      clock_t time2=clock();
//   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
// cout	<<	"Run	time:	"	<<	run_time	<<	"	seconds\n";

    return 0;
}
