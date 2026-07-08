class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size() <= k){return points;} //they are all close.
        vector<vector<int>> res;
        for(auto& point: points){
            if(pq.size() < k){
                pq.push(point);
            }else{
                if(dist(point) < dist(pq.top())){
                    //closer point
                    pq.pop();
                    pq.push(point);
                }
            }
        }
        int popCnt = 0;
        while(popCnt < k){
            res.push_back(pq.top());
            pq.pop();
            popCnt++;
        }
        return res;
    }
    double dist(const vector<int>& point){
        int x = point[0];
        int y = point[1];
        return sqrt(x*x + y*y);
    }
    
private:
struct Compare{
    bool operator()(vector<int>& p1, vector<int>& p2){
        return dist(p1) < dist(p2);
    }
    double dist(const vector<int>& point){
        int x = point[0];
        int y = point[1];
        return sqrt(x*x + y*y);
    }
};
    priority_queue<vector<int>, vector<vector<int>>, Compare>pq;
};

