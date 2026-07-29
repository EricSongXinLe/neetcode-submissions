class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size();i++){
            expand(s,i,i,count);
        }
        for(int i = 0; i < s.size()-1;i++){
            expand(s,i,i+1,count);
        }
        return count;
    }
    void expand(string& s, int start, int end, int& count){
        int len = s.size();
        if(start < 0 || end > len-1) return;
        if(s[start] == s[end]){
            count++;
        }else{
            return;
        }
        while((start-1) >= 0 && (end+1) <= len-1 && s[start-1] == s[end+1]){
            start--;
            end++;
            count++;
        }
    }
};
