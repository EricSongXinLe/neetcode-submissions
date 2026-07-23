class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(int i = 0; i < edges.size();i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        int components = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                components++;
                dfs(adj,vis,-1,i);
            }
        }
        return components;
    }
    void dfs(vector<vector<int>>&adj, vector<bool>&vis, int parent, int node){
        if(vis[node]) return;
        vis[node] = true;
        for(int neighbor : adj[node]){
            if(parent == neighbor) continue;
            dfs(adj,vis,node,neighbor);
        }
    }
};
