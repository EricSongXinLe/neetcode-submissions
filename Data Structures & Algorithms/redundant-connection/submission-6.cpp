class Solution {
public:
vector<int>parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i<=n;i++){
            parent.push_back(i);
        }
        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            int pa = find(a);
            int pb = find(b);

            if(pa == pb){
                return {a,b};
            }
            parent[pa] = pb;
        }
        return {-1,-1};
    }
    int find(int a){
        if(parent[a] == a){
            return a;
        }
        return find(parent[a]);
    }
};
