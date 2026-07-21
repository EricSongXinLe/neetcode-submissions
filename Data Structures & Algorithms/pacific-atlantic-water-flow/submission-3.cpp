class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>>pac(m,vector<bool>(n));
        vector<vector<bool>>atl(m,vector<bool>(n));

        for(int i = 0; i < m; i++){
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, n-1);
        }
        for(int i = 0; i < n; i++){
            dfs(heights, pac, 0, i);
            dfs(heights, atl, m-1, i);
        }

        vector<vector<int>>res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j){
        vector<int> di = {-1,0,1,0};
        vector<int> dj = {0,1,0,-1};
        vis[i][j] = true;
        for(int d = 0; d< di.size();d++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if(ni < 0 || nj < 0 || ni >= heights.size() || nj >= heights[0].size()){
                continue;
            }
            if(vis[ni][nj]) continue;
            if(heights[i][j] <= heights[ni][nj]){
                dfs(heights, vis, ni, nj);
            }
        }
    }
};
