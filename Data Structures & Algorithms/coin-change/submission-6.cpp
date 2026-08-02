class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int>dp(amount+1, amount+1);
        //dp[i]: 最少多少coin能凑到i元
        dp[0] = 0;
        for(int i = 1; i<= amount;i++){
            for(int coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if(dp[amount] == amount+1) return -1;
        return dp[amount];

    }
};
