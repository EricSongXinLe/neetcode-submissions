class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq; //num -> freq
        for(int& num : nums){
            freq[num]++;
        }
        auto it = freq.begin();
        vector<vector<int>>bucket(nums.size() + 1);
        while(it!=freq.end()){
            bucket[(*it).second].push_back((*it).first); //freq->nums
            it++;
        }
        vector<int>res;
        for(int i = bucket.size() - 1; i>=0; i--){
            if(!bucket[i].empty()){
                for(auto elem : bucket[i]){
                    if(k == 0) return res;
                    res.push_back(elem);
                    k--;
                }
            }
        }
        return res;
    }
};