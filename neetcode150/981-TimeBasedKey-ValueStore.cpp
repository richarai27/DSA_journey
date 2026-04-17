class TimeMap {
  // Time: O(log(n)) for get, O(1) for set, where n is the number of values for a given key.
  // Space: O(m) where m is the total number of key-value pairs stored in the TimeMap.
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);   
    }
    
    string get(string key, int timestamp) {
        auto& values = mp[key];
        int l = 0, r = values.size() - 1;
        string res = "";

        while(l <= r){
            int mid =  l + (r - l) / 2;
            if(values[mid].first <= timestamp){
                res = values[mid].second;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        } return res; 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */