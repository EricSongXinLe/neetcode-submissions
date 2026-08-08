class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            int curr_coin = coins[i-1];
            for(int amt = 1; amt <= amount; amt++){
                dp[i][amt] = dp[i-1][amt];
                if(amt - curr_coin >= 0){
                    dp[i][amt] += dp[i][amt-curr_coin];
                }
            }
        }
        return dp[n][amount];
    }
};
