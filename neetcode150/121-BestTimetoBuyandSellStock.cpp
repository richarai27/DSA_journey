class Solution {
  // Time complexity: O(n)
  // Space complexity: O(1) 
public:
    int maxProfit(vector<int>& prices) {
        int maxP =0;
        int buy=0, sell=1;
        while(sell < prices.size()){
            if(prices[sell]>prices[buy]){
                int profit= prices[sell]-prices[buy];
                maxP = max( maxP, profit);
            }else{
                buy=sell;
            }
            sell++;
        }
        return maxP;        
    }
};