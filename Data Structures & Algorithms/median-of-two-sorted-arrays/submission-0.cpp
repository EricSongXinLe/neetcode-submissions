class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = m;
        //how many elems does left side of nums1 have?
        
        int totalLeft = (m+n+1)/2;
        while(l <= r){
            int s1l = l + (r - l)/2; //# elems in s1l
            int s2l = totalLeft - s1l; // #elems in s2l
            
            int s1lMax = (s1l == 0) ? INT_MIN : nums1[s1l-1];
            int s2lMax = (s2l == 0) ? INT_MIN : nums2[s2l-1];
            int s1rMin = (s1l == m) ? INT_MAX : nums1[s1l];
            int s2rMin = (s2l == n) ? INT_MAX : nums2[s2l];

            if(s1lMax <= s2rMin && s2lMax <= s1rMin){
                if((m+n) % 2 == 1){
                    return max(s1lMax, s2lMax);
                }else{
                    return (max(s1lMax, s2lMax) + min(s1rMin, s2rMin)) / 2.0;
                }
            }else if(s1lMax > s2rMin){ //too much on s1L! 
                r = s1l-1;
            }else{
                l = s1l+1;
            }
        }
        return INT_MIN;
    }
};
