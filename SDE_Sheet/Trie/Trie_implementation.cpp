#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch) {
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* node) {
        links[ch-'a']=node;
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    void setEnd() {
        flag=true;
    }

    bool getEnd() {
        return flag;
    }
};
class Trie {
    Node* root;
    public:
    Trie() {
        root = new Node();
    }

    void insertWord(string str) {
        Node* node = root;
        for(int i=0;i<str.size();i++) {
            if(!node->containsKey(str[i])) {
                node->put(str[i], new Node());
            }
            node=node->get(str[i]);
        }
        node->setEnd();
    }

    bool checkWord(string str) {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i])) return false;
            node=node->get(str[i]);
        }
        return node->getEnd();
    }
    bool checkForPrefix(string str) {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i])) return false;
            node=node->get(str[i]);
        }
        return true;
    }
};
int main()
{
    Trie t;
    cout<<".................Staring the application................."<<endl;
    int controller=10;
    string str;
    while(controller != 0) {
        cout<<"Enter appropriate option to move forward or 0 to exit: "<<endl;
        cout<<"1. Insert a word into the Trie"<<endl;;
        cout<<"2. Find the word in the Trie"<<endl;
        cout<<"3. Check is the word is prefix of any word in the Trie"<<endl;
        cin>>controller;
        if(controller == 0) break;
        cin>>str;
        if(controller == 1) {
            t.insertWord(str);
        }
        else if(controller == 2) {
            if(t.checkWord(str)) {
                cout<<"Word is present in the Trie"<<endl;
            } else {
                cout<<"Oops!!, Can't find the word right now!"<<endl;
            }
        }
        else if(controller == 3) {
            if(t.checkForPrefix(str)) {
                cout<<"The given word is a prefix of a word in the Trie"<<endl;
            } else {
                cout<<"Cannot find a word for which the given word is a prefix!"<<endl;
            }
        }
    }
}
