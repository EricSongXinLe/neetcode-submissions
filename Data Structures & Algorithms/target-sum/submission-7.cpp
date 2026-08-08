class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //P+N = sum(nums) // P-N = target. //P = (sum + targ) / 2.
        //FIND: how many ways to get target. 
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum+target) % 2 != 0) return 0;
        if(abs(target) > sum) return 0;
        int targP = (sum + target) / 2;
        int n = nums.size();
        vector<int>dp(targP+1);
        dp[0] = 1;
        for(int num : nums){
            for(int j = targP; j >= num; j--){
                dp[j] = dp[j] +dp[j-num];
            }
        }
        return dp[targP];
    }
};
