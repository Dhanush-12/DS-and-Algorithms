#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* links[26];
    bool flag=false;
    int cntEndWith=0;
    int cntPrefix=0;
    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }
};
class Trie
{
private: Node* root;

public:
    Trie(){
        root=new Node();
    }
    void insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increaseEnd();
            node->increasePrefix();
        }
        node->setEnd();
        node->increaseEnd();
    }
    bool search(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix)
    {
        Node* node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
    int countWordsEqualTo(string &word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        node->getEnd();
    }
    int countWordsStartingWith(string &word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
            }
            else return 0;
        }
        return node->getPrefix();
    }
    void erase(string &word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else return;
        }
        node->deleteEnd();
    }
    public: bool checkIfPrefixExist(string &str)
    {
        Node* node=root;
        for(int i=0;i<str.size();i++)
        {
            if(node->containsKey(str[i]))
            {
                node=node->get(str[i]);
                if(node->isEnd()==false)
                {
                    //cout<<str<<" "<<str[i]<<endl;
                    return false;
                }
            }
            else
            {
                cout<<str<<" "<<str[i]<<endl;
                return false;
            }
        }
        return true;
    }
};
string completeString(int n,vector<string>&arr)
{
    Trie t;
    for(auto it:arr)
    {
        t.insert(it);
    }
    string ans="";
    for(auto it:arr)
    {
        if(t.checkIfPrefixExist(it))
        {
            if(it.size()>ans.size())
            {
                ans=it;
            }
            else if(it.size()==ans.size() && it<ans)
            {
                ans=it;
            }
        }
    }
    //if(ans.size()==0) cout<<"does not exist"<<endl;
    return ans;
}
int main()
{
    Trie t;
    t.insert("hello");
    t.insert("help");
    t.insert("helper");
    t.insert("hesitate");
    t.insert("hell");
    cout<<t.search("help")<<endl;
    cout<<t.startsWith("hel")<<endl;
    cout<<t.startsWith("he")<<endl;
    cout<<t.search("hel")<<endl;
    string word="hell";
    cout<<t.countWordsStartingWith(word)<<endl;
    word="hell";
    t.erase(word);
    word="hell";
    cout<<t.countWordsStartingWith(word)<<endl;
    cout<<"Enter the size of the buffer: "<<endl;
    int n;
    cin>>n;
    vector<string>arr(n);
    cout<<"Enter the input strings to check the longest string with all the prefixes present: "<<endl;
    for(auto &it:arr)
    {
        cin>>it;
    }
    string ans=completeString(n,arr);
    if(ans.empty()) cout<<"String does not exists"<<endl;
    else cout<<ans<<endl;
}
