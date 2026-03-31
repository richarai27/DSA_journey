class Solution {
  // Time complexity: O(n^2)
  // Space complexity: O(1) (not counting the space used for the output)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int l,r;
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            l=i+1; r=nums.size()-1;
            if(nums[i]>0) break;
            else{          
                while(l<r){
                  int sum= nums[i]+nums[l]+nums[r];
                  if(sum<0) l++;
                  else if(sum>0) r--;
                  else{
                        v.push_back({nums[i],nums[l],nums[r]});
                        l++; r--;
                        while(nums[l]==nums[l-1] && l<r) {l++;}
                        while(nums[r]==nums[r+1] && l<r) {r--;}
                    }    
                }
            }
        }return v;
    }
};