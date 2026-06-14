// ═══════════════════════════════════════════════════════
// Problem: 208. Implement Trie (Prefix Tree)
// Difficulty: Medium
// Topics: Hash Table, String, Design, Trie
// Runtime: 23 ms (Beats 45.2%)
// Memory: 50.5 MB (Beats 53.2%)
// Submitted: Jun 14, 2026
// Link: https://leetcode.com/problems/implement-trie-prefix-tree/
// ═══════════════════════════════════════════════════════

class TrieNode{
public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;

        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        
        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
         TrieNode* cur = root;
        
        for(char c : prefix){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
