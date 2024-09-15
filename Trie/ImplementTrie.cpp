//problemLink: https://leetcode.com/problems/implement-trie-prefix-tree/description/

struct TrieNode{
    TrieNode* children[26];
    bool end;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        end=false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(node->children[c-'a']==NULL){
                node->children[c-'a']=new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->end=true;
    }
    
    bool search(string word) {
         TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(node->children[c-'a']==NULL){
                return false;
            }
            node = node->children[c-'a'];
        }
      return  node->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int cnt=0;
        for(int i=0;i<prefix.size();i++){
            char c=prefix[i];
             if(node->children[c-'a']==NULL){
                break;
            }
            cnt++;
            if(cnt==prefix.length()) break;
            node = node->children[c-'a'];
        }
      return cnt==prefix.length();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
