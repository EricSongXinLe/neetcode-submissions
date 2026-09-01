class MyHashSet {
public:
    MyHashSet() {
        bucketCount = 100;
        elemCount = 0;
        loadFactor = 1.5;
        mp.resize(bucketCount);
    }
    
    void add(int key) {
        if(contains(key))return;
        /*if(elemCount + 1 > bucketCount * loadFactor){
            resize();
        }*/
        int bucket = hash(key);
        mp[bucket].push_back(key);
        elemCount++;
    }
    
    void remove(int key) {
        int bucket = hash(key);
        auto it = mp[bucket].begin();
        while(it != mp[bucket].end()){
            if(*it == key){
                mp[bucket].erase(it); //can't use it again
                elemCount--;
                return;
            }
            it++;
        }
    }
    
    bool contains(int key) {
        int bucket = hash(key);
        auto it = mp[bucket].begin();
        while(it != mp[bucket].end()){
            if(*it == key){
                return true;
            }
            it++;
        }
        return false;
    }
private:
    void resize(){
    }
    int hash(int key){
        return key % bucketCount;
    }
    int bucketCount;
    int elemCount;
    double loadFactor;
    vector<list<int>>mp;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */