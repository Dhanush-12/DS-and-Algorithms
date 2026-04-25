#include<bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode* next;

    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};
ListNode* buildList(vector<int> &arr)
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
}
class Solution {
    int lengthOfList(ListNode* root)
    {
        int ans = 0;
        while(root)
        {
            ans++;
            root=root->next;
        }
        return ans;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int st = lengthOfList(head)-n;
        if(st == 0) return head->next;
        ListNode* temp = head;
        int ind = 0;
        while(temp && ind < (st-1))
        {
            temp = temp->next;
            ind++;
        }
        temp->next = temp->next->next;
        return head;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    ListNode* root = buildList(arr);
    int k;
    cin>>k;
    Solution s;
    ListNode* ans = s.removeNthFromEnd(root, k);
    printList(ans);
}
