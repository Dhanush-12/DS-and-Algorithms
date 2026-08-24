#include<bits/stdc++.h>
using namespace std;
struct Node {
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
        Node* root = new Node(arr[0]);

        int ind = 1;
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
            int sz = (int)q.size();
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
    }
};
class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        if(!r1 || !r2) return r1 == r2;

        if(r1->data != r2->data) return false;

        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    BTree bt;
    Node* root1 = bt.buildTree(a);
    Node* root2 = bt.buildTree(b);
    //bt.printTree(root1);
    //bt.printTree(root2);
    Solution s;
    cout<<s.isIdentical(root1, root2)<<endl;
}
/*
7 7
1 2 3 4 -1 -1 -1
1 2 3 4 -1 -1 -1
*/
