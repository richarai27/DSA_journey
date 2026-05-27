// ═══════════════════════════════════════════════════════
// Problem: 1127. Last Stone Weight
// Difficulty: Easy
// Topics: Array, Heap (Priority Queue)
// Runtime: 0 ms (Beats 100.0%)
// Memory: 10 MB (Beats 49.1%)
// Submitted: May 27, 2026
// Link: https://leetcode.com/problems/last-stone-weight/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) { 
        priority_queue<int> maxHeap;
        for(int stone : stones){
            maxHeap.push(stone);
        }
        
        while(maxHeap.size()>=1){
            if(maxHeap.size() == 1) return maxHeap.top();

            int s1 = maxHeap.top();
            maxHeap.pop();
            int s2 = maxHeap.top();
            maxHeap.pop();
            if(s1 != s2) maxHeap.push(s1 - s2);
        }
        return 0;
    }
};
