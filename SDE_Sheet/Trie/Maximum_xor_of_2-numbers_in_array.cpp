#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* links[2];
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
};
class Trie
{
    private: Node* root;
    public :
    Trie()
    {
        root=new Node();
    }
    void insert(int n)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int n)
    {
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxi=maxi|(1<<i);
                node=node->get(1-bit);
            }
            else
            {
                node=node->get(bit);
            }
        }
        return maxi;
    }
};
int maxXor(int n,int m,vector<int>&a,vector<int>&b)
{
    Trie t;
    for(int i=0;i<n;i++)
    {
        t.insert(a[i]);
    }
    int maxi=0;
    for(int i=0;i<m;i++)
    {
        maxi=max(maxi,t.getMax(b[i]));
    }
    return maxi;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    cout<<maxXor(n,m,a,b)<<endl;
}
