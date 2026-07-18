class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> res;
        int count_open=0;
        int count_close =0;
        backtrack(n,curr,res,count_open,count_close);
        return res;
    }
    void backtrack(int n, string& curr, vector<string>& res, int count_open, int count_close){
        if(curr.size() == (n * 2)){
            res.push_back(curr);
        }
        if(count_open < n){
           curr.push_back('(');
            backtrack(n, curr, res, count_open + 1, count_close);
            curr.pop_back();
        }
        if(count_close < count_open){
            curr.push_back(')');
            backtrack(n, curr, res, count_open , count_close+1);
            curr.pop_back();
        }
    }
};
