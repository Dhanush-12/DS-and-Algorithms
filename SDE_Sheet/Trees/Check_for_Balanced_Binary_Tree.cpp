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
// A Balanced Binary Tree is a tree in which for every node, the height of leftSubTree is equal to the height of rightSubTree.
int dfsHeight(Node* root)
{
    if(!root) return 0;
    int leftH=dfsHeight(root->left);
    if(leftH == -1) return -1;
    int rightH = dfsHeight(root->right);
    if(rightH == -1) return -1;

    if(abs(leftH-rightH) > 1) return -1;
    return max(leftH,rightH) + 1;
}
bool checkBalancedBinaryTree(Node* root)
{
    return dfsHeight(root) != -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root=takeInput(arr);
    if(checkBalancedBinaryTree(root))
    {
        cout<<"Given Tree is a Balanced Binary Tree"<<endl;
    }
    else
    {
        cout<<"Given Tree is not a Balanced Binary Tree"<<endl;
    }
}
/*
11
3 9 20 -1 -1 15 7 -1 -1 -1 -1

15
1 3 2 5 4 -1 -1 7 6 -1 -1 -1 -1 -1 -1
*/
