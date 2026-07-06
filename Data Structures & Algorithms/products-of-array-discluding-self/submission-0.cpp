class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix;
        vector<int>suffix;
        int len = nums.size();
        prefix.resize(len);
        suffix.resize(len);
        prefix[0] = nums[0];
        suffix[len-1]= nums[len-1];
        for(int i =1;i<len;++i){
            prefix[i] = prefix[i-1] * nums[i];
        }
        for(int i =len-2;i>=0;--i){
            suffix[i] = suffix[i+1] * nums[i];
        }
        vector<int> ans;
        ans.resize(len);
        ans[0] = suffix[1];
        for(int i =1;i<len-1;++i){
            ans[i] = prefix[i-1] * suffix[i+1];
        }
        ans[len-1] = prefix[len-2];
        return ans;
    }
};
