// ═══════════════════════════════════════════════════════
// Problem: 355. Design Twitter
// Difficulty: Medium
// Topics: Hash Table, Linked List, Design, Heap (Priority Queue)
// Runtime: 3 ms (Beats 89.3%)
// Memory: 57 MB (Beats 24.8%)
// Submitted: Jun 1, 2026
// Link: https://leetcode.com/problems/design-twitter/
// ═══════════════════════════════════════════════════════

class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweetRecord; // userId : {{time, tweetId}}
    unordered_map<int, set<int>> followRecord;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetRecord[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followRecord[userId].insert(userId);
        
        priority_queue<vector<int>> maxHeap;
        
        for (auto followee : followRecord[userId]) {
            if (!tweetRecord.count(followee) || tweetRecord[followee].empty()) {
                continue;
            }
            
            int idx = tweetRecord[followee].size() - 1;
            auto &p = tweetRecord[followee][idx];
            
            maxHeap.push({p.first, p.second, followee, idx - 1});
        }
       
        while (!maxHeap.empty() && res.size() < 10) {
            auto t = maxHeap.top();
            maxHeap.pop();
            
            res.push_back(t[1]); // Append tweetId to results
            
            int nextIdx = t[3];
            int followeeId = t[2];
            
            if (nextIdx >= 0) {
                auto &p = tweetRecord[followeeId][nextIdx];
                maxHeap.push({p.first, p.second, followeeId, nextIdx - 1});
            }
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followRecord[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && followRecord[followerId].count(followeeId)) {
            followRecord[followerId].erase(followeeId);
        }
    }
};
