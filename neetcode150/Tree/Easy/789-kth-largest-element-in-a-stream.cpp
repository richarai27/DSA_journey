// ═══════════════════════════════════════════════════════
// Problem: 789. Kth Largest Element in a Stream
// Difficulty: Easy
// Topics: Tree, Design, Binary Search Tree, Heap (Priority Queue), Binary Tree, Data Stream
// Runtime: 7 ms (Beats 62.9%)
// Memory: 33.1 MB (Beats 62.6%)
// Submitted: May 26, 2026
// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// ═══════════════════════════════════════════════════════

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> MinHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums){
            MinHeap.push(num);
            if(MinHeap.size() > k){
                MinHeap.pop();
            }
        }
    }
    
    int add(int val) {
        MinHeap.push(val);
        if(MinHeap.size() > k){
            MinHeap.pop();
        }
        return MinHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
