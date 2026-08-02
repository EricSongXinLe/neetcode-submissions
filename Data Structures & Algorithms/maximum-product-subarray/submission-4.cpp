class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMin = nums[0];
        int prevMax = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size();i++){
            int curr = nums[i];
            int currMax = max({curr, prevMax * curr, prevMin * curr});
            int currMin = min({curr, prevMax * curr, prevMin * curr});
            prevMin = currMin;
            prevMax = currMax;
            res = max(res, prevMax);
        }
        return res;
    }
};
