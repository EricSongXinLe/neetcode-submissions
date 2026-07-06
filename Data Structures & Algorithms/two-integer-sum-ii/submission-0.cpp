class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lptr = 0;
        int rptr = numbers.size()-1;
        while(lptr != rptr){
            if(numbers[lptr] + numbers[rptr] == target){
                return {lptr+1, rptr+1};
            } else if (numbers[lptr] + numbers[rptr] < target){
                lptr++;
            } else {
                rptr--;
            }
        }
        return {-1,-1};
    }
};
