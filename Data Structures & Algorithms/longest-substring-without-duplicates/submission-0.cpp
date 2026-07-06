class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int maxLen = 0;
        int lptr = 0;
        for(int rptr = 0; rptr < s.size(); rptr++){
            char curr = s[rptr];
            while(seen.count(curr)){
                seen.erase(s[lptr]);
                lptr++;
            }
            seen.insert(curr);
            maxLen = max(maxLen, rptr - lptr + 1);
        }
        return maxLen;
    }
};
