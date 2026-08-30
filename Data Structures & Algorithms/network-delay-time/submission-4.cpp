class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1, vector<pair<int,int>>());
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto& t : times){
            int ui = t[0];
            int vi = t[1];
            int ti = t[2];
            adj[ui].push_back({ti,vi});
        }
        pq.push({0, k});
        while(!pq.empty()){
            auto[nodeDist, nodeId] = pq.top();
            pq.pop();

            if(nodeDist > dist[nodeId]) continue; //stale
            
            for(auto& nei : adj[nodeId]){
                int nodeNeiDist = nei.first;
                int neiId = nei.second;
                if(dist[neiId] > nodeDist + nodeNeiDist){
                    dist[neiId] = nodeDist + nodeNeiDist;
                    pq.push({nodeDist + nodeNeiDist, neiId});
                }
            }
        }
        int res = -1; 
        for(int i = 1; i <=n; i++){
            if(dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};
