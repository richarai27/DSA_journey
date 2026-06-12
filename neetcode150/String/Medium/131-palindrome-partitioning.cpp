// ═══════════════════════════════════════════════════════
// Problem: 131. Palindrome Partitioning
// Difficulty: Medium
// Topics: String, Dynamic Programming, Backtracking
// Runtime: 47 ms (Beats 53.5%)
// Memory: 57.6 MB (Beats 52.2%)
// Submitted: Jun 12, 2026
// Link: https://leetcode.com/problems/palindrome-partitioning/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; vector<string> validStrings;        
        dfs(0, s, validStrings, res);
        return res;
    }
    void dfs(int i, string& s, vector<string>& validStrings, vector<vector<string>>& res){
        if(i == s.length()){
            res.push_back(validStrings);
            return;
        }
        for(int j = i; j < s.length(); j++){
            if( isPalindrome(s, i, j) ){
                validStrings.push_back( s.substr(i, j - i + 1) );
                dfs(j + 1, s, validStrings, res);
                validStrings.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};
