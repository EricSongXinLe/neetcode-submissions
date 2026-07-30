class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMax = nums[0];
        int prevMin = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size();i++){
            int x = nums[i];
            int currMax = max({x, prevMax * x, prevMin * x});
            int currMin = min({x, prevMax * x, prevMin * x});
            prevMax= currMax;
            prevMin = currMin;
            ans = max(ans, prevMax);
        }
        return ans;
    }
};
