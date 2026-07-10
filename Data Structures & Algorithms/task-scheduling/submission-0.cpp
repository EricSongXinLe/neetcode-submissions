class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> dict(26,0);
        priority_queue<pair<int,char>>pq;
        queue<pair<int,pair<int,char>>>waiting;
        for(char& task : tasks){
            dict[task - 'A']++;
        }
        for(int i = 0; i < 26; i++){
            if(dict[i] > 0){
                pq.push({dict[i], i + 'A'});
            }
        }
        int time = 0;
        while(!pq.empty() || !waiting.empty()){
            time++;
            if(!waiting.empty() && waiting.front().first == time){
                auto eligible = waiting.front();
                waiting.pop();
                pq.push({eligible.second.first, eligible.second.second});
            }

            if(!pq.empty()){
                auto exec = pq.top();
                pq.pop();
                if(exec.first - 1 > 0){
                    waiting.push({time + n + 1,{exec.first - 1, exec.second}});
                }
            }
        }
        return time;
    }
};