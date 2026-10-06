/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructNode(grid, 0, grid.size(), 0, grid[0].size());
    }
    Node* constructNode(vector<vector<int>>& grid, int rs, int re, int cs, int ce){
        bool allSame = allSameGrid(grid, rs,re,cs,ce);
        if(allSame){
            Node* n = new Node(grid[rs][cs], true);
            return n;
        }else{
            int halfR = rs+(re-rs)/2;
            int halfC = cs+(ce-cs)/2;
            Node* topL = constructNode(grid, rs, halfR, cs, halfC);
            Node* topR = constructNode(grid, rs, halfR, halfC, ce);
            Node* botL = constructNode(grid, halfR, re, cs, halfC);
            Node* botR = constructNode(grid, halfR, re, halfC, ce);
            Node* n = new Node(0, false, topL, topR, botL, botR);
            return n;
        }
    }
    bool allSameGrid(vector<vector<int>>& grid, int rs, int re, int cs, int ce){
        for(int i = rs; i < re; i++){
            for(int j = cs; j < ce; j++){
                if(grid[i][j] != grid[rs][cs]){
                    return false;
                }
            }
        }
        return true;
    }
    
};