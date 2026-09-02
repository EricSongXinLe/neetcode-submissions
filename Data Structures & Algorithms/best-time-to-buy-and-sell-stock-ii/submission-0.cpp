class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int noHold = 0;
        int hold = -prices[0];

        for(int i = 0; i < prices.size(); i++){
            noHold = max(noHold, hold + prices[i]);
            hold = max(hold, noHold - prices[i]);
        }
        return noHold;
    }
};