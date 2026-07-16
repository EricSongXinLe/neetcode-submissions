class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, curr, res);
        return res;
    }
    void backtrack(vector<int>& candidates, int idx, int target, vector<int>& curr, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = idx; i<candidates.size();i++){
            if(i > idx && candidates[i-1] == candidates[i]) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates, i+1, target - candidates[i], curr, res);
            curr.pop_back();
        }
    }
};
