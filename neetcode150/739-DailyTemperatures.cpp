class Solution {
  // Time complexity: O(n)
  // Space complexity: O(n)
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> stk;

        for(int i=0; i<temperatures.size(); i++){
            int temp= temperatures[i];
            while(!stk.empty() && stk.top().first< temp){
                result[stk.top().second]= i-stk.top().second;
                stk.pop();
            }
            stk.push({temp, i});
        }
        return result;
    }
};