class Solution {
public:
    struct TrieNode{
    public:
        vector<TrieNode*> children;
        string word;
        TrieNode(){
            children.resize(26,nullptr);
        }
    };
    vector<string>res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();
        int col = board[0].size();
        TrieNode* root = new TrieNode();
        for(string& word :words){
            insert(root, word);
        }
        for(int i = 0; i<row;i++){
            for(int j = 0; j < col;j++){
                dfs(board,i,j,root);
            }
        }
        return res;
    }
    void insert(TrieNode* root, string& str){
        TrieNode* curr = root;
        for(char c : str){
            if(!curr->children[c - 'a']){
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->word = str;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return;
        }
        char c = board[i][j];
        if(c == '#') return;
        TrieNode* next = node->children[c-'a'];
        if(!next) return;
        if(next->word != ""){
            res.push_back(next->word);
            next->word = "";
        }
        board[i][j] = '#';
        dfs(board, i+1, j, next);
        dfs(board, i-1, j, next);
        dfs(board, i, j+1, next);
        dfs(board, i, j-1, next);
        board[i][j] = c;
    }
};
