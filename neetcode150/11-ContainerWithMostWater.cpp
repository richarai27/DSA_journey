class Solution {
  // Time complexity: O(n)
  // Space complexity: O(1) 
public:
    int maxArea(vector<int>& height) {
        int res= 0;
        int l=0, r=height.size()-1;
        while(l<r){
            int area = (r-l) * min(height[r],height[l]);
            res = max(res, area);
            
            if(height[r]<height[l]){
                int prevHeight = height[r];
                while(l<r && height[r]<=prevHeight) r--;
            } else{
                int prevHeight = height[l];
                while(l<r && height[l]<=prevHeight) l++;
            }
        }
        return res;
    }
};