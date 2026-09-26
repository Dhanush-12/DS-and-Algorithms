#include <iostream>
#include <stack>
using namespace std;
// Using an Auxiliary Stack - O(1) Time and O(n) Space
class SpecialStack1 {
    stack<int> st; 
    stack<int> minStack; 

public:
    void push(int x) {
        st.push(x);
        
        // If the minStack is empty or the new element is smaller than 
        // the top of minStack, push it onto minStack
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            
            // Otherwise, push the top element of minStack 
            // again to keep the minimum unchanged
            minStack.push(minStack.top());
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (st.empty()) {
            return;
        }
        
        // Pop from both stacks
        st.pop();
        minStack.pop();
    }

    // Return the top element of the stack without removing it
    int peek() {
        if (st.empty()) {
            return -1;
        }
        return st.top();
    }

    // Get the minimum element in the stack
    int getMin() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.top();
    }
};

// Using a Pair in Stack - O(1) Time and O(n) Space
class SpecialStack2 {
private:
    stack<pair<int, int>> st;

public:
    SpecialStack2() {
    }
    
    // Add an element to the top of stack
    void push(int x) {
        int newMin = st.empty() ? x : min(x, st.top().second);
        st.push({x, newMin});
    }
    
    // Remove the top element from the stack
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    // Return top element of the stack
    int peek() {
        if (st.empty()) {
            return -1;
        }
        return st.top().first;
    }
    
    // Find minimum element of the stack
    int getMin() {
        if (st.empty()) {
            return -1;
        }
        return st.top().second;
    }
};

// Without Extra Space- O(1) Time and O(1) Space
/*
The idea is to use a variable minEle to track the minimum element in the stack. Instead of
storing the actual value of minEle in the stack, we store a modified value when pushing an
element smaller than minEle.

Push(x)

If the stack is empty, push x and set minEle = x.
If x >= minEle, push x normally.
If x < minEle, push 2*x - minEle and update minEle = x (this encodes the previous min).
Pop()

Remove the top element.
If the removed element is >= minEle, no change in minEle.
If the removed element is < minEle, update minEle = 2*minEle - top (decoding the previous min).
Peek()

Returns minEle if the top is modified (encoded) or top otherwise.
getMin()

Returns minEle, the current minimum in O(1) time.
How this approach works?
When the element to be inserted is less than minEle, we insert "2x - minEle". The important
thing to note is, that 2x - minEle will always be less than x (proved below), i.e., new minEle
and while popping out this element we will see that something unusual has happened as the popped
element is less than the minEle. So we will be updating minEle.

How 2*x - minEle is less than x in push()? 

x < minEle which means x - minEle < 0 

// Adding x on both sides
x - minEle + x < 0 + x 
2*x - minEle < x 
We can conclude 2*x - minEle < new minEle 

While popping out, if we find the element(y) less than the current minEle, we find the new
minEle = 2*minEle - y

How previous minimum element, prevMinEle is, 2*minEle - y
in pop() is y the popped element?

// We pushed y as 2x - prevMinEle. Here 
// prevMinEle is minEle before y was inserted

y = 2*x - prevMinEle  

// Value of minEle was made equal to x
minEle = x 

new minEle = 2 * minEle - y = 2*x - (2*x - prevMinEle) = prevMinEle // This is what we wanted
*/
class SpecialStack {
private:
    stack<int> st;
    int minEle;
    
public:
    SpecialStack() {
        minEle = -1;
    }
    
    // Add an element to the top of stack
    void push(int x) {
        if (st.empty()) {
            minEle = x;
            st.push(x);
        }
        // If new number is less than minEle
        else if (x < minEle) {
            st.push(2 * x - minEle);
            minEle = x;
        }
        else {
            st.push(x);
        }
    }
    
    // Remove the top element from the stack
    void pop() {
        if (st.empty()) return;
        
        int top = st.top();
        st.pop();
        
        // Minimum will change if min element is removed
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }
    
    // Return top element of the stack
    int peek() {
        if (st.empty()) return -1;

        int top = st.top();
        return (minEle > top) ? minEle : top;
    }
    
    // Return minimum element of the stack
    int getMin() {
        if (st.empty()) return -1;
        return minEle;
    }
};

int main() {
    SpecialStack st;
    
    st.push(18);
    st.push(19);
    st.push(29);
    st.push(15);
    st.push(16);

    cout << st.getMin() << endl;

    return 0;
}