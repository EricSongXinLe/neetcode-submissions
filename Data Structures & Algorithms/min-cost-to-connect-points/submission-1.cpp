class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //{cost to connect to tree, point id}
        vector<bool>vis(n,false);
        int connected = 0;
        int totalCost = 0;
        pq.push({0,0});
        while(connected < n){
            auto[cost, id] = pq.top();
            pq.pop();

            if(vis[id])continue;
            vis[id] = true;
            connected++;
            totalCost += cost;
            for(int next = 0; next < n; next++){
                if(vis[next])continue; //already conected to graph
                int newCost = abs(points[id][0] - points[next][0])+
                                abs(points[id][1] - points[next][1]);
                pq.push({newCost, next});
            }
        }
        return totalCost;
    }
};
