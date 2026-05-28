// ═══════════════════════════════════════════════════════
// Problem: 1014. K Closest Points to Origin
// Difficulty: Medium
// Topics: Array, Math, Divide and Conquer, Geometry, Sorting, Heap (Priority Queue), Quickselect
// Runtime: N/A (Beats 0.0%)
// Memory: N/A (Beats 0.0%)
// Submitted: May 28, 2026
// Link: https://leetcode.com/problems/k-closest-points-to-origin/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> result;

        for(auto& pt : points){
            maxHeap.push({pt[0]*pt[0]+pt[1]*pt[1], pt});

            if(maxHeap.size() > k) maxHeap.pop();
        }
        while(maxHeap.size() != 0){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
