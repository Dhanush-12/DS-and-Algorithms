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
void inorderTraversalRecursive(Node* root, vector<int>&ans)
{
    if(!root) return;
    inorderTraversalRecursive(root->left,ans);
    ans.push_back(root->data);
    inorderTraversalRecursive(root->right, ans);
}
void inorderTraversalIterative(Node* root, vector<int>&ans)
{
    if(!root) return;
    stack<Node*>st;
    Node* node=root;
    while(1)
    {
        if(node){
            st.push(node);
            node=node->left;
        }
        else {
            if(st.empty()) break;
            node=st.top();
            st.pop();
            ans.push_back(node->data);
            node=node->right;
        }
    }
    return;
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
void postorderTraversalRecursive(Node* root, vector<int>&ans)
{
    if(!root) return;
    postorderTraversalRecursive(root->left,ans);
    postorderTraversalRecursive(root->right, ans);
    ans.push_back(root->data);
}
void postorderTraversalIterative_twoStacks(Node* root, vector<int>&ans)
{
    if(!root) return;
    stack<Node*>st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left)
        {
            st1.push(root->left);
        }
        if(root->right)
        {
            st1.push(root->right);
        }
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return;
}
void postorderTraversalIterative_oneStacks(Node* root, vector<int>&ans)
{
    if(!root) return;
    stack<Node*>st;
    Node* curr=root;
    while(curr || !st.empty())
    {
        if(curr)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            Node* temp=st.top()->right;
            if(temp == NULL)
            {
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                curr=temp;
            }
        }
    }
}
void preInorderPostorderTogether(Node* root, vector<int>&pre,vector<int>&in,vector<int>&post)
{
    stack<pair<Node*, int>>st;
    st.push({root, 1});
    if(root == NULL) return;
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();
        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
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
    inorderTraversalRecursive(root, ans);
    cout<<"Inorder Traversal Recursive: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    ans.clear();
    inorderTraversalIterative(root, ans);
    cout<<"Inorder Traversal iterative: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
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
    postorderTraversalRecursive(root, ans);
    cout<<"Postorder Traversal Recursive: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans.clear();
    postorderTraversalIterative_twoStacks(root, ans);
    cout<<"Postorder Traversal Iterative with two stacks: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    ans.clear();
    postorderTraversalIterative_oneStacks(root, ans);
    cout<<"Postorder Traversal Iterative with one stacks: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
    vector<int>pre,in,post;
    preInorderPostorderTogether(root, pre, in, post);
    cout<<"All the technique using One Traversal: "<<endl;
    cout<<"Preorder Traversal: "<<endl;
    for(int i=0;i<pre.size();i++)
    {
        cout<<pre[i]<<' ';
    }
    cout<<endl;
    cout<<"Inorder Traversal: "<<endl;
    for(int i=0;i<in.size();i++)
    {
        cout<<in[i]<<' ';
    }
    cout<<endl;
    cout<<"Postorder Traversal: "<<endl;
    for(int i=0;i<post.size();i++)
    {
        cout<<post[i]<<' ';
    }
    cout<<endl;
}
/*
11
1 2 7 3 4 -1 -1 -1 -1 5 6
*/
