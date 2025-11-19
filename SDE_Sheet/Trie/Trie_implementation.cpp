#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node *links[26];
    bool flag=false;

    bool containsKey(char ch) {
         return (links[ch-'a'] != NULL);
    }

    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }

    Node *get(char ch) {
        return links[ch-'a'];
    }

    bool setEnd() {
        flag=true;
    }

    bool getEnd() {
        return flag;
    }
};
class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i])) return false;
            node->get(word[i]);
        }
        return node->getEnd();
    }
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i])) return false;
            node->get(word[i]);
        }
        return true;
    }
};
int main()
{
    Trie t;
    int controller=1;
    string str;
    cout<<"Enter a word into your trie: ";
    do {
        if(controller == 1)
        {
            cin>>str;
            t.insert(str);
        }
        else if(controller == 2)
        {
            cin>>str;
            cout<<t.search(str)<<endl;
        }
        else if(controller == 3)
        {
            cin>>str;
            cout<<t.startsWith(str)<<endl;
        }
        cout<<"Enter the controller value: ";
        cin>>controller;
    }while(controller != 0);
}
