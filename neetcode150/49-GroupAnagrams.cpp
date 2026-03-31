class Solution {
  // Time complexity: O(n * k) where n is the number of strings and k is the average length of the strings (for counting frequency)
  // Space complexity: O(n * k) in the worst case (if all strings are anagrams of each other, we store all of them in the map)
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto x: strs){
           array<int,26> freq(26,0);
            for(char c : x){
             freq[c - 'a']++;
            }
            string key = "";
            for(int i=0; i<26; i++){
                key+= to_string(freq[i]) + "#";
            }
            mp[key].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};