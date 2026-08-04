class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //let P be all positive numbers
        //let N be all negative numbers.
        //P + N = sum(nums); P - N = target.  P = (sum(nums) + target) / 2.
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        int twoP = totalSum + target;
        if(twoP % 2 != 0) return 0;
        int targetP = twoP / 2;
        vector<int>dp(targetP + 1);
        dp[0] = 1;
        for(int num : nums){
            for(int sum = targetP; sum >= num; sum--){
                dp[sum] = dp[sum] + dp[sum - num];
            }
        }
        return dp[targetP];
    }
};
