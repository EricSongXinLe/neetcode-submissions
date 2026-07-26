class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<bool>vis(n,false);
        //
        for(auto edge : edges){
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        //
        if(!dfs(graph,vis,-1,0)){
            return false;
        } //have cycle
        for(bool v : vis){
            if(!v) return v;
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int parent, int node){
        if(vis[node]) return false;
        vis[node] = true;
        for(auto neighbor : graph[node]){
            if(neighbor == parent) continue;
            if(!dfs(graph,vis,node, neighbor)){
                return false;
            }
        }
        return true;
    }
};
