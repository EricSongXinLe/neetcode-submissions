class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() -1;
        int lMax = height[l];
        int rMax = height[r];
        int res = 0;
        while(l < r){
            if(lMax < rMax){
                res += (lMax - height[l]);
                l++;
                lMax = max(lMax, height[l]);
            }else{
                res+= (rMax - height[r]);
                r--;
                rMax = max(rMax, height[r]);
            }
        }
        return res;
    }
};
