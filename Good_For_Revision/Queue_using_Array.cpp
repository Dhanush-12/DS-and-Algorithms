#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Implement a Queue using an Array, where the size of the array, n is given.
    The Queue must support the following operations:

    (i) enqueue(x): Insert an element x at the rear of the queue.
    (ii) dequeue(): Remove the element from the front of the queue.
    (iii) getFront(): Return front element if not empty, else -1.
    (iv) getRear(): Return rear element if not empty, else -1.
    (v) isEmpty(): Return true if the queue is empty else return false.
    (vi) isFull(): Return true if the queue is full else return false.

    There will be a sequence of queries queries[][]. The queries are represented in numeric form:

    1 x : Call enqueue(x)
    2: Call dequeue()
    3: Call getFront()
    4: Call getRear()
    5: Call isEmpty()
    6: Call isFull()
    You just have to implement the functions enqueue, dequeue, getFront, getRear, isEmpty and isFull and the driver code will handle the output.

    Input: n = 3, q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]
    Output: [5, false, 4]

    Input: n = 2, q = 4, queries[][] = [[4], [1, 3], [1, 7], [6]]
    Output: [-1, true]
*/
class myQueue {
    vector<int> arr;
    int capacity;
    int sz;
    int ind = 0;
  public:
    myQueue(int n) {
        // Define Data Structures
        capacity = n;
        sz = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return (sz == 0);
    }

    bool isFull() {
        // check if the queue is full
        return (sz == capacity);
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        arr.push_back(x);
        sz++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        ind++;
        sz--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(sz == 0) return -1;
        return arr[ind];
    }

    int getRear() {
        // Return the last element of queue
        if(sz == 0) return -1;
        return arr.back();
    }
};
int main()
{
   int n,q;
   cin>>n>>q;
   myQueue mq(n);
   for(int i=0;i<q;i++)
   {
      int ch;
      cin>>ch;
      if(ch == 1)
      {
         int x;
         cin>>x;
         mq.enqueue(x);
      }
      else if(ch == 2)
      {
         mq.dequeue();
      }
      else if(ch == 3)
      {
         cout<<mq.getFront()<<endl;
      }
      else if(ch == 4)
      {
         cout<<mq.getRear()<<endl;
      }
      else if(ch == 5)
      {
         cout<<mq.isEmpty()<<endl;
      }
      else if(ch == 6)
      {
         cout<<mq.isFull()<<endl;
      }
   }
}
