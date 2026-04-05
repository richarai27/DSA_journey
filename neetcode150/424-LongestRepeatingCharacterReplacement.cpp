class Solution {
    // Time Complexity: O(n) where n is the length of the string s. We traverse the string once with the right pointer, and the left pointer also moves at most n times in total.
    // Space Complexity: O(1) since the frequency map can hold at most 26 entries for uppercase English letters.
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, int> freq;
        
        int l=0, maxFreq=0;
        for(int r=0; r<s.size(); r++){
            freq[s[r]]++;
            maxFreq= max(maxFreq,freq[s[r]]);
            
            while((r-l+1)-maxFreq > k){
                freq[s[l]]--;
                l++;   
            }
            res= max(res, r-l+1); 
        }
      return res;  
    }
};