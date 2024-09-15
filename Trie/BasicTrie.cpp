#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
    TrieNode* children[26];
    bool End;
    TrieNode()
    {
        End=false;
        for(int i=0; i<26; i++)
        {
            children[i]=NULL;
        }
    }
};

class Trie
{
    TrieNode* root;
public:
    Trie()
    {
        root= new TrieNode();
    }

    void insert(const string& word)
    {
        TrieNode* node=root;
        for(int i=0; i<word.size(); i++)
        {
            char c=word[i];
            if(node->children[c-'a']==NULL)
            {
                node->children[c-'a']=new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->End=true;
    }

    bool search(const string& word)
    {
        TrieNode* node = root;
        int i=0;
        while(i<word.size())
        {
            char c=word[i];
            if(node->children[c-'a']==NULL) return false;
            node=node->children[c-'a'];
            i++;
        }
        return node->End;

    }
};

int main()
{

    Trie myTrie;
    //when inserting words becareful for not inserting uppercase letters since we took 0-25 number
    vector<string>words = {"hello","kbnr","shivay","krishna"};// we can insert only lowercase words
     for (const string& word : words) {
        myTrie.insert(word);
    }

    bool found  = myTrie.search("shivay");
    cout<<found<<endl;
    return 0;
}
