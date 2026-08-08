class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN;
        int rest = 0;
        int hold = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            int prevSold = sold;
            int prevRest = rest;
            int prevHold = hold;

            sold = prevHold + prices[i];
            rest = max(prevRest, prevSold);
            hold = max(prevHold, prevRest - prices[i]);
        }
        return max(rest, sold);
    }
};
