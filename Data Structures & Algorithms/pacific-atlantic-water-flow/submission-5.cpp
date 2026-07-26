class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>>atl(row,vector<bool>(col,false));
        vector<vector<bool>>pac(row,vector<bool>(col,false));
        vector<vector<int>>res;
        for(int r = 0; r < row; r++){
            dfs(heights, pac, 0,r,0);
            dfs(heights, atl, 0,r,col-1);
        }
        for(int c = 0; c < col; c++){
            dfs(heights, pac, 0,0,c);
            dfs(heights, atl, 0,row-1,c);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col;j++){
                if(atl[i][j] && pac[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, 
                int prevHeight, int i, int j){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;
        if(prevHeight > heights[i][j]) return;
        if(vis[i][j]) return;
        vis[i][j] = true;
        dfs(heights, vis, heights[i][j], i+1, j);
        dfs(heights, vis, heights[i][j], i-1, j);
        dfs(heights, vis, heights[i][j], i, j+1);
        dfs(heights, vis, heights[i][j], i, j-1);
    }
};
