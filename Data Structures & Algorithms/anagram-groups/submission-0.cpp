class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(string& s : strs){
            vector<int>cnt(26,0);
            for(char& c: s){
                cnt[c - 'a']++;
            }
            string dist;
            for(int i =0; i<26; i++){
                dist += to_string(cnt[i]) + '#';
            }
            mp[dist].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(mp.size());
        auto it = mp.begin();
        while(it != mp.end()){
            res.push_back((*it).second);
            it++;
        }
        return res;
    }
};