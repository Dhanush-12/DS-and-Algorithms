#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node* takeInput(vector<int>&arr)
{
    int n=(int)arr.size();
    queue<Node*>q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i=1;
    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        if(i<n && arr[i] != -1)
        {
            Node* n = new Node(arr[i]);
            curr->left=n;
            q.push(n);
        }
        i++;
        if(i<n && arr[i] != -1)
        {
            Node* n = new Node(arr[i]);
            curr->right=n;
            q.push(n);
        }
        i++;
    }
    return root;
}
int maximumDepthOfBinaryTree_Recursion(Node* root)
{
    if(!root) return 0;
    return 1+max(maximumDepthOfBinaryTree_Recursion(root->left), maximumDepthOfBinaryTree_Recursion(root->right));
}
int maximumDepthOfBinaryTree_levelOrderTraversal(Node* root)
{
    if(!root) return 0;
    int cnt=1;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=(int)q.size();
        int f=0;
        for(int i=0;i<n;i++)
        {
            Node* curr = q.front();
            q.pop();
            if(curr->left)
            {
                f=1;
                q.push(curr->left);
            }
            if(curr->right)
            {
                f=1;
                q.push(curr->right);
            }
        }
        if(f) cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root=takeInput(arr);
    cout<<maximumDepthOfBinaryTree_Recursion(root)<<endl;
    cout<<maximumDepthOfBinaryTree_levelOrderTraversal(root)<<endl;
}
/*
11
1 2 7 3 4 -1 -1 -1 -1 5 6

11
1 2 3 -1 -1 4 6  5 -1  -1 -1
*/
