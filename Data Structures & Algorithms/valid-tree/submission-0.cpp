class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool>vis(n,false);
        for(int i = 0; i < edges.size();i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        if(!dfs(0,-1,adj,vis)) return false; // cycle
        for(bool b : vis){
            if(!b) return false;
        }
        return true;
    }
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis){
        if(vis[node]) return false;
        vis[node] = true;
        for(int neighbor : adj[node]){
            if(neighbor == parent) continue;
            if(vis[neighbor]) return false;
            if(!dfs(neighbor, node, adj, vis)){
                return false;
            }
        }
        return true;
    }
};
