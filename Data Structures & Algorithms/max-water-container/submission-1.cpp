class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxArea = min(height[l],height[r]) * (r-l);
        while(l<r){
            if(height[r] > height[l]){
                l = l+1;
                int newArea = min(height[l],height[r]) * (r-l);
                if (newArea > maxArea){
                    maxArea = newArea;
                }
            }
            else{
                r = r-1;
                int newArea = min(height[r],height[l]) * (r-l);
                if(newArea > maxArea){
                    maxArea = newArea;
                }
            }
        }
        return maxArea;
    }
};
