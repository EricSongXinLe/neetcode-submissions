class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int r1 = robRange(nums, 0, n - 1);
        int r2 = robRange(nums, 1, n);
        return max(r1,r2);
    }
    int robRange(vector<int>&nums, int start, int end){
        if(start == end - 1){return nums[start];}
        
        int prev2 = 0;
        int prev1 = 0;
        for(int i = start; i < end; i++){
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
