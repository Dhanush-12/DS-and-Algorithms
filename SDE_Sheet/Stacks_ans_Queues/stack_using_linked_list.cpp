#include<iostream>
using namespace std;
template<typename T>
class Node
{
    public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
};
template<typename T>
class Stack
{
    Node<T> *head;
    int size;
public:
    Stack()
    {
        head=NULL;
        size=0;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size==0;
    }
    void push(int ele)
    {
        Node<T> *n=new Node<T>(ele);
        /*if(head==NULL)
        {
            head=n;
        }*/
        //else
            n->next=head;
            head=n;
            size++;
    }
    void pop()
    {
        if(head==NULL)
        {cout<<"Stack is empty"<<endl;
        return;}
        Node<T> *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        size--;
    }
    T top()
    {
        if(head==NULL)
        {
            return 0;
        }
        return head->data;
    }
};
int main()
{
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(64);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.getsize()<<endl;
    cout<<s.isempty()<<endl;
    return 0;
}
