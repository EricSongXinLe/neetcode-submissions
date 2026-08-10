class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>bals(n+2,1);
        for(int i = 1; i <= n; i++){
            bals[i] = nums[i-1];
        }
        vector<vector<int>>dp(n+2, vector<int>(n+2));
        //i-j means the total coins to get, in range between i and j (not inclusive)
        for(int length = 2; length <= n+1; length++){
            for(int left = 0; left <= n+1-length; left++){
                int right = left+length;
                for(int k = left+1; k < right; k++){
                    int coin = dp[left][k] + 
                            bals[left]*bals[k]*bals[right] 
                            + dp[k][right];
                    dp[left][right] = max(dp[left][right], coin);
                    
                }
            }
        }
        return dp[0][n+1];
    }
};
