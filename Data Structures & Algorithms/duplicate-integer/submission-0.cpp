class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hm;
        for(int i =0;i<nums.size();i++){
            hm.insert(nums[i]);
        }
        if(hm.size() == nums.size())
            return false;
        return true;
    }
};