class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size();i++){
            auto[start,end] = expandOdd(s,i);
            if(end - start > res.size()){
                res = s.substr(start, end-start);
            }
        }
        for(int i = 0; i < s.size()-1;i++){
            auto[start,end] = expandEven(s,i);
            if(end - start > res.size()){
                res = s.substr(start, end-start);
            }
        }
        return res;
    }
    pair<int,int>expandOdd(string& s, int c){ //half-open
        int len = s.size();
        int left = c;
        int right = c;
        while((left-1) >= 0 && (right+1) <= (len-1) && s[left-1] == s[right+1]){
            left--;
            right++;
        }
        return {left,right+1};
    }
    pair<int,int>expandEven(string&s, int c){
        int len = s.size();
        int left = c;
        int right = c+1;
        if(right >= len || s[left] != s[right]) return {0,0};
        while((left-1) >= 0 && (right+1) <= (len-1) && s[left-1] == s[right+1]){
            left--;
            right++;
        }
        return {left,right+1};
    }
};
