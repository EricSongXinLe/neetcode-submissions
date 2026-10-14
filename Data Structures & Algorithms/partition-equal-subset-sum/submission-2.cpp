class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        //can we select some elements fro nums, to make target?
        vector<bool>dp(target+1, false);
        dp[0] = true;
        int j = target;
        for(int num : nums){
            j = target;
            while(j >= num){
                if(dp[j-num] == true){
                    dp[j] = true;
                }
                j--;
            }
        }
        return dp[target];
    }
};
