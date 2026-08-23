class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>freq;
        int lptr = 0;
        int maxFreq = 0;
        int res = 0;
        for(int rptr = 0; rptr < s.size(); rptr++){
            freq[s[rptr]]++;
            maxFreq = max(maxFreq, freq[s[rptr]]);
            while(rptr - lptr + 1 - maxFreq > k){
                freq[s[lptr]]--;
                if(freq[s[lptr]] == 0){
                    freq.erase(s[lptr]);
                }
                lptr++;
            }
            res = max(res, rptr - lptr + 1);
        }
        return res;
    }
};
