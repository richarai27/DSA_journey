// ═══════════════════════════════════════════════════════
// Problem: 40. Combination Sum II
// Difficulty: Medium
// Topics: Array, Backtracking
// Runtime: 0 ms (Beats 100.0%)
// Memory: 14.2 MB (Beats 35.2%)
// Submitted: Jun 4, 2026
// Link: https://leetcode.com/problems/combination-sum-ii/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return res;        
    }

    void dfs(vector<int>& candidates, int target, int i, int sum){
        if(sum == target){
            res.push_back(subset);
            return;
        }
        if(sum > target || i >= candidates.size()){
            return;
        }

        subset.push_back(candidates[i]);
        dfs(candidates, target, i + 1, sum + candidates[i]);
        while(i + 1 < candidates.size() && candidates[i + 1] == candidates[i]){
            i++;
        }
        subset.pop_back();
        dfs(candidates, target, i + 1, sum);

    }
};
