class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string& s : strs){
            vector<char>count(26);
            for(char c : s){
                count[c - 'a']++;
            }
            string fq;
            for(int i =0;i < 26;i++){
                fq = fq + to_string(count[i]) + '#';
            }
            mp[fq].push_back(s);
        }
        vector<vector<string>>res;
        auto it = mp.begin();
        while(it != mp.end()){
            res.push_back({});
            for(string& s: it->second){
                res[res.size() - 1].push_back(s);
            }
            it++;
        }
        return res;
    }
};
