#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int letterCount=0;

    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setLetterCount()
    {
        letterCount++;
    }
    int getLetterCount()
    {
        return letterCount;
    }
};
class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insertWord(string &str)
    {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i]))
            {
                node->put(str[i], new Node());
            }
            node = node->get(str[i]);
            node->setLetterCount();
        }
    }
    string LCP(string &str, int n)
    {
        Node* node = root;
        string ans="";
        for(int i=0;i<str.size();i++)
        {
            node = node->get(str[i]);
            if(node->getLetterCount() == n)
            {
                ans+=str[i];
            }
            else break;
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Trie t;
    for(int i=0;i<n;i++)
    {
        t.insertWord(arr[i]);
    }
    cout<<t.LCP(arr[0], n)<<endl;
}
