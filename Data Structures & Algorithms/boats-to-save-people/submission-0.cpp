class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int r = people.size() - 1;
        int l = 0;
        int boat = 0;
        while(l < r){
            if(people[l] + people[r] <= limit){
                l++;
                r--;
                boat++;
            }else{
                r--;
                boat++;
            }
        }
        if(l == r){
            boat++;
        }
        return boat;
    }
};