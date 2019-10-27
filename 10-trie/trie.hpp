#include <iostream>
#include <map>
#include <string>

using namespace std;

class Trie
{
private:
    struct Node
    {
        bool isWord;
        map<char, Node*> next;
        Node(bool isWord) : isWord(isWord){}
        Node() : isWord(false){}
    };
    Node* root;
    int count;
public:
    Trie(){
        root = new Node();
        count = 0;
    }
    int size(){return count;}
    void add(string word)
    {
        Node* cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            cout << "c = " << c << endl;
            if((cur->next).count(c) == 0)
                (cur->next)[c] = new Node();
            cur = (cur->next)[c];
        }
        if(cur->isWord == false){
            cur->isWord = true;
            count++;
        }
    }
    bool contain(string word)
    {
        Node *cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if((cur->next).count(c) == 0)
                return false;
            else
                cur = (cur->next)[c];
        }
        return cur->isWord == true;
    }
    bool isPrefix(string word)
    {
        Node* cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if((cur->next).count(c) == 0)
                return false;
            cur = (cur->next)[c];
        }
        return true;
    }
};