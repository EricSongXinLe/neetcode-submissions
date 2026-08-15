class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int res = 0;
        while(count < 32){
            count++;
            if(n & 1){
                res++;
            }
            n = n >> 1;
        }
        return res;
    }
};
