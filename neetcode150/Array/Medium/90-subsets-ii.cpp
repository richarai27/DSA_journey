// ═══════════════════════════════════════════════════════
// Problem: 90. Subsets II
// Difficulty: Medium
// Topics: Array, Backtracking, Bit Manipulation
// Runtime: 0 ms (Beats 100.0%)
// Memory: 10.3 MB (Beats 96.9%)
// Submitted: Jun 8, 2026
// Link: https://leetcode.com/problems/subsets-ii/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, subset, res, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int i){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, subset, res, i + 1);
        subset.pop_back();
        while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i += 1;
        dfs(nums, subset, res, i + 1);
    }
};
