#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Implement a Stack using Queue data structure, this stack has no fixed capacity and can grow dynamically until memory is
   available. The Stack must support the following operations:

   (i) push(x): Insert an element x at the top of the stack.
   (ii) pop(): Remove the element from the top of the stack, if stack is empty do nothing.
   (iii) top(): Return top element if not empty, else -1.
   (iv) size(): Return the number of elements currently in the stack.

   There will be a sequence of queries queries[][]. The queries are represented in numeric form:

   1 x: Call push(x)
   2: Call pop()
   3: Call top()
   4: Call size()
   You just have to implement the functions push, pop, top and size. The driver code will handle the input and output.

   Input: q = 6, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [4]]
   Output: [4, 2]

   Input: q = 4, queries[][] = [[4], [3], [1, 10], [3]]
   Output: [0, -1, 10]
*/
class myStack {
    queue<int> q;

  public:

    void push(int x) {
        // Inserts an element x at the top of the stack
        if(q.empty())
        {
            q.push(x);
            return;
        }
        queue<int> temp;
        while(!q.empty())
        {
            temp.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
        return;
    }

    void pop() {
        // Removes an element from the top of the stack
        if(q.empty()) return;
        q.pop();
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q.empty()) return -1;
        return q.front();
    }

    int size() {
        // Returns the current size of the stack
        return q.size();
    }
};
int main()
{
   int n;
   cin>>n;
   myStack s;
   for(int i=0;i<n;i++)
   {
      int q;
      cin>>q;
      if(q == 1)
      {
         int x;
         cin>>x;
         s.push(x);
      }
      else if(q == 2)
      {
         s.pop();
      }
      else if(q == 3)
      {
         cout<<s.top()<<endl;
      }
      else if(q == 4)
      {
         cout<<s.size()<<endl;
      }
   }
}
