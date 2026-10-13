class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //vector<int>prefix(n,1);
        //vector<int>suffix(n,1);
        vector<int>res(n,1);
        
        for(int i = 1; i < n; i++){
            res[i] = res[i-1] * nums[i-1];
        }
        int rightProduct = 1;
        for(int j = n-1; j >= 0; j--){
            res[j] *= rightProduct;
            rightProduct *= nums[j];
        }
        
        return res;
    }
};
