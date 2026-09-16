class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int maxArea = 0;
        for(int i = 0; i <= heights.size(); i++){
            int currHeight = (i == heights.size()) ? 0 : heights[i];
            while(!stk.empty() && heights[stk.top()] > currHeight){
                int idx = stk.top();
                stk.pop();
                if(!stk.empty()){
                    maxArea = max(maxArea, (i - 1 - stk.top()) * heights[idx]);
                }else{
                    maxArea = max(maxArea, i * heights[idx]);
                }
            }
            stk.push(i);
        }
        return maxArea;
            
    }
};
