class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;
        int prev = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(prev != nums[i]){
                nums[write] = nums[i];
                write++;
                prev = nums[i];
            }else{
                continue;
            }
        }
        return write;
    }
};