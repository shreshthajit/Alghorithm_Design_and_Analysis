//Problem Link: https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i/description/

class Solution {
    struct TrieNode{
    TrieNode* children[26];
    TrieNode(){
        for(int i=0;i<26;i++){
        children[i]=NULL;
    }
    }
    };

class Trie{
   TrieNode* root;
public:
    Trie(){
        root= new TrieNode();
    }
    
    void insert(string &word){
     TrieNode* node=root;
     for(int i=0;i<word.size();i++){
        char c=word[i];
        if(node->children[c-'a']==NULL){
            node->children[c-'a']=new TrieNode();
        }
        node = node->children[c-'a'];
     }
    }

    int rec(int index,string &target,vector<int>&dp){
        if(index==target.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int n=target.size();
        TrieNode* node=root;
        int ans=1e6;
        int i=index;
        while(i<n){
            char c=target[i];
            if(node->children[c-'a']==NULL) break;
            ans=min(ans,rec(i+1,target,dp)+1);
            node=node->children[c-'a'];
            i++;
        }
        return dp[index]=ans;
    }
};


public:
    int minValidStrings(vector<string>& words, string target) {
        Trie t;
        for(auto it:words)
        t.insert(it);
        int n=target.size();
        vector<int>dp(n,-1);
        int ans=t.rec(0,target,dp);
        if(ans>=1e6) return -1;
         
        return ans;
    }
};
