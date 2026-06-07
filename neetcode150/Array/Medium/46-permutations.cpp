// ═══════════════════════════════════════════════════════
// Problem: 46. Permutations
// Difficulty: Medium
// Topics: Array, Backtracking
// Runtime: 4 ms (Beats 10.7%)
// Memory: 11.1 MB (Beats 20.7%)
// Submitted: Jun 7, 2026
// Link: https://leetcode.com/problems/permutations/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {{}};

        vector<int> temp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> permutes = permute(temp);
        vector<vector<int>> res;
        for(auto p : permutes){
            for(int i = 0; i < p.size() + 1; i++){
                vector<int> copy = p;
                copy.insert(copy.begin() + i, nums[0]);
                res.push_back(copy);
            }
        }
        return res;
    }
};
