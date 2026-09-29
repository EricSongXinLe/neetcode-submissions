class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string>stk;
        string curr;

        while(getline(ss, curr, '/')){
            if(curr.empty() || curr == "."){
                continue;
            }else if(curr == ".."){
                if(!stk.empty()){
                    stk.pop_back();
                }
            }else{
                stk.push_back(curr);
            }
        }
        string res;
        res = "/";
        for(string& s : stk){
            res += s;
            res += '/';
        }
        if(res == "/") return res;
        return res.substr(0, res.size()-1);
    }
};