class Solution {
public:
unordered_map<string,
            priority_queue<string, vector<string>, greater<string>>>mp;
vector<string>res;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket : tickets){
            string s = ticket[0];
            string e = ticket[1];
            mp[s].push(e);
        }
        dfs("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
    void dfs(string node){
        while(!mp[node].empty()){
            string next = mp[node].top();
            mp[node].pop();
            dfs(next);
        }
        res.push_back(node);
    }
};
