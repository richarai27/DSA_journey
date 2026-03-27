class Solution {
  //I have used a hash set with time complexity O(n) and space complexity O(n).
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int num : nums){
            if(!(s.insert(num).second))
            return true;
        }
        return false;  
    }
};