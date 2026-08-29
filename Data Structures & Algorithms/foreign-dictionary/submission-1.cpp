class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>>adj;
        unordered_map<char, int>indegrees;

        for(string& s : words){
            for(char c : s){
                indegrees[c] = 0; //add a node.
            }
        }

        for(int i = 0; i < words.size() - 1; i++){
            string& s1 = words[i];
            string& s2 = words[i+1];

            int len = min(s1.size(), s2.size());
            bool foundDiff = false;
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){ //first diff
                    foundDiff = true;
                    adj[s1[j]].push_back(s2[j]);
                    indegrees[s2[j]]++;
                    break;
                }
            }
            if(foundDiff == false && s1.size() > s2.size()){
                return "";
            }
        }
        queue<char>toProcess;
        string res;
        for(auto& [c, i] : indegrees){
            if(i == 0) toProcess.push(c);
        }
        while(!toProcess.empty()){
            char curr = toProcess.front();
            toProcess.pop();
            res+=curr;
            for(char nei : adj[curr]){
                indegrees[nei]--;
                if(indegrees[nei] == 0){
                    toProcess.push(nei);
                }
            }
        }
        if(res.size() < indegrees.size()) return "";
        return res;
    }
};
