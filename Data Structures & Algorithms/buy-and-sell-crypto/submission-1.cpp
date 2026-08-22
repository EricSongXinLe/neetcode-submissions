class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int buyPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            int currPrice = prices[i];
            if(currPrice < buyPrice){
                buyPrice = currPrice; //better buy today
            }
            maxProfit = max(maxProfit, currPrice - buyPrice);
        }
        return maxProfit;
    }
};
