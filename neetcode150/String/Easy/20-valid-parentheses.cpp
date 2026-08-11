// ═══════════════════════════════════════════════════════
// Problem: 20. Valid Parentheses
// Difficulty: Easy
// Topics: String, Stack, Bracket Sequences
// Runtime: 0 ms (Beats 100.0%)
// Memory: 9.2 MB (Beats 11.3%)
// Submitted: Aug 11, 2026
// Link: https://leetcode.com/problems/valid-parentheses/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    bool isValid(string s) {
        stack<char> openingBrackets;
        unordered_map<char,char> validPair ={ {')','('} , {']','['} , {'}','{'} };

        for(char c: s){
            if(!validPair.count(c)) openingBrackets.push(c);

            else{
                if(!openingBrackets.empty() && openingBrackets.top()== validPair[c]) {
                    openingBrackets.pop();
                }
                else{
                    return false;
                }
            }
        }
        return openingBrackets.empty();
    }
};
