class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        queue<pair<int,int>>q;
        for(int i =0;i<rooms.size();i++){
            for(int j =0; j<rooms[0].size();j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        int dist = 0;
        vector<int>di = {0,-1,0,1};
        vector<int>dj = {1,0,-1,0};
        while(!q.empty()){
            int level_size = q.size();
            dist++;
            for(int cnt = 0; cnt<level_size;cnt++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int d = 0; d<di.size();d++){
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if(ni < 0 || nj < 0 || ni >= rooms.size() || nj >= rooms[0].size() || rooms[ni][nj] == -1) continue;
                    if(rooms[ni][nj] == 2147483647){ 
                        rooms[ni][nj] = dist;
                        q.push({ni,nj});
                    }
                }
            }
        }
    }
};
