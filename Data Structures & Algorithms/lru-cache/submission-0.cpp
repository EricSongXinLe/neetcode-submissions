class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity){}
    
    int get(int key) {
        if(mp_.count(key)){ //contains element
            auto it = mp_[key];
            pair<int,int> p = *it;
            int val = p.second;
            kv_pairs_.splice(kv_pairs_.begin(),kv_pairs_,it);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp_.count(key)){
            auto it = mp_[key];
            (*it).second = value;
            kv_pairs_.splice(kv_pairs_.begin(),kv_pairs_,it);
        }else{
            if(mp_.size() == cap_){ //already full!
                int key_to_del = kv_pairs_.back().first;
                kv_pairs_.pop_back();
                mp_.erase(key_to_del);
            }
            kv_pairs_.push_front({key,value});
            mp_[key] = kv_pairs_.begin(); //iterator to front.
        }
    }
private:
    int cap_;
    unordered_map<int, list<pair<int,int>>::iterator> mp_;
    list<pair<int,int>>kv_pairs_;
};