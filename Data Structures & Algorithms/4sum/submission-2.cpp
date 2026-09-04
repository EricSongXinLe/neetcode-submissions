class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size(); j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int l = j+1;
                int r = nums.size() - 1;
                while(l < r){
                    long long remaining = (long long)target - nums[i] - nums[j];
                    if(nums[l] + nums[r] == remaining){
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l+1] == nums[l]){
                            l++;
                        }
                        while(l < r && nums[r-1] == nums[r]){
                            r--;
                        }
                        l++;
                        r--;
                    }else if(nums[l] + nums[r] < remaining){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return res;
    }
};