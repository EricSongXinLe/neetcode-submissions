class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //pq: class -> prereq
        vector<vector<int>>nextClass(numCourses);
        vector<int>inDegrees(numCourses,0);
        vector<int>res;
        for(int i = 0; i < prerequisites.size();i++){
            int c = prerequisites[i][0];
            int p = prerequisites[i][1];
            nextClass[p].push_back(c);
            inDegrees[c]++;
        }
        queue<int>canTake;
        for(int i = 0; i< numCourses;i++){
            if(inDegrees[i] == 0){
                canTake.push(i);
            }
        }
        while(!canTake.empty()){
            int toTake = canTake.front();
            canTake.pop();
            res.push_back(toTake);
            for(int c : nextClass[toTake]){
                inDegrees[c]--;
                if(inDegrees[c] == 0){
                    canTake.push(c);
                }
            }
        }
        if(res.size() == numCourses) return res;
        return {};
    }
};
