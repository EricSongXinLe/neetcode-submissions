class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq; //sum -> freq
        int sum = 0;
        int res = 0;
        freq[0] = 1;
        for(int n : nums){
            sum += n;
            int rem = sum - k;
            res += freq[rem];
            freq[sum]++;
        }
        return res;
    }
};