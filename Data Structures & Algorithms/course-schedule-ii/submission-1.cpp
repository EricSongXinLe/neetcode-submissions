class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>prereq_crs; //prereq -> unlocked courses
        vector<int>inDegrees(numCourses,0);
        for(auto prereq : prerequisites){
            //class -> prereq
            int c = prereq[0];
            int p = prereq[1];
            prereq_crs[p].push_back(c);
            inDegrees[c]++;
        }
        queue<int>canTake;
        vector<int>res;
        for(int i = 0; i < numCourses; i++){
            if(inDegrees[i] == 0){
                canTake.push(i);
            }
        }
        while(!canTake.empty()){
            int toTake = canTake.front();
            canTake.pop();
            res.push_back(toTake);
            for(int unlock : prereq_crs[toTake]){
                inDegrees[unlock]--;
                if(inDegrees[unlock] == 0){
                    canTake.push(unlock);
                }
            }
        }
        if(res.size() == numCourses) return res;
        return {};
    }
};
