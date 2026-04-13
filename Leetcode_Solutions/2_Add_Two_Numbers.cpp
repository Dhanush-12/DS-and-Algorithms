#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int data;
    ListNode* next;
    ListNode(int n)
    {
        data = n;
        next = NULL;
    }
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        int carry = 0;
        while(l1 && l2)
        {
            int sum = l1->data + l2->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            head->next = new ListNode(digit);;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int sum = l1->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            head->next = new ListNode(digit);
            head = head->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int sum = l2->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            head->next = new ListNode(digit);;
            head = head->next;
            l2 = l2->next;
        }
        if(carry)
        {
            head->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
ListNode* createList(vector<int>&arr)
{
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i=1;i<arr.size();i++)
    {
        ListNode* n = new ListNode(arr[i]);
        temp->next = n;
        temp = temp->next;
    }
    return head;
}
void printList(ListNode* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>num1(n), num2(m);
    for(int i=0;i<n;i++) cin>>num1[i];
    for(int i=0;i<m;i++) cin>>num2[i];
    ListNode* head1 = createList(num1);
    ListNode* head2 = createList(num2);
    Solution s;
    ListNode* ans = s.addTwoNumbers(head1, head2);
    printList(ans);
}
