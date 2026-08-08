// ═══════════════════════════════════════════════════════
// Problem: 167. Two Sum II - Input Array Is Sorted
// Difficulty: Medium
// Topics: Array, Two Pointers, Binary Search
// Runtime: 0 ms (Beats 100.0%)
// Memory: 19.4 MB (Beats 65.6%)
// Submitted: Aug 8, 2026
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l= 0; int r= numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target) return {l+1,r+1};
            else if(numbers[l]+numbers[r]<target) l++;
            else r--;
        }
        return {};
    }
};
