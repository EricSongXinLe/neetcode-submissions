class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int lptr = 0;
        int longest = 0;
        for(int rptr = 0; rptr < s.size(); rptr++){
            freq[s[rptr] - 'A']++;
            while(true){
                int maxCount = 0;
                for(int count : freq){
                    maxCount = max(maxCount, count);
                }
                int windowSize = rptr - lptr +1;
                if(windowSize - maxCount <= k){break;}
                freq[s[lptr]-'A']--;
                lptr++;
            }
            longest = max(longest, rptr - lptr +1);
        }
        return longest;
    }
};
