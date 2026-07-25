class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>rot;
        vector<int>di = {-1,0,1,0};
        vector<int>dj = {0,1,0,-1};
        for(int i = 0; i < row; i++){
            for(int j = 0; j< col;j++){
                if(grid[i][j] == 1){
                    fresh++;
                }else if(grid[i][j] == 2){
                    rot.push({i,j});
                }
            }
        }
        int minute = 0;
        while(!rot.empty() && fresh > 0){
            int curr_lvl = rot.size();
            minute++;
            for(int l = 0; l<curr_lvl;l++){
                auto[i,j] = rot.front();
                rot.pop();
                for(int d = 0; d < 4; d++){
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if(ni < 0 || nj < 0 || ni >= row || nj >= col || grid[ni][nj] == 0){
                        continue;
                    }
                    if(grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        rot.push({ni,nj});
                        fresh--;
                    }
                }
            }
        }
        if(fresh > 0) return -1;
        return minute; 
    }
};
