class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size())return false;
        vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++){
            if(s1[i-1] == s3[i-1]){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j = 1; j <= n; j++){
            if(s2[j-1] == s3[j-1]){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i = 1; i<=m;i++){
            for(int j = 1; j <=n; j++){
                int s3Idx = i + j - 1;
                //new from s1:
                bool n1 = dp[i-1][j] && (s1[i-1] == s3[s3Idx]);
                bool n2 = dp[i][j-1] && (s2[j-1] == s3[s3Idx]);
                dp[i][j] = n1 || n2;
            }
        }
        return dp[m][n];
    }
};
