class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int maxVal = 1;
        for(int p : piles){
            maxVal = max(maxVal, p);
        }
        int hi = maxVal;
        while(lo <= hi){
            int mid = lo + (hi - lo)/ 2;
            int timeTaken = eatPile(piles, mid);
            if(timeTaken > h){ //too slow!
                lo = mid + 1;
            }else{
                hi = mid -1;
            }
        }
        return lo;

    }
    int eatPile(vector<int>& piles, int speed){
        int time = 0;
        for(int i = 0; i < piles.size(); i++){
            time+= (piles[i] + speed - 1) / speed;
        }
        return time;
    }
};
