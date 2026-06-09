// ═══════════════════════════════════════════════════════
// Problem: 22. Generate Parentheses
// Difficulty: Medium
// Topics: String, Dynamic Programming, Backtracking
// Runtime: 6 ms (Beats 13.6%)
// Memory: 17.6 MB (Beats 8.3%)
// Submitted: Jun 9, 2026
// Link: https://leetcode.com/problems/generate-parentheses/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, 2*n - 1, res, "(", 1);
        return res;        
    }

    void dfs(int n, int countLeft, vector<string>& res, string pair, int check){
        if(check < 0 || check > countLeft){
            return;
        }
        if(countLeft == 0 && check == 0){
            res.push_back(pair);
            return;
        }
        countLeft -= 1;
        string str1 = pair + "(";
        check += 1;
        dfs(n, countLeft, res, str1, check);
        string str2 = pair + ")";
        check -= 2;
        dfs(n, countLeft, res, str2, check);
    }
};
