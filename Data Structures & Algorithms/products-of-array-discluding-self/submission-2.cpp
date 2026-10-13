class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        vector<int>res(n);
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int j = n-2; j >= 0; j--){
            suffix[j] = suffix[j+1] * nums[j+1];
        }
        res[0] = suffix[0];
        res[n-1] = prefix[n-1];
        for(int i = 1; i < n-1; i++){
            res[i] = suffix[i]*prefix[i];
        }
        return res;
    }
};
