class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>ds;
        unordered_map<char, int>dt;
        for(int i = 0; i < s.size();i++){
            ds[s[i]]++;
        }
        for(int i = 0; i< t.size();i++){
            dt[t[i]]++;
        }
        return ds == dt;
    }
};
