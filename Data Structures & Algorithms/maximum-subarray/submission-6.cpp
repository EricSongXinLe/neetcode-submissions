class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int res = nums[0];
        for(int num : nums){
            currSum += num;
            res = max(res, currSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return res;
    }
};
