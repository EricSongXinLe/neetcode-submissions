class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        for(auto& inte: intervals){
            if(!res.empty() && res[res.size() - 1][1] >= inte[0]){
                res[res.size() - 1][1] = max(res[res.size() - 1][1], inte[1]);
            }else{
                res.push_back(inte);
            }
        }
        return res;
    }
};
