class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        while(l < r){
            int mid = l + (r - l )/ 2;
            if((long long)mid * mid >= x){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if (l*l == x) return l;
        return l - 1;
    }
};