class Solution {
public:
    int getSum(int a, int b) {
        uint32_t xor_res = a^b;
        uint32_t and_res = a&b;
        and_res = and_res << 1;
        if(and_res != 0){
            return getSum(and_res, xor_res);
        }
        return xor_res;
    }
};
