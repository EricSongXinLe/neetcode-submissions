class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1));
        //[i][j] means with first i coins, which j amount could we achieve
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<=amount;j++){
                int coin = coins[i-1];
                dp[i][j] += dp[i-1][j];
                if(j - coin >= 0){
                    dp[i][j] += dp[i][j-coin];
                }
            }
        }
        return dp[n][amount];
    }
};
