class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size();i++){
            auto[start, end] = expandOdd(s, i);
            if((end - start+1) > res.size()){
                res = s.substr(start, end-start+1);
            }
        }
        for(int i = 0; i < s.size()-1;i++){
            auto[start, end] = expandEven(s, i);
            if(end == start) continue;
            if((end - start+1) > res.size()){
                res = s.substr(start, end-start+1);
            }
        }
        return res;
    }
    pair<int,int>expandOdd(string& s, int idx){
        int n = s.size();
        int start = idx;
        int end = idx;
        while(start - 1 >= 0 && end + 1 <= (n-1) && s[start-1] == s[end+1]){
            start--;
            end++;
        }
        return {start,end};
    }
    pair<int,int>expandEven(string& s, int idx){
        int n = s.size();
        int start = idx;
        int end = idx+1;
        if(s[start] != s[end]) return {idx, idx};
        while(start - 1 >= 0 && end + 1 <= (n-1) && s[start-1] == s[end+1]){
            start--;
            end++;
        }
        return {start,end};
    }
};
