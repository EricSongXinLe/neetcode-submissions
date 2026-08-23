class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.size();
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(char c : s1){
            freq1[c]++;
        }
        for(int i = 0; i < windowSize; i++){
            freq2[s2[i]]++;
        }
        if(freq1 == freq2) return true;
        int lptr = 0;
        int rptr = windowSize;
        while(rptr < s2.size()){
            freq2[s2[rptr]]++;
            freq2[s2[lptr]]--;
            if(freq2[s2[lptr]] == 0){
                freq2.erase(s2[lptr]);
            }
            rptr++;
            lptr++;
            if(freq1 == freq2)return true;
        }
        return false;
    }
};
