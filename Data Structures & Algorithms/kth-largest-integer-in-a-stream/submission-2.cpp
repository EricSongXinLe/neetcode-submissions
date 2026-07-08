class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int& num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(pq.size() < k){ //less than k elements
            pq.push(val);
            return pq.top();
        }else{
            int kth_lar = pq.top();
            if(val <= kth_lar){
                return kth_lar;
            }else{
                pq.pop();
                pq.push(val); //val is greater than 
                return pq.top();
            }
        }
    }
private:
    priority_queue<int, vector<int>, greater<int>>pq;
    int k;
};

