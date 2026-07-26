class Solution {
public:
vector<int>parent;
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            parent.push_back(i);
        }
        int count = n;
        for(auto edge :edges){
            int a = edge[0];
            int b = edge[1];
            int pa = find(a);
            int pb = find(b);
            if(pa != pb)count--;
            parent[pa] = pb;
        }
        return count;
    }
    int find(int n){
        if(parent[n] != n){
            return find(parent[n]);
        }
        return parent[n];
    }
};
