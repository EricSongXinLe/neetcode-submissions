class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x+1;
        while(l < r){
            long long mid = l + (r - l )/ 2;
            if((long long)mid * mid > x){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l - 1;
    }
};