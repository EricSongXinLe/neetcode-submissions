class Solution {
public:
vector<int>parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i< n+1;i++){
            parent.push_back(i);
        }
        for(auto edge : edges){
            int pa = find(edge[0]);
            int pb = find(edge[1]);
            if(pa == pb){
                //cycle
                return {edge[0],edge[1]};
            }
            parent[pa] = pb;
        }
        return {-1,-1};
    }
    int find(int x){
        if(parent[x] != x){
            return find(parent[x]);
        }
        return x;
    }

};
