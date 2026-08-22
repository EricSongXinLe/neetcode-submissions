class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int r = n - 1;
        int l = 0;
        while(l < r){
            while(r > l && !(isalnum(s[r]))){
                r--;
            }
            while(l < r && !(isalnum(s[l]))){
                l++;
            }
            if(tolower(s[r]) != tolower(s[l])){
                return false;
            }
            r--;
            l++;
        }
        return true;
    }
};
