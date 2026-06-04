// ═══════════════════════════════════════════════════════
// Problem: 39. Combination Sum
// Difficulty: Medium
// Topics: Array, Backtracking
// Runtime: 3 ms (Beats 51.2%)
// Memory: 14.2 MB (Beats 41.6%)
// Submitted: Jun 4, 2026
// Link: https://leetcode.com/problems/combination-sum/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return res;
    }

    vector<int> subset;
    void dfs(vector<int>& candidates, int& target, int i, int sum){
        if(sum == target){
            res.push_back(subset);
            return;
        }
        if(i >= candidates.size() || sum > target){
            return;
        }
        subset.push_back(candidates[i]);
        dfs(candidates, target, i, sum + candidates[i]);
        subset.pop_back();
        dfs(candidates, target, i + 1, sum);
    }
};
