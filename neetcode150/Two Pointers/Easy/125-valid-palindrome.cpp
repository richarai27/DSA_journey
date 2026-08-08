// ═══════════════════════════════════════════════════════
// Problem: 125. Valid Palindrome
// Difficulty: Easy
// Topics: Two Pointers, String
// Runtime: 0 ms (Beats 100.0%)
// Memory: 10 MB (Beats 54.3%)
// Submitted: Aug 8, 2026
// Link: https://leetcode.com/problems/valid-palindrome/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0) return true;

        int b=0, e= s.length()-1;
        while(b<e){
            while(!(alphaNumeric(s[b]))  &&  b<e) {b++;}
            while(!(alphaNumeric(s[e]))  &&  b<e) {e--;}
            
            if(tolower(s[b]) != tolower(s[e])) return false;
            b++;e--;
        } 
        return true;
    }

    bool alphaNumeric(char ch){
        if('a'<=ch && ch<='z' || 'A'<=ch && ch<='Z' || '0'<=ch && ch<='9') return true;
        return false;
    }
};
