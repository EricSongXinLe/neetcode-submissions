class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int i = 0;
        while(isValidIdx(strs, i) && allEquals(strs, i)){
            res += strs[0][i];
            i++;
        }
        return res;
    }
    bool isValidIdx(vector<string>& strs, int idx){
        for(string& s : strs){
            if(s.size() <= idx){
                return false;
            }
        }
        return true;
    }
    bool allEquals(vector<string>& strs, int idx){
        char c = strs[0][idx];
        for(string& s : strs){
            if(s[idx] != c){
                return false;
            }
        }
        return true;
    }
};