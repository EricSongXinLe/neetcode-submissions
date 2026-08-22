class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;
        int lptr = 0;
        int maxLen =0;
        for(int i = 0; i < s.size(); i++){
            int curr = s[i];
            while(seen.count(curr)){
                seen.erase(s[lptr]);
                lptr++;
            }
            seen.insert(curr);
            maxLen = max(maxLen, i - lptr+1);
        }
        return maxLen;
    }
};
