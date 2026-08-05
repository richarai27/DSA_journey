// ═══════════════════════════════════════════════════════
// Problem: 792. Binary Search
// Difficulty: Easy
// Topics: Array, Binary Search
// Runtime: 0 ms (Beats 100.0%)
// Memory: 31.3 MB (Beats 47.1%)
// Submitted: Aug 5, 2026
// Link: https://leetcode.com/problems/binary-search/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;

        while(start <= end){
            mid = (start + end) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
};
