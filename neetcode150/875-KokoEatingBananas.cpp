class Solution {
  // Time complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile.
  // Space complexity: O(1) since we are using only a constant amount of extra space. 
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