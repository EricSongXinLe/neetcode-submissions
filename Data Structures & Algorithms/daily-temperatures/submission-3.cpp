class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>stk;
        vector<int>res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                int prev = stk.top();
                stk.pop();
                res[prev] = i - prev;
            }
            stk.push(i);
        }        
        return res;
    }
};
