class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i1 = nums[0];
        int i2 = nums[nums[0]];
        while(i1 != i2){
            i1 = nums[i1];
            i2 = nums[nums[i2]];
        }//they meet for first time
        i1= 0;
        while(i1 != i2){
            i1 = nums[i1];
            i2 = nums[i2];
        }
        return i1;
    }
};
