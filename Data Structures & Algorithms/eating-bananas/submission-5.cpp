class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int maxVal = 1;
        for(int p : piles){
            maxVal = max(maxVal, p);
        }
        int hi = maxVal+1;
        while(lo < hi){
            int mid = lo + (hi - lo)/ 2;
            if(canEat(piles, mid, h)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;

    }
    bool canEat(vector<int>& piles, int speed, int limit){
        int time = 0;
        for(int i = 0; i < piles.size(); i++){
            time+= (piles[i] + speed - 1) / speed;
        }
        return time <= limit;
    }
};
