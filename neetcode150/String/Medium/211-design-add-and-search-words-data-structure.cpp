// ═══════════════════════════════════════════════════════
// Problem: 211. Design Add and Search Words Data Structure
// Difficulty: Medium
// Topics: String, Depth-First Search, Design, Trie
// Runtime: 356 ms (Beats 59.8%)
// Memory: 583.5 MB (Beats 34.9%)
// Submitted: Jun 17, 2026
// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/
// ═══════════════════════════════════════════════════════

class dictionaryNode{
public:
    dictionaryNode* children[26]{};
    bool end = false;
};

class WordDictionary {
public:
    dictionaryNode* root;

    WordDictionary() {
        root = new dictionaryNode();
    }
    
    void addWord(string word) {
        dictionaryNode* cur = root;

        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                cur->children[i] = new dictionaryNode();
            }
            cur = cur->children[i];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int j, dictionaryNode* root){
        dictionaryNode* cur = root;

        for(int i = j; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(dictionaryNode* child : cur->children){
                    if (child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }else{
                if (cur->children[c - 'a'] == nullptr){
                    return false;
                }
                cur = cur->children[c - 'a'];
            }
        }
        return cur->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
