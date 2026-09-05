class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>window; //val->idx
        int r = 0;
        int l = 0;
        while(r < nums.size()){
            int curr = nums[r];
            if(window.count(curr)){
                return true;
            }else{
                window[curr] = r;
                r++;
                if(r - l > k){
                    window.erase(nums[l]);
                    l++;
                }
            }
        }
        return false;
    }
};