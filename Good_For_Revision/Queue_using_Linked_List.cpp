#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Implement a Queue using a Linked List, this queue has no fixed capacity and can grow dynamically until memory is available.
   The Queue must support the following operations:

   (i) enqueue(x): Insert an element x at the rear of the queue.
   (ii) dequeue(): Remove the front element from the queue. If the queue is empty, do nothing.
   (iii) getFront(): Return front element if not empty, else -1.
   (iv) isEmpty(): Return true if the queue is empty else return false.
   (v) size(): Return the number of elements currently in the queue.

   There will be a sequence of queries queries[][]. The queries are represented in numeric form:

   1 x : Call enqueue(x)
   2: Call dequeue()
   3: Call getFront()
   4: Call isEmpty()
   5: Call size()
   You just have to implement the functions enqueue, dequeue, getFront,  isEmpty and size. The driver code will handle the input and output.

   Input: q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]
   Output: [5, 2, false]

   Input: q = 4, queries[][] = [[4], [3], [1, 10], [5]]
   Output: [true, -1, 1]
*/
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {
    Node* curr;
    Node* iter;
    int sz = 0;
  public:
    myQueue() {
        // Initialize your data members
        curr = NULL;
        iter = NULL;
        sz = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return !sz;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* n = new Node(x);
        if(curr == NULL)
        {
            curr = n;
            iter = n;
            sz += 1;
            return;
        }
        iter->next = n;
        iter = iter->next;
        sz += 1;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(sz == 0) return;
        curr = curr->next;
        sz -= 1;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(sz == 0) return -1;
        return curr->data;
    }

    int size() {
        // Returns the current size of the queue.
        return sz;
    }
};
int main()
{
   int q;
   cin>>q;
   myQueue mq;
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
         cout<<mq.isEmpty()<<endl;
      }
      else if(ch == 5)
      {
         cout<<mq.size()<<endl;
      }
   }
}
