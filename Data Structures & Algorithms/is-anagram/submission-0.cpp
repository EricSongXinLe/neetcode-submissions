class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>s_cnt;
        unordered_map<char,int>t_cnt;
        for(auto& c: s){
            s_cnt[c]++;
        }
        for(auto& c: t){
            t_cnt[c]++;
        }
        return s_cnt == t_cnt;
    }
};
