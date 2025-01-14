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
vector<int>maxXorQueries(vector<int>&arr,vector<vector<int>>&queries,int n,int q)
{
    sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>>oq;
    for(int i=0;i<q;i++)
    {
        oq.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(oq.begin(),oq.end());
    vector<int>ans(q,0);
    int ind=0;
    Trie t;
    for(int i=0;i<q;i++)
    {
        int limit=oq[i].first;
        int x=oq[i].second.first;
        int qind=oq[i].second.second;
        while(ind<n && arr[ind]<=limit)
        {
           t.insert(arr[ind]);
           ind++;
        }
        if(ind==0) ans[qind]=-1;
        else ans[qind]=t.getMax(x);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;
    cin>>q;
    vector<vector<int>>queries(q);
    for(int i=0;i<q;i++)
    {
        int x,limit;
        cin>>x>>limit;
        queries[i].push_back(x);
        queries[i].push_back(limit);
    }
    vector<int>ans=maxXorQueries(arr,queries,n,q);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
