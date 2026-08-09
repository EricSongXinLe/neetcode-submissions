class Solution {
public:
    vector<int>dr = {-1,0,1,0};
    vector<int>dc = {0,1,0,-1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        int maxLen = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxLen = max(maxLen, dfs(matrix, i, j, dp));
            }
        }
        return maxLen;
    }
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
        if(dp[r][c] != 0){
            return dp[r][c];
        }
        dp[r][c] = 1;
        for(int i = 0 ;i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= matrix.size() || nc >= matrix[0].size() || 
                matrix[r][c] >= matrix[nr][nc]){
                    continue;
            }else{
                dp[r][c] = max(dp[r][c], 1 + dfs(matrix, nr, nc, dp));
            }
        }
        return dp[r][c];
    }
};
