class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>freq;
        string res;
        for(char c : s){
            freq[c]++;
        }
        priority_queue<pair<int,char>>pq; // max Heap
        for(auto& [c, f] : freq){
            pq.push({f,c});
        }
        while(pq.size() >= 2){
            char c1 = pq.top().second;
            int f1 = pq.top().first;
            pq.pop();
            res += c1;
            char c2 = pq.top().second;
            int f2 = pq.top().first;
            pq.pop();
            res += c2;
            if(f1-1 > 0){
                pq.push({f1-1,c1});
            }
            if(f2-1 > 0){
                pq.push({f2-1,c2});
            }
        }
        if(pq.size() == 1){
            int f = pq.top().first;
            if(f > 1) return "";
            res += pq.top().second;
        }
        return res;
    }
};