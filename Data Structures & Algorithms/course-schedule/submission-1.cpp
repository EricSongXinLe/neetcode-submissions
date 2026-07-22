class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //pr: class -> prereq
        vector<vector<int>>pre_cls(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i =0;i<prerequisites.size();i++){
            int c = prerequisites[i][0];
            int p = prerequisites[i][1];
            pre_cls[p].push_back(c);
            indegree[c]++;
        }
        int finished = 0;
        queue<int>canTake;
        for(int i = 0; i<numCourses;i++){
            if(indegree[i] == 0){
                canTake.push(i);
            }
        }
        while(!canTake.empty()){
            int toTake = canTake.front();
            canTake.pop();
            finished++;
            for(int i = 0; i<pre_cls[toTake].size();i++){
                indegree[pre_cls[toTake][i]]--;
                if(indegree[pre_cls[toTake][i]] == 0){
                    canTake.push(pre_cls[toTake][i]);
                }
            }
        }
        if(finished == numCourses) return true;
        return false;
    }
};
