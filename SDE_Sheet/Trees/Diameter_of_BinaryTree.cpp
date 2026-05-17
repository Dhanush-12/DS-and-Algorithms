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
int height(Node* root, int &ans)
{
    if(!root) return 0;
    int lh = height(root->left, ans);
    int rh = height(root->right, ans);
    ans=max(ans,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(Node* root)
{
    int ans=0;
    height(root, ans);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root=takeInput(arr);
    cout<<"Diameter of the Binary Tree is: "<<diameterOfBinaryTree(root)<<endl;
}
/*
11
1 2 3 4 5 -1 -1 -1 -1 -1 -1

19
1 2 3 -1 -1 4 6 5 -1 -1 7 9 -1 -1 8 -1 -1 -1 -1
*/
