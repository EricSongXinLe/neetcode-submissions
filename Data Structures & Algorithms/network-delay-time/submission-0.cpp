class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            graph[u].push_back({t,v});
        }
        vector<int>dist(n+1, INT_MAX);
        dist[k]= 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
        //dist -> node
        minHeap.push({0,k});
        while(!minHeap.empty()){
            auto [currDist, node] = minHeap.top();
            minHeap.pop();
            if(currDist > dist[node]) continue;
            for(auto [toNeighborDist, neighbor] : graph[node]){
                if(toNeighborDist + currDist < dist[neighbor]){
                    dist[neighbor] = toNeighborDist + currDist;
                    minHeap.push({toNeighborDist + currDist, neighbor});
                }
            }
        }
        int res = 0;
        for(int i = 1; i< dist.size();i++){
            if(dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};
