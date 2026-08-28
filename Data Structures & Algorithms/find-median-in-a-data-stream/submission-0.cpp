class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxH.empty() && minH.empty()){
            minH.push(num);
        }else if(num > minH.top()){
            minH.push(num);
        }else{
            maxH.push(num);
        }
        if(minH.size() > maxH.size() + 1){
            maxH.push(minH.top());
            minH.pop();
        }else if(maxH.size() > minH.size() + 1){
            minH.push(maxH.top());
            maxH.pop();
        }
    }
    
    double findMedian() {
        if(maxH.empty()){
            return minH.top();
        }
        if(maxH.size() == minH.size()){
            return static_cast<double>((maxH.top() + minH.top()) / 2.0);
        }else if (maxH.size() > minH.size()){
            return maxH.top();
        }else{
            return minH.top();
        }
    }
private:
    priority_queue<int>maxH; //leftHalf.
    priority_queue<int, vector<int>, greater<int>>minH; //Right Half
};
