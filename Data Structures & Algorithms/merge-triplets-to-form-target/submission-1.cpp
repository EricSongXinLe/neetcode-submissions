class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool m1 = false;
        bool m2 = false;
        bool m3 = false;
        for(auto t : triplets){
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2]){
                continue;
            }
            if(t[0] == target[0]) m1 = true;
            if(t[1] == target[1]) m2 = true;
            if(t[2] == target[2]) m3 = true;
        }
        return m1&&m2&&m3;
    }
};
