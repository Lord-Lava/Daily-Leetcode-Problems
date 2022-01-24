class MinStack {
    stack<int>st;
    stack<int>curr_min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            curr_min.push(val);
        }else{
            curr_min.push(min(curr_min.top(),val));
        }
            
        st.push(val);
    }
    
    void pop() {
        st.pop();
        curr_min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return curr_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */