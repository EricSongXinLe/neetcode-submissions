class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        for(int i = 0; i < position.size();i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());
        double fleetTime = -1.0;
        int fleetSize = 0;
        for(int i = 0; i < cars.size();i++){
            double currentTime = static_cast<double>(target - cars[i].first) / cars[i].second;
            if(fleetTime < currentTime){
                fleetSize++;
                fleetTime = currentTime;
            }
        }
        return fleetSize;
    }
};
