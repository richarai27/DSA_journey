class Solution {
  // I have used hashmap to solve this problem with time complexity O(n) and space complexity O(n).
public:
    int longestConsecutive(vector<int>& nums) {
       
       unordered_set<int> num(nums.begin(), nums.end());
       int longest = 0;

       for(int n: num){
            int val= n;
            if(num.find(val-1)!= num.end()) continue;

            int len= 1;
            while(num.find(val+1)!= num.end()){
                len++; val++;
            }
            longest = max(len,longest);
       } 
       return longest;
    }
};