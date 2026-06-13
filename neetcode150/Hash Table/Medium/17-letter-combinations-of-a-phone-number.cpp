// ═══════════════════════════════════════════════════════
// Problem: 17. Letter Combinations of a Phone Number
// Difficulty: Medium
// Topics: Hash Table, String, Backtracking
// Runtime: 0 ms (Beats 100.0%)
// Memory: 9.4 MB (Beats 43.2%)
// Submitted: Jun 13, 2026
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return res;
        dfs(digits, 0, "");
        return res;
    }
    void dfs(string& digits, int i, string str){
        if(i == digits.length()){
            res.push_back(str);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for(char c : chars){
            dfs(digits, i + 1, str + c); 
        }
    }
};
