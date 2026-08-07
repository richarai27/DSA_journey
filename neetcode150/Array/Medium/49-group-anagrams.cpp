// ═══════════════════════════════════════════════════════
// Problem: 49. Group Anagrams
// Difficulty: Medium
// Topics: Array, Hash Table, String, Sorting
// Runtime: 76 ms (Beats 6.3%)
// Memory: 37.5 MB (Beats 5.1%)
// Submitted: Aug 7, 2026
// Link: https://leetcode.com/problems/group-anagrams/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> mp;
        for(auto x: strs){
           vector<int> freq(26,0);
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
