class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int intendedSum = 0;
        int actualSum = 0;
        for(int i = 0; i <= nums.size(); i++){
            intendedSum += i;
        }
        for(int num : nums){
            actualSum += num;
        }
        return intendedSum - actualSum;
    }
};
