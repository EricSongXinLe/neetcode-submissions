class Solution {
public:
        string longestPalindrome(string s) {
        int len = s.size();
        string maxStr;
        //odd length
        for(int i =0;i<len;i++){
            string curr = expandOdd(s, i);
            if(curr.size() > maxStr.size()){
                maxStr = curr;
            }
        }
        for(int i = 1;i<len;i++){
            string curr = expandEven(s,i);
            if(curr.size() > maxStr.size()){
                maxStr = curr;
            }
        }
        return maxStr;
    }
    string expandOdd(const string& s, int ct_idx){
        int len = s.size();
        int lptr = ct_idx;
        int rptr = ct_idx;
        while((lptr-1) >= 0 && (rptr+1) <= (len - 1) && s[lptr-1] == s[rptr+1]){
            lptr--;
            rptr++;
        }
        return s.substr(lptr, rptr-lptr+1);
    }
    string expandEven(const string& s, int ct_pos){
        int len = s.size();
        int lptr = ct_pos-1;
        int rptr = ct_pos;
        if(lptr < 0 || rptr > (len-1) || s[lptr] != s[rptr]){
            return "";
        }
        while((lptr-1) >= 0 && (rptr+1) <= (len - 1) && s[lptr-1] == s[rptr+1]){
            lptr--;
            rptr++;
        }
        return s.substr(lptr, rptr-lptr+1);
    }
};
