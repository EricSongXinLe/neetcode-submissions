class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>q; //max index.
        for(int i = 0; i < nums.size(); i++){
            if(!q.empty() && (i - k) >= q.front()){
                q.pop_front();
            }
            while(!q.empty() && nums[i] > nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(i >= k-1){
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
