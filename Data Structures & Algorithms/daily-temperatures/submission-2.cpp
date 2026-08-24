class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>stk;
        vector<int>res(n);
        for(int i = 0; i<n; i++){
            int today = temperatures[i];
            while(!stk.empty() && temperatures[stk.top()] < today){
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
