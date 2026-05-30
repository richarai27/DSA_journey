// ═══════════════════════════════════════════════════════
// Problem: 621. Task Scheduler
// Difficulty: Medium
// Topics: Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
// Runtime: 24 ms (Beats 45.2%)
// Memory: 42.8 MB (Beats 55.6%)
// Submitted: May 30, 2026
// Link: https://leetcode.com/problems/task-scheduler/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);

        for(char task : tasks) {
            counts[task - 'A']++;
        }

        priority_queue<int> maxHeap;

        for(int count : counts) {
            if(count > 0) {
                maxHeap.push(count);
            }
        }

        queue<pair<int, int>> q; // {remaining count, available time}
        int time = 0;

        while(!maxHeap.empty() || !q.empty()) {
            time++;

            while(!q.empty() && q.front().second <= time) {
                maxHeap.push(q.front().first);
                q.pop();
            }

            if(!maxHeap.empty()) {
                int curr = maxHeap.top();
                maxHeap.pop();

                curr--;

                if(curr > 0) {
                    q.push({curr, time + n + 1});
                }
            }
        }

        return time;
    }
};
