class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n != 1){
            int newNum = 0;
            seen.insert(n);
            while(n != 0){
                int digit = n % 10;
                n /= 10;
                newNum += digit * digit;
            }
            n = newNum;
            if(seen.count(newNum)) return false;
        }
        return true;
    }
};
