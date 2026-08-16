/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
        [](Interval& a, Interval& b){
            return a.start < b.start; 
        });
        priority_queue<int, vector<int>, greater<int>>pq; //earliest meeting room end time
        for(auto& inte : intervals){
            if(!pq.empty() && pq.top() <= inte.start){
                pq.pop();
            }
            pq.push(inte.end);
        }
        return pq.size();
    }
};
