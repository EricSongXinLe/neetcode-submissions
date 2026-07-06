class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()){return false;}
        vector<int>freq_s1(26,0);
        vector<int>freq_window(26,0);
        int windowSize = s1.size();
        for(int i =0;i<windowSize;++i){
            freq_s1[s1[i] - 'a']++;
            freq_window[s2[i] - 'a']++;
        }
        if(freq_s1 == freq_window){return true;}
        int lptr = 0;
        int rptr = windowSize - 1;
        while(rptr < (s2.size()-1)){
            rptr++;
            freq_window[s2[rptr] - 'a']++;
            freq_window[s2[lptr] - 'a']--;
            lptr++;
            if(freq_s1 == freq_window){return true;}
        }
        return false;
    }
};
