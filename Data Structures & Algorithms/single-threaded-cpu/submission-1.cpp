class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(i); //enqueueTime, length, originalIdx
        }
        auto sortedTasks = tasks;
        sort(sortedTasks.begin(), sortedTasks.end());
        vector<int>res;
        int time = sortedTasks[0][0];
        int j = 0;
        while(true){
            if(pq.empty() && j < sortedTasks.size()){
                time = max(time, sortedTasks[j][0]); 
            }
            while(j < sortedTasks.size() && time >= sortedTasks[j][0]){
                int taskLen = sortedTasks[j][1];
                int taskOrigIdx = sortedTasks[j][2];
                pq.push({taskLen, taskOrigIdx});
                j++;
            }
            if(!pq.empty()){
                int taskOrigIdx = pq.top().second;
                pq.pop();
                res.push_back(taskOrigIdx);
                if(res.size() == tasks.size()) return res;
                time = time + tasks[taskOrigIdx][1];
            }
        }
    }
};