class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++){
            dfs(board, i,0);
            dfs(board, i, col-1);
        }
        for(int j = 0; j < col; j++){
            dfs(board, 0,j);
            dfs(board, row-1, j);
        }
        for(int i = 0; i < row; i++){
            for(int j =0; j < col;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X'){
            return;
        }else if(board[i][j] == 'O'){
            board[i][j] = 'T';
            dfs(board, i+1,j);
            dfs(board, i-1,j);
            dfs(board, i,j+1);
            dfs(board, i,j-1);
        }
    }
};
