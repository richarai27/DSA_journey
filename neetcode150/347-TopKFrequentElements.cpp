class Solution {
  // Time complexity: O(n)
  // Space complexity: O(n) (due to the bucket array)
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto x: mp){
            int freq= x.second; int num= x.first;
            bucket[freq].push_back(num);
        }

        vector<int> v;
        for(int i= nums.size(); i >= 0 && v.size()<k; i--){
            for(int num: bucket[i]){
                v.push_back(num);
                if(v.size() == k) break;
            }
        }   
        return v;
    }
};