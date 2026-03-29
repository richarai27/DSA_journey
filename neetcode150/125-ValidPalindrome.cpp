class Solution {
  //I have used two pointers to check if the string is a palindrome or not, with TC O(n) and SC O(1) where n is the length of the string.
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