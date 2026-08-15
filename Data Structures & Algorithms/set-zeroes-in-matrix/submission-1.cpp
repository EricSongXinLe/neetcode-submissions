class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>rows;
        unordered_set<int>cols;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        vector<int>rs(rows.begin(), rows.end());
        vector<int>cs(cols.begin(), cols.end());
        for(int i : rs){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[i][j] = 0;
            }
        }
        for(int j : cs){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][j] = 0;
            }
        }
    }
};
