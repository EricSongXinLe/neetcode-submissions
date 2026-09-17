class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int prevEnd = INT_MIN;
        while(i < intervals.size()){
            int currBegin = intervals[i][0];
            if(currBegin <= prevEnd){ //overlap
                res[res.size() - 1][1] = max(res[res.size() - 1][1], 
                                            intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
            prevEnd = res[res.size() - 1][1];
            i++;
        }
        return res;
    }
};
