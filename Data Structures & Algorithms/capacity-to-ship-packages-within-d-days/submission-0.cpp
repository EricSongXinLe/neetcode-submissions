class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sumW = 0;
        int maxW = 0;
        for(int w : weights){
            maxW = max(maxW, w);
            sumW += w;
        }
        long long l = maxW;
        long long r = sumW;
        while(l < r){
            long long mid = l + (r - l) / 2;
            if(canShip(weights, days, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
    bool canShip(const vector<int>& weights, const int daysLim, const int cap){
        int days = 0;
        int i = 0;
        int currWeight = 0;
        while(i < weights.size()){
            while(i < weights.size() && currWeight + weights[i] <= cap){
                currWeight += weights[i];
                i++;
            }
            days++;
            currWeight = 0;
        }
        return days <= daysLim;
    }
};