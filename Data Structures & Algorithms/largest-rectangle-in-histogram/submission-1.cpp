class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>stk;
        int maxArea = 0;
        for(int i = 0; i <= heights.size();i++){
            int currHeight = (i == heights.size()) ? 0 : heights[i];
            int start = i;
            while(!stk.empty() && stk.top().second > currHeight){
                auto[index, height] = stk.top();
                stk.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            stk.push({start, currHeight});
        }
        return maxArea;
    }
};
