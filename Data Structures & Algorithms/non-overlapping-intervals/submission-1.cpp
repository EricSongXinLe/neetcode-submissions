class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
        [](vector<int>& ia, vector<int>& ib){
            return ia[1] < ib[1];
        });
        int res = 0;
        int prevEnd = INT_MIN;
        for(int i = 0; i < intervals.size(); i++){
            if(prevEnd > intervals[i][0]){
                res++; //delete one
            }else{
                prevEnd = intervals[i][1];
            }
        }
        return res;
    }
};
