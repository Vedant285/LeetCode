class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(val < mini) {
            long long x = (2LL * val) - mini;
            st.push(x);
            mini = val;
        }
        else {
            st.push(val);
        }
    }
    
    void pop() {
        long long a = st.top();
        st.pop();
        if (a < mini) {
            mini = (2LL * mini) - a;
        }
    }
    
    int top() {
        long long k = st.top();
        if(k < mini) return mini;
        return k;
    }
    
    int getMin() {
        return mini;
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