// ═══════════════════════════════════════════════════════
// Problem: 907. Koko Eating Bananas
// Difficulty: Medium
// Topics: Array, Binary Search
// Runtime: 8 ms (Beats 54.1%)
// Memory: 22.9 MB (Beats 77.7%)
// Submitted: Jun 3, 2026
// Link: https://leetcode.com/problems/koko-eating-bananas/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > max) max= piles[i];
        }
        
        int lowest = 1, highest = max; int res = max;
        while(lowest <= highest){
           int k = (lowest + highest) / 2;
           long long hours = 0;
           for(int p: piles){
                hours += (p + k - 1) / k;
           }
           if(hours <= h){
                res = k;
                highest = k - 1;
           }
           else{
                lowest = k + 1;
           }
        }
        return res;
    }
};
