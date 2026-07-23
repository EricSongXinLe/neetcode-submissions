class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1);
        for(int i = 1; i < n+1;i++){
            parent[i] = i;
        }
        for(auto edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];
            if(!(unite(n1,n2,parent))){
                return {n1,n2};
            }
        }
        return {-1,-1};
    }
    int find(int i, vector<int>&parent){
        if(parent[i] == i){
            return i;
        }else{
            return find(parent[i],parent);
        }
    }
    bool unite(int a, int b, vector<int>& parent){
        int pa = find(a,parent);
        int pb = find(b,parent);
        if(pa == pb){
            return false; // already connected
        }else{
            parent[pa] = pb;
            return true;
        }
    }
};
