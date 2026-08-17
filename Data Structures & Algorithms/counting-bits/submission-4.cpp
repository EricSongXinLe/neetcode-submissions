class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int>dp(n+1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            if(i % 2 == 1){
                dp[i] = dp[i / 2]+1;
            }else{
                dp[i] = dp[i/2];
            }
        }
        return dp;
    }
};
