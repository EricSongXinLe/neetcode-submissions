class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>stk;
        for(int i = 0; i < asteroids.size(); i++){
            bool alive = true;
            while(!stk.empty() && asteroids[i] < 0 && 
            stk.back() > 0 && stk.back() < abs(asteroids[i])){
                stk.pop_back();
            }
            if(!stk.empty() && asteroids[i] < 0 && 
            stk.back() > 0 && abs(asteroids[i]) == stk.back()){
                alive = false;
                stk.pop_back();
            }else if(!stk.empty() && asteroids[i] < 0 && 
            stk.back() > 0 && abs(asteroids[i]) < stk.back()){
                alive = false;
            }
            if(alive){
                stk.push_back(asteroids[i]);
            }
        }
        return stk;
    }
};