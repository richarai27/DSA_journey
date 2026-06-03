// ═══════════════════════════════════════════════════════
// Problem: 78. Subsets
// Difficulty: Medium
// Topics: Array, Backtracking, Bit Manipulation
// Runtime: 0 ms (Beats 100.0%)
// Memory: 10 MB (Beats 58.4%)
// Submitted: Jun 3, 2026
// Link: https://leetcode.com/problems/subsets/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSet;
        vector<vector<int>> result;
        dfs(nums, 0, currSet, result);
        return result;        
    }

    void dfs(vector<int>& nums, int i, vector<int>& currSet, vector<vector<int>>& result){
        if(i >= nums.size()){
            result.push_back(currSet);
            return;
        }
        currSet.push_back(nums[i]);
        dfs(nums, i + 1, currSet, result);
        currSet.pop_back();
        dfs(nums, i + 1, currSet, result);
    }
};
