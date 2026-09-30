class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        k_ = k;
        q.resize(k_);
        l = 0;
        r = 0;
        empty = true;
        full = false;
    }
    
    bool enQueue(int value) {
        if(full) return false;
        empty = false;
        q[r] = value;
        r = (r + 1) % k_;
        if(r == l){
            full = true;
        }
        return true;
    }
    
    bool deQueue() {
        if(empty) return false;
        full = false;
        l = (l + 1) % k_;
        if (l == r){
            empty = true;
        }
        return true;
    }
    
    int Front() {
        if(empty) return -1;
        return q[l];
    }
    
    int Rear() {
        if(empty) return -1;
        return q[(r - 1 + k_) % k_];
    }
    
    bool isEmpty() {
        return empty;
    }
    
    bool isFull() {
        return full;
    }
private:
    vector<int>q;
    int k_;
    int l;
    int r;
    bool empty;
    bool full;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */