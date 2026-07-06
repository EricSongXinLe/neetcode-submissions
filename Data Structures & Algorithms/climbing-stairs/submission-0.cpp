class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1; // only 1 way to climb 0 stair.
        dp[1] = 1; // 1ways to climb one stair
        //dp[2] = 2;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2]; //we could climb n-2 stairs, and climb the 2 at once, OR, climbe n-1, and climb the last one. 
        } 
        return dp[n];
    }
};
