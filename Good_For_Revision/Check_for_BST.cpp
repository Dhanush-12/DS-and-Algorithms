#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BTree {
public:
    Node* buildTree(vector<int> &arr)
    {
        int n = (int)arr.size();
        int ind = 1;
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = (int)q.size();
            for(int i=0;i<sz;i++)
            {
                Node* curr = q.front();
                q.pop();
                if(ind < n)
                {
                    if(arr[ind] != -1)
                    {
                        Node* n = new Node(arr[ind]);
                        curr->left = n;
                        q.push(curr->left);
                    }
                    ind++;
                }
                if(ind < n)
                {
                    if(arr[ind] != -1)
                    {
                        Node* n = new Node(arr[ind]);
                        curr->right = n;
                        q.push(curr->right);
                    }
                    ind++;
                }
            }
        }
        return root;
    }
    void printTree(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                Node* curr = q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        cout<<endl;
        return;
    }
};
class Solution {
    bool helper(Node* root, int minv = INT_MIN, int maxv = INT_MAX)
    {
        if(!root) return true;

        bool left = helper(root->left, minv, root->data);
        bool right = helper(root->right, root->data, maxv);

        return (left && right && root->data > minv && root->data < maxv);
    }
  public:
    bool isBST(Node* root) {
        //return helper(root);

        stack<Node*> st;

        Node* curr = root;
        Node* prev = NULL;
        while(curr || !st.empty())
        {
            while(curr)
            {
                st.push(curr);
                curr =  curr->left;
            }

            curr = st.top();
            st.pop();

            if(prev && curr->data <= prev->data) return false;

            prev = curr;

            curr = curr->right;
        }

        return true;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    BTree bt;
    Node* root = bt.buildTree(arr);
    //bt.printTree(root);

    Solution s;
    cout<<s.isBST(root)<<endl;
    return 0;
};
/*
7
2 1 3 -1 -1 -1 5

7
2 -1 7 -1 6 -1 9

7
10 5 20 -1 -1 9 25
*/
