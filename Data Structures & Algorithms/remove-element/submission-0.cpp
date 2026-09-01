class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int rightBoundary = nums.size() - 1;
        int i = 0;
        while(i <= rightBoundary){
            if(nums[i] == val){
                swap(nums[i], nums[rightBoundary]);
                rightBoundary--;
            }else{
                i++;
            }
        }
        return rightBoundary+1;
    }
};