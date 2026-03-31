class Solution {
  // Time complexity: O(n) where n is the length of the input strings
  // Space complexity: O(n) in the worst case (if all characters are unique, we store all of them in the map) 
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,int> m;
        for(char ch : s) {
            m[ch]++;
        }
        for(char ch : t){
            m[ch]--;
            if (m[ch] < 0) return false;
        }
        return true;
    }
};