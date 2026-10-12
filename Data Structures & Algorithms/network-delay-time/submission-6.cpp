class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>dist(n+1, INT_MAX);
        for(auto& edge : times){
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            adj[u].push_back({t,v});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //time, idx
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto[currDist, currNode] = pq.top();
            pq.pop();
            if(dist[currNode] < currDist) continue;
            //dist[currNode] = min(dist[currNode], currDist);
            for(auto& nei : adj[currNode]){
                int neiDist = nei.first;
                int neiId = nei.second;
                if(dist[neiId] > neiDist + currDist){
                    dist[neiId] = neiDist+currDist;
                    pq.push({neiDist + currDist, neiId});
                }
            }
        }
        int res = -1;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};
