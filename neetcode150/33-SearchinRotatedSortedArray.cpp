class Solution {
  // Time complexity: O(log n) where n is the number of elements in the array.
  // Space complexity: O(1) since we are using only a constant amount of extra space.
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int m = (l + r) / 2;
            if(target == nums[m]) return m;
            
            if(nums[m] >= nums[l]){
                if(target > nums[m] || target < nums[l]){
                    l = m + 1;
                }
                else{
                    r = m -1;
                }
            }
            else{
                if(target < nums[m] || target > nums[r]){
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};