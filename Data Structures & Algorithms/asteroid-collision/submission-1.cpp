class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>stk;
        for(int i = 0; i < asteroids.size(); i++){
            bool alive = true;
            int a = asteroids[i];
            while(alive && a < 0 && !stk.empty() && stk.back() > 0){
                if(stk.back() > -a){
                    alive = false;
                }else if(stk.back() == -a){
                    alive = false;
                    stk.pop_back();
                }else{ //stak.back() < -a
                    stk.pop_back();
                }
            }
            if(alive){
                stk.push_back(a);
            }
        }
        return stk;
    }
};