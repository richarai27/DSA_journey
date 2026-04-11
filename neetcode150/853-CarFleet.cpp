class Solution {
  // Time complexity: O(nlogn)
  // Space complexity: O(n)
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pair;
        for(int i = 0; i < speed.size(); i++){
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stk;
        for(auto p: pair){
            stk.push_back(double(target - p.first) / p.second);
            if(stk.size() >= 2 && stk[stk.size() - 1] <= stk[stk.size() - 2]){
                stk.pop_back();
            }
        }
        return stk.size();
    }
};