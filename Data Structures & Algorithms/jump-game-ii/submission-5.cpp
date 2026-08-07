class Solution {
public:
    int jump(vector<int>& nums) {
        int farthestNext = 0;
        int jumps = 0;
        int currRange = 0;
        for(int i = 0; i < nums.size()-1; i++){
            farthestNext = max(farthestNext, i + nums[i]);
            if(i == currRange){
                jumps++;
                currRange = farthestNext;
            }
        }
        return jumps;
    }
};
