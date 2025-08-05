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
void print(Node* root)
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
        cout<<f->data<<' ';
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
void preorderTraversalRecursive(Node* root, vector<int>&ans)
{
    if(!root) return;
    ans.push_back(root->data);
    preorderTraversalRecursive(root->left,ans);
    preorderTraversalRecursive(root->right, ans);
}
void preorderTraversalIterative(Node* root, vector<int>&ans)
{
    if(!root) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right)
        {
            st.push(root->right);
        }
        if(root->left)
        {
            st.push(root->left);
        }
    }
    return;
}
void postorderTraversal(Node* root, vector<int>&ans)
{
    if(!root) return;
    postorderTraversal(root->left,ans);
    postorderTraversal(root->right, ans);
    ans.push_back(root->data);
}
void levelOrderTraversal(Node* root,vector<vector<int>>&ans)
{
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int sz=(int)q.size();
        vector<int>level;
        for(int i=0;i<sz;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    return;
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
    preorderTraversalRecursive(root, ans);
    cout<<"Preorder Traversal recursive: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans.clear();
    preorderTraversalIterative(root, ans);
    cout<<"Preorder Traversal iterative: ";
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
    vector<vector<int>>res;
    levelOrderTraversal(root, res);
    cout<<"Levelorder Traversal: "<<endl;
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
/*
11
1 2 7 3 4 -1 -1 -1 -1 5 6
*/
