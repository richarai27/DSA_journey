class Solution {
  // Time complexity: O(n) where n is the number of elements in the input array
  // Space complexity: O(n) in the worst case (if all elements are unique, we store all of them in the map)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i]) != m.end() && nums[i]==target-nums[i]) return {i,m[nums[i]]};
            m[nums[i]]=i;
        
            int diff = target-nums[i];
            if(m.find(diff) != m.end() && m[diff] != i) return {i,m[diff]};
        }
        return {};
    }
};