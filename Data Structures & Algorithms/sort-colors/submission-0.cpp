class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>colors(3);
        for(int num : nums){
            if(num == 0){
                colors[0]++;
            }else if(num == 1){
                colors[1]++;
            }else{
                colors[2]++;
            }
        }
        int i =0;
        while(colors[0] > 0){
            nums[i] = 0;
            i++;
            colors[0]--;
        }
        while(colors[1] > 0){
            nums[i] = 1;
            i++;
            colors[1]--;
        }
        while(colors[2] > 0){
            nums[i] = 2;
            i++;
            colors[2]--;
        }
    }
};