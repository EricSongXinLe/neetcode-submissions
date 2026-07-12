class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceYet = prices[0];
        int maxProf = 0;
        for(int i = 1; i<prices.size();++i){
            int currPrice = prices[i];
            maxProf = max(maxProf, currPrice - minPriceYet);
            minPriceYet = min(minPriceYet, currPrice);
        }
        return maxProf;
    }
};
