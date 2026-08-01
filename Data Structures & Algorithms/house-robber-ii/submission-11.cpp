class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(robRange(nums, 0, n-1), robRange(nums, 1, n));
    }
    int robRange(vector<int>& nums, int start, int end){ //half-open
        int n = end - start;
        vector<int>dp(n);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[start + i]);
        }
        return dp[n-1];
    }
};
