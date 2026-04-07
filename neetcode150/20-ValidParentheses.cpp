class Solution {
  // Time Complexity: O(n) where n is the length of the input string s. We traverse the string once, and each operation on the stack (push and pop) takes O(1) time .
  // Space Complexity: O(n) in the worst case, when all characters in the string are opening brackets. In this case, we would push all of them onto the stack.
public:
    bool isValid(string s) {
        stack<char> openingBrackets;
        unordered_map<char,char> validPair ={ {')','('} , {']','['} , {'}','{'} };

        for(char c: s){
            if(!validPair.count(c)) {openingBrackets.push(c);}

            else{
                if(!openingBrackets.empty() && openingBrackets.top()== validPair[c]) {openingBrackets.pop();}
                else {return false;}
            }
        }
        return openingBrackets.empty();
    }
};