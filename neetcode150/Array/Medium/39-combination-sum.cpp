// ═══════════════════════════════════════════════════════
// Problem: 39. Combination Sum
// Difficulty: Medium
// Topics: Array, Backtracking
// Runtime: 2 ms (Beats 57.0%)
// Memory: 14 MB (Beats 73.3%)
// Submitted: Jun 4, 2026
// Link: https://leetcode.com/problems/combination-sum/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        dfs(candidates, target, 0, 0, result);
        return result;
    }

    vector<int> subset;
    void dfs(vector<int>& candidates, int& target, int i, int sum, vector<vector<int>>& res){
        if(sum == target){
            res.push_back(subset);
            return;
        }
        if(i >= candidates.size() || sum > target){
            return;
        }
        subset.push_back(candidates[i]);
        dfs(candidates, target, i, sum + candidates[i], res);
        subset.pop_back();
        dfs(candidates, target, i + 1, sum, res);
    }
};
