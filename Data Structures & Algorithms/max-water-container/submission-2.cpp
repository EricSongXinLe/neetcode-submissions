class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int l = 0;
        int r = heights.size() -1;
        while(l < r){
            maxArea = max(maxArea, (r - l) * min(heights[r], heights[l]));
            if(heights[l] > heights[r]){
                r--; //if we move the left one, it would still be bounded by r, or a weaker l.
            }else{
                l++;
            }
        }
        return maxArea;
    }
};
