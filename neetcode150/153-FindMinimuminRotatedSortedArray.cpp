class Solution {
  // Time complexity: O(log n) where n is the number of elements in the array.
  // Space complexity: O(1) since we are using only a constant amount of extra space.
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        int res = nums[0];
        while(l <= r){
            if(nums[l] <= nums[r]){
                res = min(res, nums[l]);
                break;
            }
            int k = (l + r) / 2;
            res = min(res, nums[k]);
            if(nums[k] >= nums[l]){
                l = k + 1;
            }else{
                r = k - 1;
            }
        }
        return res;
    }
};