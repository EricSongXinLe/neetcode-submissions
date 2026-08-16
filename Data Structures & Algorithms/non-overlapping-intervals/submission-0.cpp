class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
        [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int keep = 0;
        int prevEnd = INT_MIN;
        for(auto& inte : intervals){
            if(inte[0] < prevEnd){
                continue;
            }else{
                keep++;
                prevEnd = inte[1];
            }
        }
        return intervals.size() - keep;
    }
};
