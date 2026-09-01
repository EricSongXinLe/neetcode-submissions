class MyHashMap {
public:
    MyHashMap() {
        bucketCount = 1000;
        elemCount = 0;
        loadFactor = 1.5;
        mp.resize(bucketCount);
    }
    
    void put(int key, int value) {
        int bucket = hash(key);
        auto it = mp[bucket].begin();
        while(it != mp[bucket].end()){
            if((*it).first == key){
                (*it).second = value;
                return;
            }
            it++;
        }
        mp[bucket].push_back({key,value});
        elemCount++;
    }
    
    int get(int key) {
        int bucket = hash(key);
        auto it = mp[bucket].begin();
        while(it != mp[bucket].end()){
            if((*it).first == key){
                return (*it).second;
            }
            it++;
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket = hash(key);
        auto it = mp[bucket].begin();
        while(it != mp[bucket].end()){
            if((*it).first == key){
                mp[bucket].erase(it); //can't use it again
                elemCount--;
                return;
            }
            it++;
        }
    }
    private:
    int hash(int key){
        return key % bucketCount;
    }
    int bucketCount;
    int elemCount;
    double loadFactor;
    vector<list<pair<int,int>>>mp;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */