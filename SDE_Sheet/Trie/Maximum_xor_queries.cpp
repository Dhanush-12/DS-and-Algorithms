#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[2];

    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
};
class Trie {
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insertNumber(int num)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int maxXor(int k)
    {
        Node* node = root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit = (k>>i) & 1;
            int opp = (bit == 1) ? 0 : 1;
            if(node->containsKey(opp))
            {
               ans = (ans*2) + 1;
               node = node->get(opp);
            }
            else
            {
                ans = (ans*2);
                node = node->get(bit);
            }
        }
        return ans;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Trie t;
    vector<pair<int,int>>q;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        q.push_back({a,b});
    }
    vector<int>ans(m);
    vector<pair<pair<int,int>,int>>sq;
    for(int i=0;i<m;i++)
    {
        sq.push_back({{q[i].first, q[i].second}, i});
    }
    sort(sq.begin(), sq.end(), [&](pair<pair<int,int>,int>a, pair<pair<int,int>,int>b)
         {
            return a.first.second < b.first.second;
         });
    sort(arr.begin(), arr.end());
    int j=0;
    for(int i=0;i<m;i++)
    {
        int x=sq[i].first.first;
        int a=sq[i].first.second;
        int index = sq[i].second;
        int cnt=0;
        while(j<n && arr[j]<=a)
        {
            t.insertNumber(arr[j]);
            j++;
            cnt++;
        }
        if(j==0 && cnt == 0)
        {
            ans[index]=-1;
            continue;
        }
        ans[index]=t.maxXor(x);
    }
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
/*
6 3
3 10 5 25 2 8
0 1
1 2
3 3

6 3
13 3 15 5 12 6
0 3
1 6
3 3
*/
