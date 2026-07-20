class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>rot;
        vector<int> di = {-1,0,1,0};
        vector<int> dj = {0,-1,0,1};
        int fresh = 0;
        for(int i =0;i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    rot.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int minutes = 0;
        while(!rot.empty() && fresh > 0){
            
            int level_size = rot.size();
            for(int cnt = 0; cnt < level_size;cnt++){
                int i = rot.front().first;
                int j = rot.front().second;
                rot.pop();
                for(int d = 0; d < 4; d++){
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size()) continue;
                    if(grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        rot.push({ni,nj});
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};
