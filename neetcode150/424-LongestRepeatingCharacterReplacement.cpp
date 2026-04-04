class Solution {
  // Time complexity: O(n*m) where m is the size of the charset and n is the size of the string
  // Space complexity: O(m) where m is the size of the charset  
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char> charset(s.begin(), s.end());

        for(char c: charset){
            int count=0, l=0;

            for(int r=0; r<s.size(); r++){
                if(s[r]==c)
                count++;
            
                while((r-l+1)-count > k){
                    if(s[l] == c){
                        count--;
                    }
                    l++;
                }
                res= max(res, r-l+1);
            }
        }
      return res;  
    }
};