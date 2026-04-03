class Solution {
  // Time complexity: O(n)
  // Space complexity: O(min(m,n)) where m is the size of the charset and n is the size of the string
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0; int l=0;
        unordered_map<char,int> m;
        
        for (int r=0; r< s.size(); r++){
            if(m.find(s[r]) != m.end()){
                l = max(l, m[s[r]] + 1);
            }
            m[s[r]] = r;
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};