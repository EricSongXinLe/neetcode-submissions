class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, 0, curr, res);
        return res;
    }
    void backtrack(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& res){
        res.push_back(curr);
        for(int i = idx; i < nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(nums, i+1, curr, res);
            curr.pop_back();
        }
    }
};
