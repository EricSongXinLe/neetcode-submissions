class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1, vector<pair<int,int>>()); //adjacency list
        //graph[i]: list of adjacent nodes; {dist, dest};
        vector<int>time(n+1, INT_MAX);
        priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;
        time[k] = 0;
        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            graph[u].push_back({t,v});
        }
        pq.push({0,k});
        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();
            if(time[node] < dist) continue;
            for(auto nei : graph[node]){
                int nei_id = nei.second;
                int nei_dist = nei.first;
                int tentative_dist = dist + nei_dist;
                if(tentative_dist < time[nei_id]){
                    pq.push({tentative_dist, nei_id});
                    time[nei_id] = tentative_dist;
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(time[i] == INT_MAX) return -1;
            res = max(res, time[i]);
        }
        return res;
    }
};
