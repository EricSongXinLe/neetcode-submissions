class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        int l = 0;
        int r = mp[key].size();
        while(l < r){ //search for first elem largest than timestamp
            int mid = l + (r - l)/2;
            if(mp[key][mid].first > timestamp){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if(l == 0) return "";
        return mp[key][l-1].second;
    }
private:
    unordered_map<string, vector<pair<int,string>>>mp;
};
