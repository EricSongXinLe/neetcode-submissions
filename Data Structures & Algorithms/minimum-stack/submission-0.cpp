class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(mins.empty()){
            mins.push(val);
        }
        else{
            mins.push(min(val, mins.top()));
        }
        elems.push(val);
    }
    
    void pop() {
        elems.pop();
        mins.pop();
    }
    
    int top() {
        return elems.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int>elems;
    stack<int>mins;
};
