#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2];
    int countNum=0;

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void setCount()
    {
        countNum++;
    }
    int getCount()
    {
        return countNum;
    }
    void decreaseCount()
    {
        countNum--;
    }
};
class Trie{
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
            node->setCount();
        }
    }
    void removeNumber(int num)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            node = node->get(bit);
            node->decreaseCount();
        }
    }
    int maxXor(int num)
    {
        Node* node = root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            int opp = bit ^ 1;
            if(node->containsKey(opp) && node->get(opp)->getCount() > 0)
            {
                ans = ans|(1<<i);
                node = node->get(opp);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    Trie t;
    int l=0,r=0;
    int ans=0;
    while(r<n)
    {
        t.insertNumber(arr[r]);
        while(l<r && (arr[r] > 2ll*arr[l]))
        {
            t.removeNumber(arr[l]);
            l++;
        }
        ans=max(ans, t.maxXor(arr[r]));
        r++;
    }
    cout<< ans << endl;
}
