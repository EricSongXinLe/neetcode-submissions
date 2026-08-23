class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>freq;
        int lptr = 0;
        int maxFreq = 0;
        int res = 0;
        for(int rptr = 0; rptr < s.size(); rptr++){
            int windowSize = rptr - lptr + 1;
            freq[s[rptr]]++;
            maxFreq = max(maxFreq, freq[s[rptr]]);
            while(windowSize - maxFreq > k){
                freq[s[lptr]]--;
                if(freq[s[lptr]] == 0){
                    freq.erase(s[lptr]);
                }
                lptr++;
                windowSize = rptr - lptr + 1;
            }
            res = max(res, windowSize);
        }
        return res;
    }
};
