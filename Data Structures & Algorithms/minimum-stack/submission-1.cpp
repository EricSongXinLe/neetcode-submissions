class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        if(minData.empty()){
            minData.push(val);
        }else{
            minData.push(min(minData.top(), val));
        }
    }
    
    void pop() {
        data.pop();
        minData.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minData.top();
    }
private:
    stack<int>data;
    stack<int>minData;
};
