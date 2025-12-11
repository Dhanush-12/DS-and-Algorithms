#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    void put(int bit, Node* node)
    {
        links[bit]=node;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
};
class Trie{
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertNumber(int number)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (number >> i) & 1;
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int maxXor(int n, vector<int>&arr)
    {
        int ans=0;
        for(int curr : arr)
        {
            int tempans=0;
            Node* node = root;
            for(int i=31;i>=0;i--)
            {
                int bit = (curr >> i) & 1;
                int opp = (bit == 1) ? 0 : 1;
                if(node->containsKey(opp))
                {
                    tempans = (tempans*2) + 1;
                    node = node->get(opp);
                }
                else
                {
                    tempans = (tempans*2);
                    node = node->get(bit);
                }
            }
            ans=max(ans, tempans);
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Trie t;
    for(int i=0;i<n;i++)
    {
        t.insertNumber(arr[i]);
    }
    cout<<t.maxXor(n,arr)<<endl;
}
