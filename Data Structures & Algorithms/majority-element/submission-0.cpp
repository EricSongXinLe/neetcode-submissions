class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num : nums){
            freq[num]++;
        }
        int n = nums.size();
        for(auto& [num, f] : freq){
            if(f > n / 2){
                return num;
            }
        }
        return INT_MIN;
    }
};