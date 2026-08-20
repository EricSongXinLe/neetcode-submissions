class Solution {
public:
     bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            unordered_set<int>seen;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                if(seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
                }
            }
        }
        for(int j = 0; j < 9; ++j){
            unordered_set<int>seen;
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                if(seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
                }
            }
        }
        for(int ii = 0; ii < 3; ii++){
            for(int jj = 0; jj < 3; jj++){
                unordered_set<int>seen;
                for(int i = ii*3; i < ii*3+3; i++){
                    for(int j = jj*3; j < jj*3+3; j++){
                        if(board[i][j] != '.'){
                            if(seen.count(board[i][j])) return false;
                            seen.insert(board[i][j]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
