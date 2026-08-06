// ═══════════════════════════════════════════════════════
// Problem: 217. Contains Duplicate
// Difficulty: Easy
// Topics: Array, Hash Table, Sorting
// Runtime: 75 ms (Beats 33.0%)
// Memory: 111.3 MB (Beats 42.3%)
// Submitted: Aug 6, 2026
// Link: https://leetcode.com/problems/contains-duplicate/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int num : nums){
            if(!(s.insert(num).second))
            return true;
        }
        return false;  
    }
};
