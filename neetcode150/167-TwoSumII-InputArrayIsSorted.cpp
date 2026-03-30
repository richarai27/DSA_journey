class Solution {
  //I have used two pointers to find the two numbers that add up to the target, with TC O(n) and SC O(1) where n is the length of the input array.
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l= 0; int r= numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target) return {l+1,r+1};
            else if(numbers[l]+numbers[r]<target) l++;
            else r--;
        }
        return {};
    }
};