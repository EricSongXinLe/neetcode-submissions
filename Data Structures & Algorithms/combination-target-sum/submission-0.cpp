class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>current;
        vector<vector<int>>res;
        backtrack(nums, 0, target, current, res);
        return res;
    }
    void backtrack(vector<int>& nums, int idx, int target, vector<int>& current, vector<vector<int>>&res){
        if(target == 0){
            res.push_back(current);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = idx; i<nums.size();i++){
            current.push_back(nums[i]);
            backtrack(nums, i, target-nums[i], current, res);
            current.pop_back();
        }
    }
};
