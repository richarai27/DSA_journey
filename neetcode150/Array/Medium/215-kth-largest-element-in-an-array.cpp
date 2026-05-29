// ═══════════════════════════════════════════════════════
// Problem: 215. Kth Largest Element in an Array
// Difficulty: Medium
// Topics: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
// Runtime: 37 ms (Beats 37.2%)
// Memory: 61.6 MB (Beats 33.6%)
// Submitted: May 29, 2026
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
