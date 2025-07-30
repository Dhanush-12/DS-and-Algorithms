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
void levelOrderTraversal(Node* root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* f=q.front();
        ans.push_back(f->data);
        q.pop();
        if(f->left!=NULL)
        {
            q.push(f->left);
        }
        if(f->right!=NULL)
        {
            q.push(f->right);
        }
    }
    return;
}
void inorderTraversal(Node* root, vector<int>&ans)
{
    if(!root) return;
    inorderTraversal(root->left,ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}
void preorderTraversal(Node* root, vector<int>&ans)
{
    if(!root) return;
    ans.push_back(root->data);
    preorderTraversal(root->left,ans);
    preorderTraversal(root->right, ans);
}
void postorderTraversal(Node* root, vector<int>&ans)
{
    if(!root) return;
    postorderTraversal(root->left,ans);
    postorderTraversal(root->right, ans);
    ans.push_back(root->data);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root=takeInput(arr);
    vector<int>ans;
    inorderTraversal(root, ans);
    cout<<"Inorder Traversal: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    ans.clear();
    preorderTraversal(root, ans);
    cout<<"Preorder Traversal: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans.clear();
    postorderTraversal(root, ans);
    cout<<"Postorder Traversal: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans.clear();
    levelOrderTraversal(root, ans);
    cout<<"Levelorder Traversal: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
