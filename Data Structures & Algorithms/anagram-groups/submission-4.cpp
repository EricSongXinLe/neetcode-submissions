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
        for(auto& [key, value] : mp){
            res.push_back(value);
        }
        return res;
    }
};
