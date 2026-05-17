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
int maximumPathSum(Node* root, int &maxi)
{
    if(root==NULL) return 0;
    int leftSum=maximumPathSum(root->left, maxi);
    int rightSum=maximumPathSum(root->right, maxi);

    maxi=max(maxi, leftSum+rightSum+root->data);

    return root->data+max(leftSum,rightSum);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root=takeInput(arr);
    int ans=INT_MIN;
    maximumPathSum(root, ans);
    cout<<ans<<endl;
}
/*
11
-10 9 20 -1 -1 15 7 -1 -1 -1 -1
Answer: 42
*/
