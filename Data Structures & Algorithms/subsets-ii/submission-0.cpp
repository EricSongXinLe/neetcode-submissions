class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, curr, res);
        return res;
    }
    void backtrack(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& res){
        res.push_back(curr);
        for(int i = idx; i < nums.size();i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums, i+1, curr, res);
            curr.pop_back();
        }
    }

};
