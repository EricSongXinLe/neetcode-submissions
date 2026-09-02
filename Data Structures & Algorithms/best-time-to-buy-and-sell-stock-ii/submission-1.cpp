class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int noHold = 0;
        int hold = -prices[0];

        for(int i = 1; i < prices.size(); i++){
            int prevNoHold = noHold;
            int prevHold = hold;
            noHold = max(prevNoHold, prevHold + prices[i]);
            hold = max(prevHold, prevNoHold - prices[i]);
        }
        return noHold;
    }
};